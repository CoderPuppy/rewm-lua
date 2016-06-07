local clws, tiles = unpack(require '../windows')
local ClW = require '../clw'
local Tile = require '../tile'
local x11 = require '../x11'
local ffi = require 'ffi'

local function split_resizer(con, con_size)
	local r = {
		ceil = true;
		pos = 0;
	}

	if con.parent then
		setmetatable(r, { __call = function(_, child, move)
			local size = con_size * con.sizes[child]
			if r.ceil and size % 1 ~= 0 then
				size = math.ceil(size)
				r.ceil = false
			else
				size = math.floor(size)
			end
			move(child, r.pos, size)
			r.pos = r.pos + size
		end })
	else
		setmetatable(r, { __call = function() end })
	end

	return r
end

function tiles.hsplit()
	local tile = {
		type = 'hsplit';
		parents = {};
		children = {};
		sizes = {};

		as_clw = {};
	}

	-- Create window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tiles.cache[tile.xwin] = tile
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.xwin, -- window
			x11.screen.root, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor( -- values mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			values -- values
		)
	end

	-- Create input window
	do
		tile.input_clw = {
			type = 'hsplit.input_clw';
		}
		tile.input_clw.xwin = x11.xcb.xcb_generate_id(x11.conn)
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.input_clw.xwin, -- window
			tile.xwin, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor( -- values mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			values -- values
		)
		x11.map(tile.input_clw.xwin)
		ClW(tile.input_clw)
	end

	function tile.focus()
		x11.focus(tile.input_clw.xwin, x11.xcb.XCB_INPUT_FOCUS_NONE)
	end

	local function split_move(child, x, width)
		if child.parent ~= tile then
			x11.reparent(child.xwin, tile.xwin)
		end
		child.move {
			parent = tile;
			x = x;
			y = 0;
			width = width;
			height = tile.height;
		}
	end

	function tile.add(new)
		new.put_under(tile)

		local num = #tile.children
		local factor = num / (num + 1)
		
		local r = split_resizer(tile, tile.width)
		for _, child in ipairs(tile.children) do
			tile.sizes[child] = tile.sizes[child] * factor
			r(child, split_move)
		end

		tile.children[#tile.children + 1] = new
		tile.sizes[new] = 1 / (num + 1)
		r(new, split_move)
	end

	function tile.remove(prev)
		prev.removed_from(tile)
		if tile.parent then
			prev.off()
		end

		if #tile.children == 1 then
			tiles.remove(tile)
			x11.destroy_window(tile.xwin)
			tiles.cache[tile.xwin] = nil
		else
			local amt = tile.sizes[prev] / (#tile.children - 1)
			local r = split_resizer(tile, tile.width)
			local prev_i
			for i, child in ipairs(tile.children) do
				if child == prev then
					prev_i = i
				else
					tile.sizes[child] = tile.sizes[child] + amt
					r(child, split_move)
				end
			end
			if prev_i then
				table.remove(tile.children, prev_i)
			end
			tile.sizes[prev] = nil
		end
	end

	function tile.move(move)
		local r = split_resizer(tile, tile.width)
		for _, child in ipairs(tile.children) do
			r(child, split_move)
		end
	end

	function tile.off()
		x11.unmap(tile.xwin)
		tile.parent = nil
	end

	Tile(tile)

	return tile
end

function tiles.vsplit()
	local tile = {
		type = 'vsplit';
		parents = {};
		children = {};
		sizes = {};

		as_clw = {};
	}

	-- Create window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tiles.cache[tile.xwin] = tile
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.xwin, -- window
			x11.screen.root, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor( -- values mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			values -- values
		)
	end

	-- Create input window
	do
		tile.input_clw = {
			type = 'vsplit.input_clw';
		}
		tile.input_clw.xwin = x11.xcb.xcb_generate_id(x11.conn)
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.input_clw.xwin, -- window
			tile.xwin, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor( -- values mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			values -- values
		)
		x11.map(tile.input_clw.xwin)
		ClW(tile.input_clw)
	end

	function tile.focus()
		x11.focus(tile.input_clw.xwin, x11.xcb.XCB_INPUT_FOCUS_NONE)
	end

	local function split_move(child, y, height)
		if child.parent ~= tile then
			x11.reparent(child.xwin, tile.xwin)
		end
		child.move {
			parent = tile;
			x = 0;
			y = y;
			width = tile.width;
			height = height;
		}
	end

	function tile.add(new)
		new.put_under(tile)

		local num = #tile.children
		local factor = num / (num + 1)
		
		local r = split_resizer(tile, tile.height)
		for _, child in ipairs(tile.children) do
			tile.sizes[child] = tile.sizes[child] * factor
			r(child, split_move)
		end

		tile.children[#tile.children + 1] = new
		tile.sizes[new] = 1 / (num + 1)
		r(new, split_move)
	end

	function tile.remove(prev)
		prev.removed_from(tile)
		if tile.parent then
			prev.off()
		end

		if #tile.children == 1 then
			tiles.remove(tile)
			x11.destroy_window(tile.xwin)
			tiles.cache[tile.xwin] = nil
		else
			local amt = tile.sizes[prev] / (#tile.children - 1)
			local r = split_resizer(tile, tile.height)
			local prev_i
			for i, child in ipairs(tile.children) do
				if child == prev then
					prev_i = i
				else
					tile.sizes[child] = tile.sizes[child] + amt
					r(child, split_move)
				end
			end
			if prev_i then
				table.remove(tile.children, prev_i)
			end
			tile.sizes[prev] = nil
		end
	end

	function tile.move(move)
		local r = split_resizer(tile, tile.height)
		for _, child in ipairs(tile.children) do
			r(child, split_move)
		end
	end

	function tile.off()
		x11.unmap(tile.xwin)
		tile.parent = nil
	end

	Tile(tile)

	return tile
end
