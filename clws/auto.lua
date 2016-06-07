local clws, tiles = unpack(require '../windows')
local x11 = require '../x11'

require './tile'

function clws.auto(xwin)
	local attrs = x11.get_window_attributes(xwin)()

	if attrs.override_redirect == 0 then
		return clws.tile(xwin)
	else
		return clws.unmanaged(xwin)
	end
end
