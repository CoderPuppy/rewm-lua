local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x11 = require 'x11'
local clws, windows = table.unpack(require 'windows')

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
		local xwin = children[i - 1]
		local clw = clws(xwin, clws.auto)
		if clw.type == 'tiled' then
			windows.add(clw.win)
		end
	end
	x11.flush()
end

x11.handlers.error = {'xcb_generic_error_t', function(ev)
	io.stderr:write(string.format(
		'X error: request=%s error=%s\n',
		ffi.string(x11.xcb_util.xcb_event_get_request_label(ev.major_code)),
		ffi.string(x11.xcb_util.xcb_event_get_error_label(ev.error_code))
	))
end}

x11.handlers.MapRequest = {'xcb_map_request_event_t', function(ev)
	local clw = clws(ev.window, clws.auto)
	clw.map_request(ev)
end}

x11.handlers.DestroyNotify = {'xcb_destroy_notify_event_t', function(ev)
	print('destroy notify', ev.window, ev.event)
	local clw = clws(ev.window, clws.dummy)
	clw.destroyed(ev)
end}

x11.handlers.Expose = {'xcb_expose_event_t', function(ev)
	print('expose', ev.window)
	local clw = clws(ev.window, clws.auto)
	print(clw.type)
	clw.expose(ev)
end}

x11.handlers.PropertyNotify = {'xcb_property_notify_event_t', function(ev)
	print('property change', ev.window)
	local clw = clws(ev.window, clws.auto)
	clw.property_change(ev)
end}

uv.run()
