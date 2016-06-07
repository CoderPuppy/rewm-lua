local clws, tiles = unpack(require './windows')
local x11 = require './x11'
local uv = require 'luv'

return function()
	for _, tile in pairs(tiles.cache) do
		if tile.type == 'clw' then
			x11.reparent(tile.clw.xwin, x11.screen.root)
		end
	end
	x11.flush_buffer()
	x11.sync()
	uv.stop()
end
