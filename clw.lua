local clws, tiles = unpack(require './windows')

local function ClW(clw)
	if not clw.type then
		error('clw missing type')
	end

	if not clw.xwin then
		error('clw missing xwin')
	end

	for _, name in ipairs({
		'map_request';
		'mapped';
		'unmapped';
		'destroyed';
		'expose';
		'property_change';
		'focus_in';
		'focus_out';
		'button_press';
	}) do
		if clw[name] == nil then
			clw[name] = function(ev) end
		elseif type(clw[name]) ~= 'function' then
			error('bad handler: ' .. tostring(clw.type) .. '.' .. name)
		end
	end

	clws.cache[clw.xwin] = clw

	return clw
end

return ClW
