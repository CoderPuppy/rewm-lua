local clws, tiles = unpack(require '../windows')
local x11 = require '../x11'
local ffi = require 'ffi'
local Tile = require '../tile'
local ClW = require '../clw'

function tiles.tabbed()
	local tile = {
		type = 'tabbed';
		parents = {};
		children = {};

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
			type = 'tabbed.input_clw';
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

	function tile.add(new)
		new.put_under(tile)

		tile.children[#tile.children + 1] = new

		p('TODO', 'tabbed.add')
	end

	function tile.remove(prev)
		prev.removed_from(tile)
		if tile.parent then
			prev.off()
		end

		if #tile.children == 1 then
			tiles.remove(tile)
			x11.destroy_window(tile.xwin)
			destroy_tile(tile)
		else
			local prev_i
			for i, child in ipairs(tile.children) do
				if child == prev then
					prev_i = i
				end
			end
			if prev_i then
				table.remove(tile.children, prev_i)
			end
			p('TODO', 'tabbed.remove')
		end
	end

	function tile.move(move)
		p('TODO', 'tabbed.move')
	end

	function tile.off()
		x11.unmap(tile.xwin)
		tile.parent = nil
	end

	Tile(tile)

	return tile
end
