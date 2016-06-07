local x11 = require '../x11'
local ClW = require '../clw'

local ewmh = {
	type = 'ewmh';
}

ewmh.xwin = x11.xcb.xcb_generate_id(x11.conn)
x11.xcb.xcb_create_window(x11.conn,
	0, -- depth: copy from parent
	ewmh.xwin, -- window
	x11.screen.root, -- parent
	0, 0, -- x, y
	1, 1, -- width, height
	0, -- border width
	x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
	x11.screen.root_visual, -- visual
	0, -- values mask
	nil -- values
)

ClW(ewmh)

x11.map(ewmh.xwin)
