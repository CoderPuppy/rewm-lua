local x11 = require './x11'
local xtend = require './xtend'
local ffi = require 'ffi'

local colors = {
	unfocused = {
		border = 0x333333;
		bg = 0x1F1F1F;
		title = 0xC0B18B;
	};

	focused = {
		border = 0x5A3637;
		bg = 0x2F1F1F;
		title = 0xEDEDED;
	};
}
colors = xtend.deep_map(colors, function(path, v)
	return x11.xcb.xcb_alloc_color(x11.conn,
		x11.screen.default_colormap, -- colormap
		bit.band(0xFF, bit.rshift(v, 16)) * 256, -- red
		bit.band(0xFF, bit.rshift(v,  8)) * 256, -- green
		bit.band(0xFF, bit.rshift(v,  0)) * 256  -- blue
	)
end)
local err = ffi.new('xcb_generic_error_t*[1]')
colors = xtend.deep_map(colors, function(path, v)
	local res = x11.xcb.xcb_alloc_color_reply(x11.conn, v, err)
	if res == nil then
		x11.error(err[1])
		return
	end
	return res.pixel
end)

return colors
