local clws, tiles = unpack(require '../windows')
local ClW = require '../clw'

function clws.dummy(xwin)
	local clw = {
		type = 'dummy';
		xwin = xwin;
	}

	ClW(clw)
	clws.cache[clw.xwin] = nil

	return clw
end
