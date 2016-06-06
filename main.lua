local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

_G.i = pl.pretty.write
function _G.p(...)
	io.stderr:write(table.concat(pl.seq({...}):map(tostring):copy(), '\t') .. '\n')
end

local x11 = require 'x11'
local clws, tiles = table.unpack(require 'windows')

local A = x11.A

p('randr', i(x11.randr_outputs()))
p('xinerama', i(x11.xinerama_screens()))

-- Listen for events on root window
do
	local values = ffi.new('uint32_t[1]', bit.bor(unpack({ 0;
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT;
		x11.xcb.XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY;
	})))
	local req = x11.xcb.xcb_change_window_attributes_checked(x11.conn, x11.screen.root, x11.xcb.XCB_CW_EVENT_MASK, values)
	local e = x11.xcb.xcb_request_check(x11.conn, req)
	if e ~= nil then
		error('there\'s already a window manager')
	end
end

do
	local tree = x11.xcb.xcb_query_tree_reply(x11.conn, x11.xcb.xcb_query_tree(x11.conn, x11.screen.root), nil)
	local children = x11.xcb.xcb_query_tree_children(tree)
	local children_len = x11.xcb.xcb_query_tree_children_length(tree)
	for i = 1, children_len do
		local xwin = children[i - 1]
		local clw = clws(xwin, clws.auto)
		if clw.type == 'tile' then
			tiles.add(clw.tile)
		end
	end
	x11.flush()
end

x11.on('map_request', function(ev)
	local clw = clws(ev.window, clws.auto)
	clw.map_request(ev)
end)

x11.on('map_notify', function(ev)
	local clw = clws(ev.window, clws.auto)
	-- p('map notify', clw.type, ev.window)
	clw.mapped(ev)
end)

x11.on('unmap_notify', function(ev)
	-- no this really shouldn't call anything
	p('unmap notify', clws(ev.window, clws.dummy).type, ev.window)
end)

x11.on('smooth:unmap_notify', function(ev)
	local clw = clws(ev.window, clws.dummy)
	-- p('unmap notify', clw.type, ev.window)
	clw.unmapped(ev)
end)

x11.on('reparent_notify', function(ev)
	local clw = clws(ev.window, clws.dummy)
	local parent = clws(ev.parent, clws.dummy)
	-- p('reparent notify', clw.type, ev.window, parent.type, ev.parent)
end)

x11.on('destroy_notify', function(ev)
	local clw = clws(ev.window, clws.dummy)
	clw.destroyed(ev)
end)

x11.on('expose', function(ev)
	local clw = clws(ev.window, clws.dummy)
	clw.expose(ev)
end)

x11.on('property_notify', function(ev)
	local reply = x11.xcb.xcb_get_atom_name_reply(x11.conn, x11.xcb.xcb_get_atom_name_unchecked(x11.conn, ev.atom), nil)
	local clw = clws(ev.window, clws.dummy)
	-- p('property_change', clw.type, ev.window, ffi.string(x11.xcb.xcb_get_atom_name_name(reply), x11.xcb.xcb_get_atom_name_name_length(reply)))
	clw.property_change(ev)
end)

x11.on('focus_in', function(ev)
	local rpl = x11.xcb.xcb_get_input_focus_reply(x11.conn, x11.xcb.xcb_get_input_focus(x11.conn), nil)
	local clw = clws(rpl.focus, clws.dummy)
	-- p('focus in', clw.type, ev.event)
	clw.focus_in(ev)
end)

x11.on('focus_out', function(ev)
	local clw = clws(ev.event, clws.dummy)
	-- p('focus out', clw.type, ev.event)
	clw.focus_out(ev)
end)

x11.on('button_press', function(ev)
	local clw = clws(ev.event, clws.dummy)
	p('button press', ev.event, clw.type, ev.child, ev.root)
	clw.button_press(ev)
end)

require './uv-repl'

uv.run()
