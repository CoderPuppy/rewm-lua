-- local x11 = require 'x11'
local pl = require 'pl.import_into' ()

local function gen_id()
	return tostring({}):match('^table: 0x....(.+)$')
end

local windows = {
	cache = {};
}

local function Window(win)
	return win
end

setmetatable(windows, { __call = function(_, xwin, get)
	if windows.cache[xwin] then
		return windows.cache[xwin]
	elseif get then
		return get(xwin)
	else
		local win = {
			xwin = xwin;
			needs_title = true;
		}

		function win.move(parent, x, y, width, height)
			print('move', win.xwin, parent.xwin, x, y, width, height)
		end

		function win.add(child, dir)
			win.parent.add(child, 'up')
		end

		return win
	end
end })

function windows.frame(win)
	local frame = {
		xwin = 'f ' .. win.xwin;
		needs_title = win.needs_title;
	}

	win.parent = frame

	function frame.move(parent, x, y, width, height)
		print('move', frame.xwin, parent.xwin, x, y, width, height)
		win.move(frame, x + 2, y, width - 4, height - 2)
	end

	function frame.add(child, dir)
		if dir == 'up' then
			frame.parent.add(child, 'up')
		elseif dir == 'down' then
			win.add(child, 'down')
		end
	end

	function frame.replace(prev, new)
	end

	return frame
end

function windows.hsplit()
	local con = {
		xwin = 'h ' .. gen_id();
		children = {};
		sizes = {};
	}

	local function resizer()
		local r = {
			ceil = true;
			x = 0;
		}

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

		return r
	end

	function con.add(child)
		local num = #con.children
		local factor = num / (num + 1)
		local r = resizer()
		for i, child in ipairs(con.children) do
			con.sizes[child] = con.sizes[child] * factor
			r(child)
		end
		con.children[#con.children + 1] = child
		con.sizes[child] = 1/(num + 1)
		child.parent = con
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
		print('unmap', child)
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
		print('move', con.xwin, parent.xwin, x, y, width, height)
		con.x = x
		con.y = y
		con.width = width
		con.height = height

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

				print('unmap', child.xwin)
				child = new
				con.children[i] = new
			end
			r(child)
			child.replace(prev, new)
		end
	end

	return con
end

local root = {
	type = 'root';
	-- xwin = x11.screen.root;
	xwin = 'root';
	x = 0; y = 0;
	width = 1600; height = 900;
}

function root.add(win, dir)
	if dir == 'up' then
		print('TODO', 'root.add')
	elseif dir == 'down' then
		if root.child then
			return root.child.add(win, 'down')
		else
			root.child = win
			win.parent = root
			win.move(root, root.x, root.y, root.width, root.height)
		end
	end
end

function root.replace(prev, new)
	if root.child == prev then
		root.child = new
		print('unmap', prev.xwin)
		new.move(root, root.x, root.y, root.width, root.height)
	end
	if root.child then
		root.child.replace(prev, new)
	end
end

function root.redraw_frame()
	if root.child.needs_title then
		print('redraw', 'root', 'frame')
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

-- print('\nadding test1')
-- local test1 = windows.frame(windows('t1'))
-- windows.add(test1)
--
-- print('\nspliting')
-- local hsplit = windows.hsplit()
-- windows.replace(test1, hsplit)
-- windows.add(test1)
--
-- print('\nadding test2')
-- local test2 = windows.frame(windows('t2'))
-- windows.add(test2)
--
-- print('\nadding test3')
-- local test3 = windows.frame(windows('t3'))
-- windows.add(test3)
--
-- print('\nresizing')
-- hsplit.resize(test1, 0.5)
--
-- print('\nremoving test3')
-- hsplit.remove(test3)
--
-- print('\nreplacing test2 with test3')
-- windows.replace(test2, test3)

return windows
