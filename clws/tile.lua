local clws, tiles = unpack(require '../windows')
local ClW = require '../clw'
local Tile = require '../tile'
local x11 = require '../x11'
local ffi = require 'ffi'
local colors = require '../colors'
local gc = require '../gc'
local render_title = require '../render-title'

function clws.tile(xclw)
	local clw = {
		type = 'tile';
		xwin = xclw;
	}
	clws.cache[clw.xwin] = clw

	ClW(clw)

	local tile = {
		type = 'clw';
		parents = {};
		as_clw = {};
		clw = clw;
	}

	clw.tile = tile

	-- Create frame window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tiles.cache[tile.xwin] = tile
		local values = ffi.new('int32_t[3]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS;
				-- x11.xcb.XCB_EVENT_MASK_BUTTON_RELEASE;
				-- x11.xcb.XCB_EVENT_MASK_POINTER_MOTION;
				x11.xcb.XCB_EVENT_MASK_EXPOSURE;
				-- x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY;
				x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT;
				x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY;
				-- x11.xcb.XCB_EVENT_MASK_ENTER_WINDOW;
				-- x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY;
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

	-- Listen on the clw window
	do
		x11.change_window_attributes(clw.xwin, {
			event_mask = bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY;
				x11.xcb.XCB_EVENT_MASK_PROPERTY_CHANGE;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}));
		})
		x11.xcb.xcb_grab_button(x11.conn,
			false, -- whether the window gets events
			clw.xwin, -- window
			x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS, -- event mask
			x11.xcb.XCB_GRAB_MODE_SYNC, -- pointer grab mode
			x11.xcb.XCB_GRAB_MODE_ASYNC, -- keyboard grab mode
			x11.screen.root, -- constraint to window
			0, -- cursor: XCB_NONE (don't change)
			1, -- button
			x11.xcb.XCB_MOD_MASK_ANY -- modifiers
		)
	end

	-- Move clw window under frame window
	do
		x11.reparent(clw.xwin, tile.xwin)
		x11.map(clw.xwin)
	end

	local function render()
		-- if it doesn't have a parent then it's not mapped
		if not tile.parent then return end

		local colors_ = tiles.focused == tile and colors.focused or colors.unfocused
		local rects = ffi.new('xcb_rectangle_t[1]')

		if tile.internal_frame then
			x11.change_gc(gc, {
				foreground = colors_.border;
				line_width = 2;
			})
			rects[0].x = 1
			rects[0].y = 1
			rects[0].width = tile.width - 2
			rects[0].height = tile.height - 2
			x11.xcb.xcb_poly_rectangle(x11.conn, tile.xwin, gc, 1, rects)
		end

		if tile.title_pl then
			tile.title_pl.render()
		else
			render_title {
				xwin = tile.xwin;
				x = 0;
				y = 0;
				width = tile.width;
				height = 18;
				title = tile.title;
				colors = tiles.focused == tile and colors.focused or colors.unfocused
			}
		end
	end

	local function update_title()
		local ascii_cookie = x11.get_property(clw.xwin, x11.xcb.XCB_ATOM_WM_NAME, 128)
		local utf8_cookie = x11.get_property(clw.xwin, x11.A._NET_WM_NAME, 128)

		local ascii_val = ascii_cookie()
		tile.ascii_title = ffi.string(ascii_val.ptr, ascii_val.len)
		
		local utf8_val = utf8_cookie()
		tile.utf8_title = ffi.string(utf8_val.ptr, utf8_val.len)

		tile.title = (tile.utf8_title or tile.ascii_title) .. ' (' .. tile.xwin .. ' ' .. clw.xwin .. ')'
		render()
	end

	update_title()

	function clw.map_request(ev)
		if not tile.parent then
			tiles.add(tile)
		end
	end

	function clw.mapped(ev)
	end

	function clw.unmapped(ev)
		tiles.remove(tile)
		x11.destroy_window(tile.xwin)
		clws.cache[clw.xwin] = nil
		tiles.cache[tile.xwin] = nil
	end

	function clw.property_change(ev)
		if ev.atom == x11.xcb.XCB_ATOM_WM_NAME then
			update_title()
		elseif ev.atom == x11.A._NET_WM_NAME then
			update_title()
		end
	end

	function clw.destroyed(ev)
		tiles.remove(tile)
		x11.destroy_window(tile.xwin)
		clws.cache[clw.xwin] = nil
		tiles.cache[tile.xwin] = nil
	end

	function clw.button_press(ev)
		x11.xcb.xcb_allow_events(x11.conn, x11.xcb.XCB_ALLOW_REPLAY_POINTER, ev.time)
		tiles.focus(tile)
	end

	-- TODO: pull out duplicate code

	function tile.move(move)
		local x, y, width, height = 0, 0, tile.width, tile.height
		if not move.title_pl then
			y = y + 18
			height = height - 18
		end
		if tile.internal_frame then
			x = x + 2
			width = width - 4
			height = height - 2
		end
		x11.move(clw.xwin, x, y, width, height)
	end

	function tile.add(new, dir)
		tile.parent.add(new, 'up')
	end

	function tile.focus()
		x11.focus(clw.xwin)
		render()
	end

	function tile.defocus()
		render()
	end

	function tile.as_clw.expose(ev)
		render()
	end

	function tile.as_clw.button_press(ev)
		tiles.focus(tile)
	end

	Tile(tile)

	return clw
end
