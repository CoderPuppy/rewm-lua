local clws, tiles = unpack(require '../windows')
local x11 = require '../x11'
local ffi = require 'ffi'
local Tile = require '../tile'
local ClW = require '../clw'
local render_title = require '../render-title'
local colors = require '../colors'

function tiles.tabbed()
	local tile = {
		type = 'tabbed';
		parents = {};
		children = { n = 0 };
		title = 'tabbed';

		as_clw = {};
	}

	-- Create window
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
			bit.bor( -- values mask
				x11.xcb.XCB_CW_OVERRIDE_REDIRECT,
				x11.xcb.XCB_CW_EVENT_MASK
			),
			ffi.new('int32_t[2]', -- values
				1,
				bit.bor(unpack({ 0;
					x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
					x11.xcb.XCB_EVENT_MASK_EXPOSURE;
					x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS;
				}))
			)
		)
	end

	local cls = 'rewm:tabbed'
	x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, tile.xwin, x11.A.WM_CLASS, x11.A.STRING, 8, #cls, cls)

	-- Create input window
	do
		tile.input_clw = {
			type = 'tabbed.input_clw';
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
			bit.bor( -- values mask
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

		local cls = 'rewm:tabbed.input'
		x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, tile.input_clw.xwin, x11.A.WM_CLASS, x11.A.STRING, 8, #cls, cls)
	end

	local function activate(child)
		if tile.parent then
			tile.activate(child)
		end
		tile.active = child
	end

	local function title(child)
		return function()
			local i = tile.children[child]
			local width = tile.width / tile.children.n
			local x = (i - 1) * width
			-- TODO: rounding
			-- if width % 1 ~= 0 then
			-- 	if i == 1 then
			-- 		width = math.ceil(width)
			-- 	else
			-- 		x = x + width - width % 1
			-- 		width = math.floor(width)
			-- 	end
			-- end
			render_title {
				xwin = tile.xwin;
				x = x;
				y = 0;
				width = width;
				height = 18;
				title = child.title;
				colors = child.focused and colors.focused or colors.unfocused;
			}
		end
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

	function tile.as_clw.expose(ev)
		if tile.mapped then
			for _, child in ipairs(tile.children) do
				title(child)()
			end
		end
	end

	function tile.as_clw.button_press(ev)
		local width = tile.width / tile.children.n
		if ev.event_y <= 18 then
			tiles.focus(tile.children[math.floor(ev.event_x / width) + 1])
		end
	end

	local function move_child(child)
		x11.reparent(child.xwin, tile.xwin)
		local title_pl = title(child)
		child.move {
			parent = tile;
			x = 0;
			y = 18;
			width = tile.width;
			height = tile.height - 18;
			title_pl = title_pl;
		}
		title_pl()
	end

	function tile.add(new)
		new.put_under(tile)
		
		local i
		if tile.active then
			i = tile.children[tile.active] + 1
		else
			i = tile.children.n + 1
		end

		for j = i, tile.children.n do
			tile.children[tile.children[j]] = j + 1
		end
		table.insert(tile.children, i, new)
		tile.children[new] = i
		tile.children.n = tile.children.n + 1

		if tile.parent then
			move_child(new)
		end

		if tile.mapped then
			for _, child in ipairs(tile.children) do
				title(child)()
			end
		end

		activate(new)
	end

	function tile.remove(prev)
		if tile.parent then
			if tile.mapped and tile.active == prev then
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
			activate(tile.sibling_to_focus(prev))

			local i = tile.children[prev]
			table.remove(tile.children, i)
			tile.children[prev] = nil
			tile.children.n = tile.children.n - 1

			for j = i, tile.children.n do
				tile.children[tile.children[j]] = j
			end

			if tile.mapped then
				for _, child in ipairs(tile.children) do
					title(child)()
				end
			end
		end
	end

	function tile.replace(prev, new)
		if tile.parent then
			prev.unmap()
			prev.off()
		end
		prev.removed_from(tile)

		-- replace in the array
		tile.children[tile.children[prev]] = new
		-- update the index
		tile.children[new] = tile.children[prev]
		tile.children[prev] = nil

		new.put_under(tile)
		if tile.parent then
			move_child(new)
		end
		if tile.active == prev then
			tile.active = nil
			activate(new)
		end
		if tile.mapped then
			title(new)()
		end
	end

	function tile.move(move)
		for _, child in ipairs(tile.children) do
			move_child(child)
		end
		if tile.active then
			tile.active.map()
		end
	end

	function tile.activate(child)
		if child then
			if tile.active and tile.mapped then
				tile.active.unmap()
			end
			tile.active = child
			if tile.mapped then
				child.map()
			end
		end
	end

	function tile.sibling_to_focus(child)
		local i = tile.children[child]
		return tile.children[i - 1] or tile.children[i + 1]
	end

	Tile(tile)

	return tile
end
