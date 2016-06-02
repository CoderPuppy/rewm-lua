local ffi = require 'ffi'
local uv = require 'luv'
local pl = require 'pl.import_into' ()

local x11 = require 'x11'

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

x11.handlers.MapRequest = {'xcb_map_request_event_t', function(ev)
	local geom = x11.get_geometry(ev.window)()

	local frame = x11.xcb.xcb_generate_id(x11.conn)
	x11.xcb.xcb_create_window(x11.conn,
		0, -- depth: copy from parent
		frame, -- window
		x11.screen.root, -- parent
		10, 10, -- x, y,
		geom.width, geom.height, -- width, height
		0, -- border width
		x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
		x11.screen.root_visual, -- visual
		0, -- values mask
		nil -- values
	)
	x11.reparent(ev.window, frame)
	x11.map(frame)
	x11.map(ev.window)

	x11.flush()
end}

uv.run()
