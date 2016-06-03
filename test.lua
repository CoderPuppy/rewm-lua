local ffi = require 'ffi'
local uv = require 'luv'
local pl = require 'pl.import_into' ()

local x11 = require 'x11'

-- Listen for events on root window
do
	local values = ffi.new('uint32_t[1]', bit.bor(
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
	))
	local req = x11.xcb.xcb_change_window_attributes_checked(x11.conn, x11.screen.root, x11.xcb.XCB_CW_EVENT_MASK, values)
	local e = x11.xcb.xcb_request_check(x11.conn, req)
	if e ~= nil then
		error('there\'s already a window manager')
	end
end

local function create_window()
	local xwin = x11.xcb.xcb_generate_id(x11.conn)
	local values = ffi.new('int32_t[1]', bit.bor(unpack({ 0;
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY;
		x11.xcb.XCB_EVENT_MASK_STRUCTURE_NOTIFY;
	})))
	x11.xcb.xcb_create_window(x11.conn,
		0, -- depth: copy from parent
		xwin, -- window
		x11.screen.root, -- parent
		0, 0, -- x, y
		1, 1, -- width, height
		0, -- border width
		x11.xcb.XCB_WINDOW_CLASS_INPUT_OUTPUT, -- class
		x11.screen.root_visual, -- visual
		bit.bor( -- values mask
			x11.xcb.XCB_CW_EVENT_MASK
		),
		values -- values
	)
	return xwin
end

local a = create_window()
print('a', a)
local b = create_window()
print('b', b)

x11.map(b)
x11.reparent(b, a)
x11.reparent(b, x11.screen.root)

x11.on('map_notify', function(ev)
	print('map', ev.window)
end)

x11.on('reparent_notify', function(ev)
	print('repar', ev.window)
end)

x11.on('unmap_notify', function(ev)
	print('unmap', ev.window)
end)

uv.run()
