local ffi = require 'ffi'
local x11 = require './x11'
local gc = require './gc'
local font = require './font'

return function(opts)
	local rects = ffi.new('xcb_rectangle_t[1]')
	x11.change_gc(gc, {
		foreground = opts.colors.bg;
	})
	rects[0].x = opts.x + 1
	rects[0].y = opts.y + 1
	rects[0].width = opts.width - 2
	rects[0].height = opts.height - 2
	x11.xcb.xcb_poly_fill_rectangle(x11.conn, opts.xwin, gc, 1, rects)

	x11.change_gc(gc, {
		foreground = opts.colors.border;
		line_width = 1;
	})
	rects[0].x = opts.x
	rects[0].y = opts.y
	rects[0].width = opts.width - 1
	rects[0].height = opts.height - 1
	x11.xcb.xcb_poly_rectangle(x11.conn, opts.xwin, gc, 1, rects)

	x11.change_gc(gc, {
		font = font;
		foreground = opts.colors.title;
		background = opts.colors.bg;
	})
	x11.xcb.xcb_image_text_8(x11.conn, #opts.title, opts.xwin, gc, opts.x + 5, opts.y + opts.height - 4, opts.title)
end
