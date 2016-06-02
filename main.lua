local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x11 = require 'x11'
local windows = require 'windows'

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

do
	local tree = x11.xcb.xcb_query_tree_reply(x11.conn, x11.xcb.xcb_query_tree(x11.conn, x11.screen.root), nil)
	local children = x11.xcb.xcb_query_tree_children(tree)
	local children_len = x11.xcb.xcb_query_tree_children_length(tree)
	for i = 1, children_len do
		local window = children[i - 1]
		print(pl.pretty.write(windows(window, windows.auto)))
	end
	x11.flush()
end

x11.handlers.error = {'xcb_generic_error_t', function(ev)
	io.stderr:write(string.format(
		'X error: request=%s error=%s\n',
		ffi.string(xcb_util.xcb_event_get_request_label(ev.major_code)),
		ffi.string(xcb_util.xcb_event_get_error_label(ev.error_code))
	))
end}

x11.handlers.MapRequest = {'xcb_map_request_event_t', function(ev)
	-- this is known to not be an override redirect window
	-- but I may change windows.auto to make other windows oclw
	-- then I'll have to change this
	local win = windows(ev.window, windows.clw)
	windows.add(win)
	x11.flush()
end}

x11.handlers.MapNotify = {'xcb_map_notify_event_t', function(ev)
	print('map notify', ev.window)
	windows(ev.window, windows.auto)
	x11.flush()
end}

x11.handlers.UnmapNotify = {'xcb_unmap_notify_event_t', function(ev)
	print('unmap notify', ev.window, windows.cache[ev.window])
	local win = windows(ev.window, windows.dummy)
	if win.type == 'clw' and win.clw == ev.window then
		windows.remove(win)
	end
	x11.flush()
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
	x11.flush()
end}

x11.handlers.PropertyNotify = {'xcb_property_notify_event_t', function(ev)
	-- local win = windows(ev.window)
	-- -- new value
	-- if ev.state == 0 then
	-- 	if ev.atom == x11.xcb.XCB_ATOM_WM_NAME then
	-- 		print('wm name')
	-- 	elseif ev.atom == A._NET_WM_NAME then
	-- 		print('net wm name')
	-- 	end
	-- end
end}

x11.handlers.DestroyNotify = {'xcb_destroy_notify_event_t', function(ev)
	print('destroy', ev.window)
	local win = windows.cache[ev.window]
	windows.cache[ev.window] = nil
	if win and win.type ~= 'oclw' then
		windows.remove(win)
		print(ev.window, win.clw, win.xwin)
		if win.type == 'clw' and ev.window == win.clw then
			x11.xcb.xcb_destroy_window(x11.conn, win.xwin)
		end
		x11.flush()

		print('destroy', win.xwin)
		windows.cache[win.xwin] = nil
	end
end};

x11.handlers.ReparentNotify = {'xcb_reparent_notify_event_t', function(ev)
	print('reparent notify', ev.window, ev.parent)
end}

uv.run()
