local x11 = require '../x11'
local clws, tiles = unpack(require '../windows')
local ClW = require '../clw'
local ffi = require 'ffi'
local Tile = require '../tile'

-- TODO: create a root for each randr output or xinerama screen
local root = {
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

tiles.focus(root)
