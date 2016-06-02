local pl = require 'pl.import_into' ()
local ffi = require 'ffi'
local uv = require 'luv'

local x11 = require 'x11'

local function gen_id()
	return tostring({}):match('^table: 0x....(.+)$')
end

local windows = {
	cache = setmetatable({}, {
		-- __mode = 'v';
	});
}

local function Window(win)
	local required = {
		'add';
		'replace';
		'remove';

		'put_under';
		'removed_from';

		'on';
		'off';

		'move';
	}
	local missing
	for _, name in ipairs(required) do
		if type(win[name]) ~= 'function' then
			print('missing', name)
			missing = true
		end
	end
	if missing then
		error('missing')
	end

	win.parents = {}

	windows.cache[win.xwin] = win

	do
		local old_put_under = win.put_under
		function win.put_under(parent)
			win.parents[parent] = true
			old_put_under(parent)
		end
	end

	do
		local old_removed_from = win.removed_from
		function win.removed_from(parent)
			win.parents[parent] = nil
			old_removed_from(parent)
		end
	end

	do
		local old_on = win.on
		function win.on(...)
			print('on', win.xwin)
			x11.map(win.xwin)
			old_on(...)
			win.move(...)
		end
	end

	do
		local old_off = win.off
		function win.off(...)
			print('off', win.xwin)
			old_off(...)
			x11.unmap(win.xwin)
		end
	end

	do
		local oldmove = win.move
		function win.move(parent, x, y, width, height)
			print('move', win.xwin, parent.xwin, x, y, width, height)

			if win.parent ~= parent then
				x11.reparent(win.xwin, parent.xwin)
			end
			win.parent = parent
			x11.move(win.xwin, x, y, width, height)

			oldmove(parent, x, y, width, height)
		end
	end

	return win
end

setmetatable(windows, { __call = function(_, xwin, get)
	if windows.cache[xwin] then
		return windows.cache[xwin]
	else
		return get(xwin)
	end
end })

function windows.auto(xwin)
	local attrs = x11.get_window_attributes(xwin)()

	if attrs.override_redirect == 0 then
		return windows.clw(xwin)
	else
		return windows.oclw(xwin)
	end
end

function windows.dummy(xwin)
	local win = {
		type = 'dummy';
		xwin = xwin;
	}

	return win
end

function windows.oclw(xwin)
	local win = {
		type = 'oclw';
		xwin = xwin;
	}

	windows.cache[xwin] = win

	return win
end

function windows.clw(clw)
	print('clw', clw)

	local win = {
		type = 'clw';
		clw = clw;
		needs_title = true;
	}

	windows.cache[clw] = win

	do
		local values = ffi.new('int32_t[1]', bit.bor(
			x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY
		))
		x11.xcb.xcb_change_window_attributes(x11.conn, clw, x11.xcb.XCB_CW_EVENT_MASK, values)
	end

	win.xwin = x11.xcb.xcb_generate_id(x11.conn)
	print('frame', win.xwin)
	x11.xcb.xcb_create_window(x11.conn,
		0, -- depth = copy from parent
		win.xwin, -- window
		x11.screen.root, -- parent
		0, 0, -- x, y
		1, 1, -- width, height
		0, -- border width
		x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
		x11.screen.root_visual, -- visual
		0, -- values mask
		nil -- values
	)

	function win.put_under(parent)
	end

	function win.removed_from(parent)
	end

	function win.move(parent, x, y, width, height)
		print('move', win.clw, win.xwin, 2, 0, width - 4, height - 2)
		x11.move(win.clw, 2, 0, width - 4, height - 2)
	end

	function win.add(child, dir)
		win.parent.add(child, 'up')
	end

	function win.on(parent, x, y, width, height)
	end

	function win.off()
	end

	function win.replace(prev, new)
	end

	function win.remove(child)
	end

	Window(win)

	x11.reparent(clw, win.xwin)
	x11.map(clw)

	return win
end

