local x11 = require './x11'

local gc = x11.xcb.xcb_generate_id(x11.conn)
x11.xcb.xcb_create_gc(x11.conn, gc, x11.screen.root, 0, nil)

return gc
