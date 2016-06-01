local manage = {}

local windows = {
	cache = {};
}
setmetatable(windows, { __call = function(_, xwin, tmp)
	if windows.cache[xwin] then
		return windows.cache[xwin]
	elseif tmp then
		return {}
	else
		local win = {
			xwin = xwin;
		}
		windows.cache[xwin] = win
		
		return win
	end
end })

function handle_map(ev)
	windows(ev.window)
end

function handle_unmap(ev)
	windows(ev.window, true).destroy {
		close = false;
	}
end

return manage