function windows.hsplit()
	local con = {
		children = {};
		sizes = {};
	}

	con.xwin = x11.xcb.xcb_generate_id(x11.conn)
	x11.xcb.xcb_create_condow(x11.conn,
		0, -- depth = copy from parent
		con.xwin, -- condow
		x11.screen.root, -- parent
		0, 0, -- x, y
		1, 1, -- width, height
		0, -- border width
		x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
		x11.screen.root_visual, -- visual
		0, -- values mask
		nil -- values
	)

	local function resizer()
		local r = {
			ceil = true;
			x = 0;
		}

		if con.is_on then
			setmetatable(r, { __call = function(_, child)
				local width = con.width * con.sizes[child]
				if r.ceil and width % 1 ~= 0 then
					width = math.ceil(width)
					r.ceil = false
				else
					width = math.floor(width)
				end
				child.move(con, r.x, con.y, width, con.height)
				r.x = r.x + width
			end })
		else
			setmetatable(r, { __call = function() end })
		end

		return r
	end

	function con.add(child)
		child.put_under(con)

		local num = #con.children
		local factor = num / (num + 1)
		local r = resizer()
		for i, child in ipairs(con.children) do
			con.sizes[child] = con.sizes[child] * factor
			r(child)
		end
		con.children[#con.children + 1] = child
		con.sizes[child] = 1/(num + 1)
		r(child)
	end

	function con.remove(child)
		local num = #con.children - 1
		local r = resizer()
		local amt = con.sizes[child] / num
		local child_i
		for i, child_ in ipairs(con.children) do
			if child_ == child then
				child_i = i
			else
				con.sizes[child_] = con.sizes[child_] + amt
				r(child_)
			end
		end
		if child_i then
			table.remove(con.children, child_i)
		end
		con.sizes[child] = nil
		
		child.removed_from(con)
		child.off()
	end

	function con.resize(child, size)
		local prev = con.sizes[child]
		con.sizes[child] = size
		
		local r = resizer()
		local hit
		for i, child_ in ipairs(con.children) do
			if hit == 2 then
				break
			end

			if hit == 1 then
				con.sizes[child_] = con.sizes[child_] + prev - size
			end

			if child_ == child then
				hit = 0
			end
			if hit then
				hit = hit + 1
			end

			r(child_)
		end
	end

	function con.move(parent, x, y, width, height)
		local r = resizer()
		for _, child in ipairs(con.children) do
			r(child)
		end
	end

	function con.replace(prev, new)
		local r = resizer()
		for i, child in ipairs(con.children) do
			if child == prev then
				local size = con.sizes[child]
				con.sizes[child] = nil
				con.sizes[new] = size

				child.off()

				child = new
				con.children[i] = new
			end
			r(child)
		end
	end

	return con
end

local root
do
	root = {
		type = 'root';
	}

	local geom = x11.get_geometry(x11.screen.root)()
	root.x = geom.x
	root.y = geom.y
	root.width = geom.width
	root.height = geom.height

	root.xwin = x11.screen.root
	-- root.xwin = x11.xcb.xcb_generate_id(x11.conn)
	print('root', root.xwin)
	-- x11.xcb.xcb_create_window(x11.conn,
	-- 	0, -- depth: copy from parent
	-- 	root.xwin, -- window
	-- 	x11.screen.root, -- parent
	-- 	root.x, root.y, -- x, y
	-- 	root.width, root.height, -- width, height
	-- 	0, -- border width
	-- 	x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
	-- 	x11.screen.root_visual, -- visual
	-- 	0, -- values mask
	-- 	nil -- values
	-- )

	windows.cache[root.xwin] = root

	-- x11.map(root.xwin)

	function root.add(win, dir)
		if dir == 'up' then
			print('TODO', 'root.add')
			win.put_under(root)
			win.on(root, root.x, root.y, root.width, root.height)
		elseif dir == 'down' then
			if root.child then
				return root.child.add(win, 'down')
			else
				root.child = win
				win.put_under(root)
				win.on(root, root.x, root.y, root.width, root.height)
			end
		end
	end

	function root.replace(prev, new)
		root.child = new
		prev.off()
		new.on(root, root.x, root.y, root.width, root.height)
	end

	function root.remove(child)
		print('root.remove')
		root.child = nil
		child.removed_from(root)
		child.off()
	end

	function root.redraw_frame()
		if root.child.needs_title then
			print('redraw', 'root', 'frame')
		end
	end
end

local focused = root

function windows.add(win)
	local prev = focused
	focused.add(win, 'down')
	focused = win
	-- print('focus', focused.xwin)
	-- prev.redraw_frame()
end

function windows.replace(prev, new)
	prev.parent.replace(prev, new)
	if focused == prev then
		focused = new
		-- print('focus', focused.xwin)
	end
end

function windows.remove(win)
	if focused == win then
		focused = win.parent or root
	end
	for parent in pairs(win.parents) do
		parent.remove(win)
	end
end

return windows
