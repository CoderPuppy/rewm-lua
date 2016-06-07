local pl = require 'pl.import_into' ()
local ffi = require 'ffi'
local uv = require 'luv'

local x11 = require './x11'
local xtend = require './xtend'

local tiles = {
	cache = {};
}

setmetatable(tiles, { __call = function(_, xwin, get)
	if tiles.cache[xwin] then
		return tiles.cache[xwin]
	else
		return get(xwin)
	end
end })

local clws = {
	cache = {};
}

setmetatable(clws, { __call = function(_, xwin, get)
	if clws.cache[xwin] then
		return clws.cache[xwin]
	elseif tiles.cache[xwin] then
		return tiles.cache[xwin].as_clw
	else
		return get(xwin)
	end
end })

-- TODO: tabbed
-- TODO: stacked

function tiles.focus(tile)
	tile.activate()
	local prev = tiles.focused
	tiles.focused = tile
	if prev then
		prev.unfocus()
	end
	tile.focus()
end

function tiles.add(tile)
	p(tiles.focused.type)
	tiles.focused.add(tile, 'down')
	tiles.focus(tile)
end

-- TODO: global replace (maybe?)
function tiles.replace(prev, new)
	-- for parent in pairs(prev.parents) do
	-- 	print(parent.type)
	-- 	parent.replace(prev, new)
	-- end
	local focused = tiles.focused.ancestry[prev]
	if prev.parent then
		prev.parent.replace(prev, new)
	end
	if focused then
		tiles.focus(new)
	end
end

function tiles.remove(tile)
	if tiles.focused.ancestry[tile] then
		tiles.focus(tile.parent.sibling_to_focus(tile) or tile.parent)
	end
	for parent in pairs(tile.parents) do
		parent.remove(tile)
	end
end

return {clws, tiles}
