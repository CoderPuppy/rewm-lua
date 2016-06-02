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

local clws, windows

clws = {
	cache = {};
}

setmetatable(clws, { __call = function(_, xwin, get)
	if clws.cache[xwin] then
		return clws.cache[xwin]
	elseif windows.cache[xwin] then
		return windows.cache[xwin].as_clw
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

	return clw
end

function clws.auto(xwin)
	local attrs = x11.get_window_attributes(xwin)()

	if attrs.override_redirect == 0 then
		return clws.tiled(xwin)
	else
		return clws.unmanaged(xwin)
	end
end

function clws.tiled(xclw)
	local clw = {
		type = 'tiled';
		xwin = xclw;
	}
	clws.cache[clw.xwin] = clw

	local win = {
		type = 'clw';
		parents = {};
		as_clw = {};
	}

	clw.win = win

	-- Create frame window
	do
		win.xwin = x11.xcb.xcb_generate_id(x11.conn)
		windows.cache[win.xwin] = win
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
			win.xwin, -- window
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
		x11.reparent(clw.xwin, win.xwin)
		x11.map(clw.xwin)
	end

	local function update_title()
		local ascii_cookie = x11.get_property(clw.xwin, x11.xcb.XCB_ATOM_WM_NAME, 128)
		local utf8_cookie = x11.get_property(clw.xwin, x11.A._NET_WM_NAME, 128)

		local ascii_val = ascii_cookie()
		win.ascii_title = ffi.string(ascii_val.ptr, ascii_val.len)
		
		local utf8_val = utf8_cookie()
		win.utf8_title = ffi.string(utf8_val.ptr, utf8_val.len)

		win.title = (win.utf8_title or win.ascii_title) .. ' (' .. win.xwin .. ' ' .. clw.xwin .. ')'
	end

	update_title()

	function clw.map_request(ev)
		if not win.parent then
			windows.add(win)
		end
	end

	function clw.property_change(ev)
		if ev.atom == x11.xcb.XCB_ATOM_WM_NAME then
			update_title()
		elseif ev.atom == x11.A._NET_WM_NAME then
			update_title()
		end
	end

	function clw.destroyed(ev)
		windows.remove(win)
		x11.destroy_window(win.xwin)
		clws.cache[clw.xwin] = nil
		windows.cache[win.xwin] = nil
	end

	-- TODO: pull out duplicate code
	
	function win.put_under(parent)
		win.parents[parent] = true
	end

	function win.removed_from(parent)
		win.parents[parent] = nil
	end

	function win.move(move)
		if not win.parent then
			-- containers should handle reparenting
			x11.map(win.xwin)
		end

		print('move', win.xwin, move.parent.xwin, move.x, move.y, move.width, move.height)
		win.parent = move.parent
		win.x = move.x
		win.y = move.y
		win.width = move.width
		win.height = move.height
		win.external_title = move.external_title

		x11.move(win.xwin, win.x, win.y, win.width, win.height)

		local x, y, width, height = 0, 0, win.width, win.height
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

	function win.off()
		x11.unmap(win.xwin)
		win.parent = nil
	end

	function win.add(new, dir)
		win.parent.add(new, 'up')
	end


	function win.as_clw.expose(ev)
		local rects = ffi.new('xcb_rectangle_t[1]')

		x11.change_gc(gc, {
			foreground = x11.screen.white_pixel;
			line_width = 2;
		})
		rects[0].x = 1
		rects[0].y = 1
		rects[0].width = win.width - 2
		rects[0].height = win.height - 2
		x11.xcb.xcb_poly_rectangle(x11.conn, win.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			foreground = x11.screen.black_pixel;
		})
		rects[0].x = 1
		rects[0].y = 1
		rects[0].width = win.width - 2
		rects[0].height = 16
		x11.xcb.xcb_poly_fill_rectangle(x11.conn, win.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			foreground = x11.screen.white_pixel;
			line_width = 1;
		})
		rects[0].x = 0
		rects[0].y = 0
		rects[0].width = win.width - 1
		rects[0].height = 17
		x11.xcb.xcb_poly_rectangle(x11.conn, win.xwin, gc, 1, rects)

		x11.change_gc(gc, {
			font = font;
			foreground = x11.screen.white_pixel;
			background = x11.screen.black_pixel;
		})
		x11.xcb.xcb_image_text_8(x11.conn, #win.title, win.xwin, gc, 5, 12, win.title)
	end

	return clw
end

windows = {
	cache = {};
}

setmetatable(windows, { __call = function(_, xwin, get)
	if windows.cache[xwin] then
		return windows.cache[xwin]
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

function windows.hsplit()
	local win = {
		type = 'hsplit';
		parents = {};
		children = {};
		sizes = {};
	}

	-- Create window
	do
		win.xwin = x11.xcb.xcb_generate_id(x11.conn)
		windows.cache[win.xwin] = win
		local values = ffi.new('int32_t[2]',
			1,
			bit.bor(unpack({ 0;
			}))
		)
		x11.xcb.xcb_create_window(x11.conn,
			0, -- depth: copy from parent
			win.xwin, -- window
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
		if child.parent ~= win then
			x11.reparent(child.xwin, win.xwin)
		end
		child.move {
			parent = win;
			x = x;
			y = 0;
			width = width;
			height = win.height;
		}
	end

	function win.add(new)
		new.put_under(win)

		local num = #win.children
		local factor = num / (num + 1)
		
		local r = split_resizer(win, win.width)
		for _, child in ipairs(win.children) do
			win.sizes[child] = win.sizes[child] * factor
			r(child, split_move)
		end

		win.children[#win.children + 1] = new
		win.sizes[new] = 1 / (num + 1)
		r(new, split_move)
	end

	function win.remove(prev)
		prev.removed_from(win)
		if win.parent then
			prev.off()
		end

		if #win.children == 1 then
			windows.remove(win)
			x11.destroy_window(win.xwin)
			windows.cache[win.xwin] = nil
		else
			local amt = win.sizes[prev] / (#win.children - 1)
			local r = split_resizer(win, win.width)
			local prev_i
			for i, child in ipairs(win.children) do
				if child == prev then
					prev_i = i
				else
					win.sizes[child] = win.sizes[child] + amt
					r(child, split_move)
				end
			end
			if prev_i then
				table.remove(win.children, prev_i)
			end
			win.sizes[prev] = nil
		end
	end

	function win.put_under(parent)
		win.parents[parent] = true
	end

	function win.removed_from(parent)
		win.parents[parent] = nil
	end

	function win.move(move)
		if not win.parent then
			x11.map(win.xwin)
		end

		win.parent = move.parent
		win.x = move.x
		win.y = move.y
		win.width = move.width
		win.height = move.height

		x11.move(win.xwin, win.x, win.y, win.width, win.height)

		local r = split_resizer(win, win.width)
		for _, child in ipairs(win.children) do
			r(child, split_move)
		end
	end

	function win.off()
		x11.unmap(win.xwin)
		win.parent = nil
	end

	return win
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
				local split = windows.hsplit()
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

function windows.add(win)
	print(focused.type)
	focused.add(win, 'down')
	focused = win
end

function windows.replace(prev, new)
	print('TODO', 'windows.replace')
end

function windows.remove(win)
	if focused == win then
		focused = win.parent or root
	end
	for parent in pairs(win.parents) do
		parent.remove(win)
	end
end

return {clws, windows}
