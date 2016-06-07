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
			if con.mapped then
				child.map()
			end
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

		as_clw = {
			type = 'hsplit.as_clw';
		};

		title = 'hsplit';
	}

	-- create frame window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tiles.cache[tile.xwin] = tile
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.xwin, -- window
			x11.screen.root, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor(unpack({ 0;
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT;
				x11.xcb.XCB_CW_EVENT_MASK;
			})),
			ffi.new('int32_t[2]',
				1,
				bit.bor(unpack({ 0;
				}))
			)
		)
	end
	local cls = 'rewm:hsplit'
	x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, tile.xwin, x11.A.WM_CLASS, x11.A.STRING, 8, #cls, cls)

	-- Create input window
	do
		tile.input_clw = {
			type = 'hsplit.input_clw';
		}
		tile.input_clw.xwin = x11.xcb.xcb_generate_id(x11.conn)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			tile.input_clw.xwin, -- window
			tile.xwin, -- parent
			0, 0, -- x, y
			1, 1, -- width, height
			0, -- border width
			x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
			x11.screen.root_visual, -- visual
			bit.bor( -- value mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			ffi.new('int32_t[2]', -- values
				1,
				bit.bor(unpack({ 0;
					x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
				}))
			)
		)
		x11.map(tile.input_clw.xwin)
		ClW(tile.input_clw)

		local cls = 'rewm:hsplit.input'
		x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, tile.input_clw.xwin, x11.A.WM_CLASS, x11.A.STRING, 8, #cls, cls)
	end

	function tile.focus()
		for _, child in ipairs(tile.children) do
			child.focus()
		end
		x11.focus(tile.input_clw.xwin)
	end

	function tile.unfocus()
		for _, child in ipairs(tile.children) do
			child.unfocus()
		end
	end

	local function split_move(child, x, width)
		x11.reparent(child.xwin, tile.xwin)
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
		if tile.parent then
			if tile.mapped then
				prev.unmap()
			end
			prev.off()
		end
		prev.removed_from(tile)

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

	function tile.replace(prev, new)
		if tile.parent then
			prev.unmap()
			prev.off()
		end
		prev.removed_from(tile)

		tile.sizes[new] = tile.sizes[prev]
		tile.sizes[prev] = nil

		new.put_under(tile)

		local r = split_resizer(tile, tile.width)
		local prev_i
		for i, child in ipairs(tile.children) do
			if child == prev then
				prev_i = i
				r(new, split_move)
				break
			else
				r(child, split_move)
			end
		end
		tile.children[prev_i] = new
	end

	function tile.move(move)
		local r = split_resizer(tile, tile.width)
		for _, child in ipairs(tile.children) do
			r(child, split_move)
		end
	end

	function tile.map()
		for _, child in ipairs(tile.children) do
			child.map()
		end
	end

	function tile.unmap()
		for _, child in ipairs(tile.children) do
			child.unmap()
		end
	end

	function tile.sibling_to_focus(child)
		local i = tile.children[child]
		return tile.children[i - 1] or tile.children[i + 1]
	end
	
	Tile(tile)

	return tile
end
