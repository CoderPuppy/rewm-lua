local x11 = require './x11'
local clws, tiles = unpack(require './windows')
local ClW = require './clw'

local call_hook = {'call', function(f, args, rets)
	return f, args, table.pack(table.unpack(rets, rets.n), table.pack(f(table.unpack(args, 1, args.n))))
end}
local Tile; Tile = {
	required = {
		put_under = 'function';
		removed_from = 'function';

		add = 'function';

		move = 'function';
		off = 'function';

		map = 'function';
		unmap = 'function';

		activate = 'function';

		focus = 'function';
		unfocus = 'function';
	};

	optional = {
		put_under = function() end;
		removed_from = function() end;

		off = function() end;

		map = function() end;
		unmap = function() end;

		activate = function() end;

		unfocus = function() end;
	};

	hooks = {
		put_under = function(tile, f)
			return function(...)
				local parent = ...
				if tile.parents[parent] then
					return
				end
				tile.parents[parent] = true
				return f(...)
			end;
		end;

		removed_from = function(tile, f)
			return function(...)
				local parent = ...
				if not tile.parents[parent] then
					return
				end
				tile.parents[parent] = nil
				return f(...)
			end;
		end;

		move = function(tile, f)
			return function(...)
				local move = ...

				tile.parent = move.parent
				tile.ancestry = setmetatable({ [tile] = true }, { __index = tile.parent.ancestry })
				tile.x = move.x
				tile.y = move.y
				tile.width = move.width
				tile.height = move.height
				tile.title_pl = move.title_pl

				x11.move(tile.xwin, tile.x, tile.y, tile.width, tile.height)
				
				return f(...)
			end
		end;

		off = function(tile, f)
			return function(...)
				if not tile.parent then
					return
				end
				
				tile.parent = nil
				tile.ancestry = nil
				tile.x = nil
				tile.y = nil
				tile.width = nil
				tile.height = nil
				tile.title_pl = nil

				return f(...)
			end
		end;

		map = function(tile, f)
			return function(...)
				if tile.mapped then
					return
				end
				tile.mapped = true
				x11.map(tile.xwin)
				return f(...)
			end
		end;

		unmap = function(tile, f)
			return function(...)
				if not tile.mapped then
					return
				end
				tile.mapped = false
				x11.unmap(tile.xwin)
				return f(...)
			end
		end;

		activate = function(tile, f)
			return function(...)
				local child = ...

				if not tile.mapped then
					tile.parent.activate(tile)
				end

				-- the tile is mapped and there's no child to be mapped, nothing to do here
				if tile.mapped and not child then
					return
				end

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
