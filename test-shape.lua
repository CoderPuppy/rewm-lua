local ffi = require 'ffi'
local uv = require 'luv'
local pl = require 'pl.import_into' ()

local x11 = require 'x11'

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
local values = ffi.new('int[2]', 0, bit.bor(
	x11.xcb.XCB_EVENT_MASK_EXPOSURE,
	x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY,
	x11.xcb.XCB_EVENT_MASK_BUTTON_RELEASE
))
x11.xcb.xcb_create_window(x11.conn,
	0, -- depth: copy from parent
	win, -- window
	x11.screen.root, -- parent
	0, 0, -- x, y
	100, 100, -- width, height
	0, -- border width
	x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
	x11.screen.root_visual, -- visual
	bit.bor( -- value mask
		x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
		x11.xcb.XCB_CW_EVENT_MASK
	),
	values -- values
)

local width, height = 100, 100

x11.map(win)

local gc = x11.xcb.xcb_generate_id(x11.conn)
local values = ffi.new('int[1]', x11.screen.black_pixel)
x11.xcb.xcb_create_gc(x11.conn, gc, win, x11.xcb.XCB_GC_FOREGROUND, values)

local rects = ffi.new('xcb_rectangle_t[1]')
rects[0].x = 10
rects[0].y = 10
rects[0].width = 50
rects[0].height = 50

local op = x11.xcb.XCB_SHAPE_SO_SET

-- x11.xcb_shape.xcb_shape_rectangles(x11.conn, op, x11.xcb.XCB_SHAPE_SK_INPUT, x11.xcb.XCB_CLIP_ORDERING_UNSORTED, win, 0, 0, 1, rects)
x11.xcb_shape.xcb_shape_rectangles(x11.conn, op, x11.xcb.XCB_SHAPE_SK_CLIP, x11.xcb.XCB_CLIP_ORDERING_UNSORTED, win, 0, 0, 1, rects)
-- x11.xcb_shape.xcb_shape_rectangles(x11.conn, op, x11.xcb.XCB_SHAPE_SK_BOUNDING, x11.xcb.XCB_CLIP_ORDERING_UNSORTED, win, 0, 0, 1, rects)

x11.flush()

x11.handlers.Expose = {'xcb_expose_event_t', function(ev)
	local rects = ffi.new('xcb_rectangle_t[?]', 1)
	rects[0].x = 0
	rects[0].y = 0
	rects[0].width = width
	rects[0].height = height
	x11.xcb.xcb_poly_fill_rectangle(x11.conn, win, gc, 1, rects)
	x11.flush()
end}

x11.handlers.ConfigureNotify = {'xcb_configure_notify_event_t', function(ev)
	width, height = ev.width, ev.height
end}

uv.run()
