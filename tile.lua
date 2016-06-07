local x11 = require './x11'
local clws, tiles = unpack(require './windows')
local ClW = require './clw'

local call_hook = {'call', function(f, args, rets)
	return f, args, table.pack(table.unpack(rets, rets.n), table.pack(f(table.unpack(args, 1, args.n))))
end}
local Tile; Tile = {
	add_parent = function(tile, parent)
		tile.parents[parent] = true
	end;
	remove_parent = function(tile, parent)
		tile.parents[parent] = nil
	end;

	move_map = function(tile, move)
		if not tile.parent then
			-- containers should handle reparenting
			x11.map(tile.xwin)
		end
	end;
	move_update = function(tile, move)
		p('move', tile.xwin, move.parent.xwin, move.x, move.y, move.width, move.height)
		tile.parent = move.parent
		tile.x = move.x
		tile.y = move.y
		tile.width = move.width
		tile.height = move.height
		tile.title_pl = move.title_pl
	end;
	move_xwin = function(tile, move)
		x11.move(tile.xwin, move.x, move.y, move.width, move.height)
	end;

	off_unmap = function(tile)
		x11.unmap(tile.xwin)
	end;
	off_unparent = function(tile)
		tile.parent = nil
	end;

	required = {
		put_under = 'function';
		removed_from = 'function';

		add = 'function';

		move = 'function';
		off = 'function';

		focus = 'function';
		defocus = 'function';
	};

	optional = {
		put_under = function() end;
		removed_from = function() end;
		off = function() end;
		defocus = function() end;
	};

	hooks = {
		put_under = function(tile, f)
			return function(...)
				Tile.add_parent(tile, ...)
				return f(...)
			end;
		end;

		removed_from = function(tile, f)
			return function(...)
				Tile.remove_parent(tile, ...)
				return f(...)
			end;
		end;

		move = function(tile, f)
			return function(...)
				Tile.move_map(tile, ...)
				Tile.move_update(tile, ...)
				Tile.move_xwin(tile, ...)
				return f(...)
			end
		end;

		off = function(tile, f)
			return function(...)
				Tile.off_unmap(tile, ...)
				Tile.off_unparent(tile, ...)
				return f(...)
			end
		end;
	};
}
setmetatable(Tile, { __call = function(_, tile)
	if not tile.type then
		error('tile missing type')
	end

	if not tile.xwin then
		error('tile missing xwin')
	end

	if not tile.as_clw then
		tile.as_clw = {}
	end

	-- TODO: most of these probably don't need ifs
	if not tile.as_clw.type then
		tile.as_clw.type = tile.type .. '.as_clw'
	end

	if not tile.as_clw.xwin then
		tile.as_clw.xwin = tile.xwin
	end

	if not tile.as_clw.tile then
		tile.as_clw.tile = tile
	end

	ClW(tile.as_clw)

	if tile.internal_frame == nil then
		tile.internal_frame = true
	end

	for k, v in pairs(Tile.optional) do
		if not tile[k] then
			tile[k] = v
		end
	end

	local old = setmetatable({}, { __index = tile })
	for k, v in pairs(tile) do
		if type(v) == 'function' and Tile.hooks[k] then
			old[k] = v
			tile[k] = Tile.hooks[k](tile, old[k])
		end
	end

	for name, typ in pairs(Tile.required) do
		if not tile[name] then
			error('missing: ' .. tile.type .. '.' .. name)
		elseif type(tile[name]) ~= typ then
			error('bad type: ' .. tile.type .. '.' .. name .. ': expected ' .. typ .. ' got ' .. type(tile[name]))
		end
	end

	return tile
end })

return Tile
