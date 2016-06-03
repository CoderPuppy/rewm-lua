local pl = require 'pl.import_into' ()
local ffi = require 'ffi'
local uv = require 'luv'

local x11 = require 'x11'

local gc
do
	gc = x11.xcb.xcb_generate_id(x11.conn)
	x11.xcb.xcb_create_gc(x11.conn, gc, x11.screen.root, 0, nil)
end

local font
do
	font = x11.xcb.xcb_generate_id(x11.conn)
	-- local name = '-adobe-source code pro-medium-r-normal--12-113-75-75-m-0-iso10646-1'
	-- local name = '-*-*-*-*-*-*-16-*-*-*-*-*-iso10646-1'
	local name = 'fixed'
	x11.xcb.xcb_open_font(x11.conn, font, #name, name)
end

local clws, tiles

local function destroy_tile(tile)
	tiles.cache[tile.xwin] = nil
end

local function destroy_clw(clw)
	clws.cache[clw.xwin] = nil
end

clws = {
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

function clws.dummy(xwin)
	local clw = {
		type = 'dummy';
		xwin = xwin;
	}

	function clw.destroyed(ev)
	end

	function clw.unmapped(ev)
	end

	function clw.expose(ev)
	end

	return clw
end

function clws.auto(xwin)
	local attrs = x11.get_window_attributes(xwin)()

	if attrs.override_redirect == 0 then
		return clws.tile(xwin)
	else
		return clws.unmanaged(xwin)
	end
end

function clws.tile(xclw)
	local clw = {
		type = 'tile';
		xwin = xclw;
	}
	clws.cache[clw.xwin] = clw

	local tile = {
		type = 'clw';
		parents = {};
		as_clw = {
			type = 'tile[clw].as_clw';
		};
	}

	tile.as_clw.tile = tile
	clw.tile = tile

	-- Create frame window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tile.as_clw.xwin = tile.xwin
		tiles.cache[tile.xwin] = tile
		local values = ffi.new('int32_t[3]',
			1,
			bit.bor(unpack({ 0;
				-- x11.xcb.XCB_EVENT_MASK_BUTTON_PRESS;
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
			}));
		})
	end

	-- Move clw window under frame window
	do
		x11.reparent(clw.xwin, tile.xwin)
		x11.map(clw.xwin)
	end

	local function update_title()
		local ascii_cookie = x11.get_property(clw.xwin, x11.xcb.XCB_ATOM_WM_NAME, 128)
		local utf8_cookie = x11.get_property(clw.xwin, x11.A._NET_WM_NAME, 128)

		local ascii_val = ascii_cookie()
		tile.ascii_title = ffi.string(ascii_val.ptr, ascii_val.len)
		
		local utf8_val = utf8_cookie()
		tile.utf8_title = ffi.string(utf8_val.ptr, utf8_val.len)

		tile.title = (tile.utf8_title or tile.ascii_title) .. ' (' .. tile.xwin .. ' ' .. clw.xwin .. ')'
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
		destroy_tile(tile)
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
		destroy_clw(clw)
		destroy_tile(tile)
	end

	function tile.as_clw.mapped(ev)
	end

	function tile.as_clw.unmapped(ev)
	end

	-- TODO: pull out duplicate code
	
	function tile.put_under(parent)
		tile.parents[parent] = true
	end

	function tile.removed_from(parent)
		tile.parents[parent] = nil
	end

	function tile.move(move)
		if not tile.parent then
			-- containers should handle reparenting
			x11.map(tile.xwin)
		end

		print('move', tile.xwin, move.parent.xwin, move.x, move.y, move.width, move.height)
		tile.parent = move.parent
		tile.x = move.x
		tile.y = move.y
		tile.width = move.width
		tile.height = move.height
		tile.external_title = move.external_title

		x11.move(tile.xwin, tile.x, tile.y, tile.width, tile.height)

		local x, y, width, height = 0, 0, tile.width, tile.height
		if not move.external_title then
			y = y + 18
			height = height - 18
		end
		x = x + 2
		width = width - 4
		height = height - 2
		-- TODO: make the frame optional
		x11.move(clw.xwin, x, y, width, height)
	end

	function tile.off()
		x11.unmap(tile.xwin)
		tile.parent = nil
	end

	function tile.add(new, dir)
		tile.parent.add(new, 'up')
	end


	function tile.as_clw.expose(ev)
		local rects = ffi.new('xcb_rectangle_t[1]')

		x11.change_gc(gc, {
			foreground = x11.screen.white_pixel;
			line_width = 2;
		})
		rects[0].x = 1
		rects[0].y = 1
		rects[0].width = tile.width - 2
		rects[0].height = tile.height - 2
		x11.xcb.xcb_poly_rectangle(x11.conn, tile.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			foreground = x11.screen.black_pixel;
		})
		rects[0].x = 1
		rects[0].y = 1
		rects[0].width = tile.width - 2
		rects[0].height = 16
		x11.xcb.xcb_poly_fill_rectangle(x11.conn, tile.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			foreground = x11.screen.white_pixel;
			line_width = 1;
		})
		rects[0].x = 0
		rects[0].y = 0
		rects[0].width = tile.width - 1
		rects[0].height = 17
		x11.xcb.xcb_poly_rectangle(x11.conn, tile.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			font = font;
			foreground = x11.screen.white_pixel;
			background = x11.screen.black_pixel;
		})
		x11.xcb.xcb_image_text_8(x11.conn, #tile.title, tile.xwin, gc, 5, 12, tile.title)
	end

	return clw
end

tiles = {
	cache = {};
}

setmetatable(tiles, { __call = function(_, xwin, get)
	if tiles.cache[xwin] then
		return tiles.cache[xwin]
	else
		return get(xwin)
	end
end })

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

		as_clw = {
			type = 'tile[hsplit].as_clw';
		};
	}

	-- Create window
	do
		tile.xwin = x11.xcb.xcb_generate_id(x11.conn)
		tiles.cache[tile.xwin] = tile
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
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
			destroy_tile(tile)
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

	function tile.put_under(parent)
		tile.parents[parent] = true
	end

	function tile.removed_from(parent)
		tile.parents[parent] = nil
	end

	function tile.move(move)
		if not tile.parent then
			x11.map(tile.xwin)
		end

		tile.parent = move.parent
		tile.x = move.x
		tile.y = move.y
		tile.width = move.width
		tile.height = move.height

		x11.move(tile.xwin, tile.x, tile.y, tile.width, tile.height)

		local r = split_resizer(tile, tile.width)
		for _, child in ipairs(tile.children) do
			r(child, split_move)
		end
	end

	function tile.off()
		x11.unmap(tile.xwin)
		tile.parent = nil
	end

	function tile.as_clw.mapped(ev)
	end

	return tile
