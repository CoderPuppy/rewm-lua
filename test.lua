local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x = require 'x'

local conn = x.conn
local xcb = x.xcb
local screen = x.screen
local A = x.A

print(pl.pretty.write(x.randr_outputs()))
print(pl.pretty.write(x.xinerama_screens()))

-- Listen for events on root window
do
	local values = ffi.new('uint32_t[1]', bit.bor(
		xcb.XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
		xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
	))
	local req = xcb.xcb_change_window_attributes_checked(conn, screen.root, xcb.XCB_CW_EVENT_MASK, values)
	local e = xcb.xcb_request_check(conn, req)
	if e ~= nil then
		error('there\'s already a window manager')
	end
end

local windows
do
	windows = {
		cache = {};
	}

	local function Window(win)
		if win[Window] then return end
		win[Window] = true

		windows.cache[win.xwin] = win

		win.x = 0
		win.y = 0
		win.width = 1
		win.height = 1

		function win.update_geom(x, y, width, height)
			local values = ffi.new('int32_t[4]',
				ffi.cast('int32_t', x),
				ffi.cast('int32_t', y),
				ffi.cast('uint32_t', width),
				ffi.cast('uint32_t', height)
			)
			xcb.xcb_configure_window(conn, win.xwin, bit.bor(
				xcb.XCB_CONFIG_WINDOW_X,
				xcb.XCB_CONFIG_WINDOW_Y,
				xcb.XCB_CONFIG_WINDOW_WIDTH,
				xcb.XCB_CONFIG_WINDOW_HEIGHT
			), values)
			xcb.xcb_flush(conn)
		end

		function win.map()
			xcb.xcb_map_window(conn, win.xwin)
		end

		function win.unmap()
			xcb.xcb_unmap_window(conn, win.xwin)
		end
	end

	setmetatable(windows, { __call = function(_, xwin, tmp)
		if windows.cache[xwin] then
			print('cached', xwin)
			return windows.cache[xwin]
		elseif tmp then
			local win = {
				xwin = xwin;
				dummy = true;
			}

			function win.map()
				xcb.xcb_map_window(conn, win.xwin)
			end

			function win.unmap()
				xcb.xcb_unmap_window(conn, win.xwin)
			end

			return win
		else
			local win = {
				xwin = xwin;
			}

			Window(win)

			local attrs = xcb.xcb_get_window_attributes_reply(conn, xcb.xcb_get_window_attributes(conn, xwin), nil)
			if attrs.override_redirect == 0 then
				-- Listen for events on the window
				do
					local values = ffi.new('int[1]', bit.bor(
						xcb.XCB_EVENT_MASK_PROPERTY_CHANGE
					))
					xcb.xcb_change_window_attributes(conn, xwin, xcb.XCB_CW_EVENT_MASK, values)
				end
			else
				win.override_redirect = true
			end

			return win
		end
	end })

	local function Container(win, class)
		if win[Container] then error('already a Container') end
		win[Container] = true

		win.xwin = xcb.xcb_generate_id(conn)
		xcb.xcb_create_window(conn,
			0, -- depth = copy from parent
			win.xwin, -- window
			screen.root, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			screen.root_visual, -- visual
			0, -- values mask
			nil -- values
		)

		Window(win)

		do
			local cls = 'rewm-conntainer\0' .. class .. '\0'
			xcb.xcb_change_property(conn, xcb.XCB_PROP_MODE_REPLACE, win.xwin, xcb.XCB_ATOM_WM_CLASS, xcb.XCB_ATOM_STRING, 8, #cls, cls)
		end
		xcb.xcb_change_property(conn, xcb.XCB_PROP_MODE_REPLACE, win.xwin, xcb.XCB_ATOM_WM_NAME, xcb.XCB_ATOM_STRING, 8, #class, class)
		xcb.xcb_change_property(conn, xcb.XCB_PROP_MODE_REPLACE, win.xwin, A._NET_WM_NAME, xcb.XCB_ATOM_STRING, 8, #class, class)
	end

	function windows.floating()
		local win = {}

		Container(win, 'rewm-floating')

		return win
	end

	function windows.hsplit()
		local win = {}

		Container(win, 'rewm-hsplit')

		function win.add(child)
			xcb.xcb_reparent_window(conn, child.xwin, win.xwin, 0, 0)
			child.update_geom(0, 0, win.width, win.height)
		end

		return win
	end
end

do
	local tree = xcb.xcb_query_tree_reply(conn, xcb.xcb_query_tree(conn, screen.root), nil)
	local children = xcb.xcb_query_tree_children(tree)
	local children_len = xcb.xcb_query_tree_children_length(tree)
	for i = 1, children_len do
		local window = children[i - 1]
		windows(window)
	end
	xcb.xcb_flush(conn)
end

local root_geom = xcb.xcb_get_geometry_reply(conn, xcb.xcb_get_geometry(conn, screen.root), nil)

local hsplit = windows.hsplit()
hsplit.update_geom(root_geom.x + 10, root_geom.y + 10, root_geom.width, root_geom.height)
hsplit.map()
xcb.xcb_flush(conn)

local handlers = {
	error = {'xcb_generic_error_t', function(ev)
		io.stderr:write(string.format(
			'X error: request=%s error=%s\n',
			ffi.string(xcb_util.xcb_event_get_request_label(ev.major_code)),
			ffi.string(xcb_util.xcb_event_get_error_label(ev.error_code))
		))
	end};

	MapRequest = {'xcb_map_request_event_t', function(ev)
		local win = windows(ev.window, true)
		if win.dummy then
			win = windows(ev.window)
			hsplit.add(win)
		end
		win.map()
		xcb.xcb_flush(conn)
	end};

	UnmapNotify = {'xcb_unmap_notify_event_t', function(ev)
		windows(ev.window, true).unmap()
		xcb.xcb_flush(conn)
	end};

	ConfigureRequest = {'xcb_configure_request_event_t', function(ev)
		local values = ffi.new('uint32_t[6]')
		local i = 0
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_X) ~= 0 then
			values[i] = ev.x
			i = i + 1
		end
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_Y) ~= 0 then
			values[i] = ev.y
			i = i + 1
		end
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_WIDTH) ~= 0 then
			values[i] = ev.width
			i = i + 1
		end
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_HEIGHT) ~= 0 then
			values[i] = ev.height
			i = i + 1
		end
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_SIBLING) ~= 0 then
			values[i] = ev.sibling
			i = i + 1
		end
		if bit.band(ev.value_mask, xcb.XCB_CONFIG_WINDOW_STACK_MODE) ~= 0 then
			values[i] = ev.stack_mode
			i = i + 1
		end
		xcb.xcb_configure_window(conn, ev.window, ev.value_mask, values)
		xcb.xcb_flush(conn)
	end};

	PropertyNotify = {'xcb_property_notify_event_t', function(ev)
		local win = windows(ev.window)
		-- new value
		if ev.state == 0 then
			if ev.atom == xcb.XCB_ATOM_WM_NAME then
				print('wm name')
			elseif ev.atom == A._NET_WM_NAME then
				print('net wm name')
			end
		end
	end};

	DestroyNotify = {'xcb_destroy_notify_event_t', function(ev)
		local win = windows(ev.window, true)
		windows.cache[win.xwin] = nil
	end};
}

local xcb_poll = uv.new_poll(xcb.xcb_get_file_descriptor(conn))
uv.poll_start(xcb_poll, 'r', function(err, events)
	if err then
		error(err)
	end

	while true do
		local ev = xcb.xcb_wait_for_event(conn)
		if ev == nil then break end

		local typ = ffi.string(xcb_util.xcb_event_get_label(bit.band(ev.response_type, bit.bnot(0x80))))

		print('event', typ)

		repeat
			local handler = handlers[typ]
			if not handler then
				io.stderr:write('unhandled event: ' .. tostring(typ) .. ' (' .. tostring(ev.response_type) .. ')\n')
				break
			end
			handler[2](ffi.cast(handler[1] .. '*', ev))
		until true
	end
end)

uv.run()
