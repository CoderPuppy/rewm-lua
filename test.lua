local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x11 = require 'x11'

local A = x11.A

print(pl.pretty.write(x11.randr_outputs()))
print(pl.pretty.write(x11.xinerama_screens()))

-- Listen for events on root window
do
	local values = ffi.new('uint32_t[1]', bit.bor(
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT,
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
	))
	local req = x11.xcb.xcb_change_window_attributes_checked(x11.conn, x11.screen.root, x11.xcb.XCB_CW_EVENT_MASK, values)
	local e = x11.xcb.xcb_request_check(x11.conn, req)
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
			x11.xcb.xcb_configure_window(x11.conn, win.xwin, bit.bor(
				x11.xcb.XCB_CONFIG_WINDOW_X,
				x11.xcb.XCB_CONFIG_WINDOW_Y,
				x11.xcb.XCB_CONFIG_WINDOW_WIDTH,
				x11.xcb.XCB_CONFIG_WINDOW_HEIGHT
			), values)
			x11.xcb.xcb_flush(x11.conn)
		end

		function win.map()
			x11.xcb.xcb_map_window(x11.conn, win.xwin)
		end

		function win.unmap()
			x11.xcb.xcb_unmap_window(x11.conn, win.xwin)
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
				x11.xcb.xcb_map_window(x11.conn, win.xwin)
			end

			function win.unmap()
				x11.xcb.xcb_unmap_window(x11.conn, win.xwin)
			end

			return win
		else
			local win = {
				xwin = xwin;
			}

			Window(win)

			local attrs = x11.xcb.xcb_get_window_attributes_reply(x11.conn, x11.xcb.xcb_get_window_attributes(x11.conn, xwin), nil)
			if attrs.override_redirect == 0 then
				-- Listen for events on the window
				do
					local values = ffi.new('int[1]', bit.bor(
						x11.xcb.XCB_EVENT_MASK_PROPERTY_CHANGE
					))
					x11.xcb.xcb_change_window_attributes(x11.conn, xwin, x11.xcb.XCB_CW_EVENT_MASK, values)
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

		win.xwin = x11.xcb.xcb_generate_id(x11.conn)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth = copy from parent
			win.xwin, -- window
			x11.screen.root, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			0, -- values mask
			nil -- values
		)

		Window(win)

		do
			local cls = 'rewm-x11.conntainer\0' .. class .. '\0'
			x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, win.xwin, x11.xcb.XCB_ATOM_WM_CLASS, x11.xcb.XCB_ATOM_STRING, 8, #cls, cls)
		end
		x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, win.xwin, x11.xcb.XCB_ATOM_WM_NAME, x11.xcb.XCB_ATOM_STRING, 8, #class, class)
		x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, win.xwin, A._NET_WM_NAME, x11.xcb.XCB_ATOM_STRING, 8, #class, class)
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
			x11.xcb.xcb_reparent_window(x11.conn, child.xwin, win.xwin, 0, 0)
			child.update_geom(0, 0, win.width, win.height)
		end

		return win
	end
end

do
	local tree = x11.xcb.xcb_query_tree_reply(x11.conn, x11.xcb.xcb_query_tree(x11.conn, x11.screen.root), nil)
	local children = x11.xcb.xcb_query_tree_children(tree)
	local children_len = x11.xcb.xcb_query_tree_children_length(tree)
	for i = 1, children_len do
		local window = children[i - 1]
		windows(window)
	end
	x11.xcb.xcb_flush(x11.conn)
end

local root_geom = x11.xcb.xcb_get_geometry_reply(x11.conn, x11.xcb.xcb_get_geometry(x11.conn, x11.screen.root), nil)

local hsplit = windows.hsplit()
hsplit.update_geom(root_geom.x + 10, root_geom.y + 10, root_geom.width, root_geom.height)
hsplit.map()
x11.xcb.xcb_flush(x11.conn)

x11.handlers.error = {'xcb_generic_error_t', function(ev)
	io.stderr:write(string.format(
		'X error: request=%s error=%s\n',
		ffi.string(xcb_util.xcb_event_get_request_label(ev.major_code)),
		ffi.string(xcb_util.xcb_event_get_error_label(ev.error_code))
	))
end}

x11.handlers.MapRequest = {'xcb_map_request_event_t', function(ev)
	local win = windows(ev.window, true)
	if win.dummy then
		win = windows(ev.window)
		hsplit.add(win)
	end
	win.map()
	x11.xcb.xcb_flush(x11.conn)
end}

x11.handlers.UnmapNotify = {'xcb_unmap_notify_event_t', function(ev)
	windows(ev.window, true).unmap()
	x11.xcb.xcb_flush(x11.conn)
end}

x11.handlers.ConfigureRequest = {'xcb_configure_request_event_t', function(ev)
	local values = ffi.new('uint32_t[6]')
	local i = 0
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_X) ~= 0 then
		values[i] = ev.x
		i = i + 1
	end
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_Y) ~= 0 then
		values[i] = ev.y
		i = i + 1
	end
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_WIDTH) ~= 0 then
		values[i] = ev.width
		i = i + 1
	end
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_HEIGHT) ~= 0 then
		values[i] = ev.height
		i = i + 1
	end
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_SIBLING) ~= 0 then
		values[i] = ev.sibling
		i = i + 1
	end
	if bit.band(ev.value_mask, x11.xcb.XCB_CONFIG_WINDOW_STACK_MODE) ~= 0 then
		values[i] = ev.stack_mode
		i = i + 1
	end
	x11.xcb.xcb_configure_window(x11.conn, ev.window, ev.value_mask, values)
	x11.xcb.xcb_flush(x11.conn)
end}

x11.handlers.PropertyNotify = {'xcb_property_notify_event_t', function(ev)
	local win = windows(ev.window)
	-- new value
	if ev.state == 0 then
		if ev.atom == x11.xcb.XCB_ATOM_WM_NAME then
			print('wm name')
		elseif ev.atom == A._NET_WM_NAME then
			print('net wm name')
		end
	end
end}

x11.handlers.DestroyNotify = {'xcb_destroy_notify_event_t', function(ev)
	local win = windows(ev.window, true)
	windows.cache[win.xwin] = nil
end};

uv.run()
