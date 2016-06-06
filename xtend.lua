local pl = require 'pl.import_into' ()

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

function xtend.deep_map(t, f, path)
	path = path or {}

	if type(t) ~= 'table' then
		return f(path, t)
	end

	local res = {}
	for k, v in pairs(t) do
		local path_ = pl.tablex.copy(path)
		table.insert(path_, k)
		res[k] = xtend.deep_map(v, f, path_)
	end
	return res
end

return xtend
