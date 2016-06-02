local x11 = require 'x11'
local ffi = require 'ffi'

-- Listen for events on root window
do
	local values = ffi.new('uint32_t[1]', bit.bor(
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
	))
	local req = x11.xcb.xcb_change_window_attributes_checked(x11.conn, x11.screen.root, x11.xcb.XCB_CW_EVENT_MASK, values)
	local e = x11.xcb.xcb_request_check(x11.conn, req)
	if e ~= nil then
		error('there\'s already a window manager')
	end
end

local win = x11.xcb.xcb_generate_id(x11.conn)
local values = ffi.new('int[1]', 0)
x11.xcb.xcb_create_window(x11.conn,
	0, -- depth: copy from parent
	win, -- window
	x11.screen.root, -- parent
	0, 0, -- x, y
	100, 100, -- width, height
	0, -- border width
	x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
	x11.screen.root_visual, -- visual
	x11.xcb.XCB_CW_OVERRIDE_REDIRECT, -- value mask
	values -- values
)

x11.map(win)

local gc = x11.xcb.xcb_generate_id(x11.conn)
local values = ffi.new('int[1]', x11.screen.white_pixel)
x11.xcb.xcb_create_gc(x11.conn, gc, win, x11.xcb.XCB_GC_FOREGROUND, values)

x11.flush()

while true do
	local ev = x11.xcb.xcb_wait_for_event(x11.conn)

	local typ = ffi.string(xcb_util.xcb_event_get_label(bit.band(ev.response_type, bit.bnot(0x80))))

	print('event', typ)

	local rects = ffi.new('xcb_rectangle_t[?]', 1)
	rects[0].x = 0
	rects[0].y = 0
	rects[0].width = 100
	rects[0].height = 100
	x11.xcb.xcb_poly_fill_rectangle(x11.conn, win, gc, 1, rects)
	x11.flush()
end
