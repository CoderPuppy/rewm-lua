local xtend = {}

setmetatable(xtend, { __call = function(_, ...)
	local res = {}

	for i = 1, select('#', ...) do
		for k, v in pairs(select(i, ...)) do
			res[k] = v
		end
	end

	return res
end })

function xtend.deep(...)
	local res

	for i = 1, select('#', ...) do
		local inp = select(i, ...)
		if type(inp) == 'table' then
			if type(res) ~= 'table' then
				res = {}
			end
			for k, v in pairs(inp) do
				res[k] = xtend.deep(res[k], v)
			end
		else
			res = inp
		end
	end

	return res
end

return xtend
