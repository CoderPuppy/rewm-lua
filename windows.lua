local pl = require 'pl.import_into' ()
local ffi = require 'ffi'
local uv = require 'luv'

local x11 = require 'x11'
local xtend = require 'xtend'

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

local colors = {
	unfocused = {
		border = 0x333333;
		bg = 0x1F1F1F;
		title = 0xC0B18B;
	};

	focused = {
		border = 0x5A3637;
		bg = 0x2F1F1F;
		title = 0xEDEDED;
	};
}
do
	colors = xtend.deep_map(colors, function(path, v)
		return x11.xcb.xcb_alloc_color(x11.conn,
			x11.screen.default_colormap, -- colormap
			bit.band(0xFF, bit.rshift(v, 16)) * 256, -- red
			bit.band(0xFF, bit.rshift(v,  8)) * 256, -- green
			bit.band(0xFF, bit.rshift(v,  0)) * 256  -- blue
		)
	end)
	local err = ffi.new('xcb_generic_error_t*[1]')
	colors = xtend.deep_map(colors, function(path, v)
		local res = x11.xcb.xcb_alloc_color_reply(x11.conn, v, err)
		if res == nil then
			x11.error(err[1])
			return
		end
		return res.pixel
	end)
end

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

local function destroy_tile(tile)
	tiles.cache[tile.xwin] = nil
end

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

local function destroy_clw(clw)
	clws.cache[clw.xwin] = nil
end

local function ClW(clw)
	if not clw.type then
		error('clw missing type')
	end

	if not clw.xwin then
		error('clw missing xwin')
	end

	for _, name in ipairs({
		'map_request';
		'mapped';
		'unmapped';
		'destroyed';
		'expose';
		'property_change';
		'focus_in';
		'focus_out';
		'button_press';
	}) do
		if clw[name] == nil then
			clw[name] = function(ev) end
		elseif type(clw[name]) ~= 'function' then
			error('bad handler: ' .. tostring(clw.type) .. '.' .. name)
		end
	end

	clws.cache[clw.xwin] = clw

	return clw
end

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
		tile.external_title = move.external_title
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

function clws.dummy(xwin)
	local clw = {
		type = 'dummy';
		xwin = xwin;
	}

	ClW(clw)
	clws.cache[clw.xwin] = nil

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

		if not tile.external_title then
			x11.change_gc(gc, {
				foreground = colors_.bg;
			})
			rects[0].x = 1
			rects[0].y = 1
			rects[0].width = tile.width - 2
			rects[0].height = 16
			x11.xcb.xcb_poly_fill_rectangle(x11.conn, tile.xwin, gc, 1, rects)

			x11.change_gc(gc, {
				foreground = colors_.border;
				line_width = 1;
			})
			rects[0].x = 0
			rects[0].y = 0
			rects[0].width = tile.width - 1
			rects[0].height = 17
			x11.xcb.xcb_poly_rectangle(x11.conn, tile.xwin, gc, 1, rects)

			x11.change_gc(gc, {
				font = font;
				foreground = colors_.title;
				background = colors_.bg;
			})
			x11.xcb.xcb_image_text_8(x11.conn, #tile.title, tile.xwin, gc, 5, 14, tile.title)
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

	function clw.button_press(ev)
		x11.xcb.xcb_allow_events(x11.conn, x11.xcb.XCB_ALLOW_REPLAY_POINTER, ev.time)
		tiles.focus(tile)
	end

	-- TODO: pull out duplicate code

	function tile.move(move)
		local x, y, width, height = 0, 0, tile.width, tile.height
		if not move.external_title then
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
			destroy_tile(tile)
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

-- TODO: tabbed
-- TODO: stacked

-- TODO: create a root for each randr output or xinerama screen
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
				p('splitting root')

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

					external_title = false;
				}
				x11.flush_buffer()
				x11.flush()
			end
		end
	end

	function root.remove(prev)
		if root.child ~= prev then error('removing what\'s not there') end
		root.child = nil
		prev.removed_from(root)
		prev.off()
	end

	-- Create input window
	do
		root.input_clw = {
			type = 'hsplit.input_clw';
		}
		root.input_clw.xwin = x11.xcb.xcb_generate_id(x11.conn)
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
				x11.xcb.XCB_EVENT_MASK_FOCUS_CHANGE;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			root.input_clw.xwin, -- window
			root.xwin, -- parent
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
		x11.map(root.input_clw.xwin)
		ClW(root.input_clw)
	end

	function root.focus()
		x11.focus(root.input_clw.xwin)
	end

	for _, name in ipairs({
		'move';
	}) do
		root[name] = function()
			error('root.' .. name .. ': this shouldn\'t ever be called')
		end
	end

	Tile(root)
end

local ewmh
do
	ewmh = {
		type = 'ewmh';
	}

	ewmh.xwin = x11.xcb.xcb_generate_id(x11.conn)
	x11.xcb.xcb_create_window(x11.conn,
		0, -- depth: copy from parent
		ewmh.xwin, -- window
		x11.screen.root, -- parent
		0, 0, -- x, y
		1, 1, -- width, height
		0, -- border width
		x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
		x11.screen.root_visual, -- visual
		0, -- values mask
		nil -- values
	)

	ClW(ewmh)

	x11.map(ewmh.xwin)
end

function tiles.focus(tile)
	local prev = tiles.focused
	tiles.focused = tile
	if prev then
		prev.defocus()
	end
	tile.focus()
end
tiles.focus(root)

function tiles.add(tile)
	p(tiles.focused.type)
	tiles.focused.add(tile, 'down')
	tiles.focus(tile)
end

function tiles.replace(prev, new)
	p('TODO', 'tiles.replace')
end

function tiles.remove(tile)
	if tiles.focused == tile then
		tiles.focused = tile.parent or root
	end
	for parent in pairs(tile.parents) do
		parent.remove(tile)
	end
end

return {clws, tiles}