end

local root
do
	root = {
		type = 'root';
		xwin = x11.screen.root;
	}

	do
		local geom = x11.get_geometry(root.xwin)()
		root.x = geom.x
		root.y = geom.y
		root.width = geom.width
		root.height = geom.height
	end

	function root.add(new, dir)
		if root.child and dir == 'down' then
			root.child.add(new, dir)
		else
			if root.child then
				local prev = root.child
				local split = tiles.hsplit()
				split.add(prev)
				split.add(new)

				root.remove(prev)
				root.add(split)
			else
				root.child = new

				x11.reparent(new.xwin, root.xwin)

				new.put_under(root)
				new.move {
					parent = root;
					x = 0;
					y = 0;
					width = root.width;
					height = root.height;

					-- TODO: handle
					external_title = false;
				}
			end
		end
	end

	function root.remove(prev)
		if root.child ~= prev then error('removing what\'s not there') end
		root.child = nil
		prev.removed_from(root)
		prev.off()
	end
end

local focused = root

function tiles.add(tile)
	print(focused.type)
	focused.add(tile, 'down')
	focused = tile
end

function tiles.replace(prev, new)
	print('TODO', 'tiles.replace')
end

function tiles.remove(tile)
	if focused == tile then
		focused = tile.parent or root
	end
	for parent in pairs(tile.parents) do
		parent.remove(tile)
	end
end

return {clws, tiles}
