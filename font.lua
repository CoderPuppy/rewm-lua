local x11 = require './x11'

local font
do
	font = x11.xcb.xcb_generate_id(x11.conn)
	-- local name = '-adobe-source code pro-medium-r-normal--12-113-75-75-m-0-iso10646-1'
	-- local name = '-*-*-*-*-*-*-16-*-*-*-*-*-iso10646-1'
	local name = 'fixed'
	x11.xcb.xcb_open_font(x11.conn, font, #name, name)
end

return font
