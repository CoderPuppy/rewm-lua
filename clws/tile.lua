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

	local tile = {
		type = 'clw';
		parents = {};
		as_clw = {};
		clw = clw;
	}

	clw.tile = tile

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
					x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY;
					x11.xcb.XCB_EVENT_MASK_EXPOSURE;
					x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS;
				}))
			)
		)
	end

	local cls = 'rewm:clw'
	x11.xcb.xcb_change_property(x11.conn, x11.xcb.XCB_PROP_MODE_REPLACE, tile.xwin, x11.A.WM_CLASS, x11.A.STRING, 8, #cls, cls)

	x11.change_window_attributes(clw.xwin, {
		event_mask = bit.bor(unpack({ 0;
			x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY;
		}));
	})

	x11.reparent(clw.xwin, tile.xwin)
	x11.map(clw.xwin)

	x11.xcb.xcb_grab_button(x11.conn,
		false, -- whether the window gets events
		clw.xwin, -- window
		x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS, -- event mask
		x11.xcb.XCB_GRAB_MODE_SYNC, -- pointer grab mode
		x11.xcb.XCB_GRAB_MODE_SYNC, -- keyboard grab mode
		x11.screen.root, -- constraint to window
		0, -- cursor: XCB_NONE (don't change)
		1, -- button (left click)
		x11.xcb.XCB_MOD_MASK_ANY -- modifiers
	)

	function clw.button_press(ev)
		tiles.focus(tile)
		x11.xcb.xcb_allow_events(x11.conn, x11.xcb.XCB_ALLOW_REPLAY_POINTER, ev.time)
		x11.xcb.xcb_allow_events(x11.conn, x11.xcb.XCB_ALLOW_ASYNC_KEYBOARD, ev.time)
	end

	function tile.as_clw.button_press(ev)
		tiles.focus(tile)
	end

	local function render()
		if not tile.parent then
			return
		end

		local colors_ = tiles.focused == tile and colors.focused or colors.unfocused
		local rects = ffi.new('xcb_rectangle_t[1]')

		if tile.mapped and true then
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
			tile.title_pl(tile.title)
		elseif tile.mapped then
			render_title {
				xwin = tile.xwin;
				x = 0;
				y = 0;
				width = tile.width;
				height = 18;
				title = tile.title;
				colors = colors_;
			}
		end
	end

	function tile.as_clw.expose(ev)
		render()
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

	function clw.property_change(ev)
		if ev.atom == x11.A.WM_NAME or ev.atom == x11.A._NET_WM_NAME then
			update_title()
		end
	end

	function clw.map_request(ev)
		tiles.add(tile)
	end

	function clw.destroyed(ev)
		tiles.remove(tile)
		x11.destroy_window(tile.xwin)
		tiles.cache[tile.xwin] = nil
		clws.cache[clw.xwin] = nil
	end

	function tile.add(new, dir)
		tile.parent.add(new, 'up')
	end

	function tile.move(move)
		local x, y, width, height = 0, 0, tile.width, tile.height

		if true then
			x = x + 2
			width = width - 4
			height = height - 2
		end

		if not tile.title_pl then
			y = y + 18
			height = height - 18
		end

		x11.move(clw.xwin, x, y, width, height)
	end

	function tile.focus()
		x11.focus(tile.xwin)
		render()
	end

	function tile.unfocus()
		render()
	end

	function tile.as_clw.unmapped(ev)
	end
	
	Tile(tile)
	ClW(clw)

	return clw
end
