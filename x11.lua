local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x11 = {}
x11.tick_tasks = {}

-- Load xcb
local xcb, xcb_randr, xcb_xinerama, xcb_util, xcb_shape
do
	local h = io.open('xcb.h', 'r')
	local d = h:read '*a'
	h:close()
	ffi.cdef(d)

	xcb = ffi.load 'xcb'
	xcb_randr = ffi.load 'xcb-randr'
	xcb_xinerama = ffi.load 'xcb-xinerama'
	xcb_util = ffi.load 'xcb-util'
	xcb_shape = ffi.load 'xcb-shape'

	x11.xcb = xcb
	x11.xcb_randr = xcb_randr
	x11.xcb_xinerama = xcb_xinerama
	x11.xcb_util = xcb_util
	x11.xcb_shape = xcb_shape
end

-- Connect
local conn, setup, screen
do
	local scrid = ffi.new('int[1]', 1)
	conn = xcb.xcb_connect(nil, scrid)
	setup = xcb.xcb_get_setup(conn)
	screen = xcb_util.xcb_aux_get_screen(conn, scrid[0])
end
-- TODO
x11.conn = conn
x11.setup = setup
x11.screen = screen

-- Load atoms
local A
do
	A = {}
	for _, atom in ipairs({
		'_NET_WM_NAME';
	}) do
		A[atom] = xcb.xcb_intern_atom(conn, 0, #atom, atom)
	end
	for name, req in pairs(A) do
		A[name] = xcb.xcb_intern_atom_reply(conn, req, nil).atom
	end
end
x11.A = A

function x11.randr_outputs()
	local res = xcb_randr.xcb_randr_get_screen_resources_current_reply(conn, xcb_randr.xcb_randr_get_screen_resources_current(conn, screen.root), nil)

	local ptr = xcb_randr.xcb_randr_get_screen_resources_current_outputs(res)
	return pl.seq(pl.tablex.range(0, xcb_randr.xcb_randr_get_screen_resources_current_outputs_length(res)))
		:map(function(i)
			return xcb_randr.xcb_randr_get_output_info(conn, ptr[i], res.config_timestamp)
		end)
		:map(function(cookie)
			return xcb_randr.xcb_randr_get_output_info_reply(conn, cookie, nil)
		end)
		:filter(function(info)
			return info ~= nil and info.crtc ~= nil
		end)
		:map(function(info)
			return {
				info = info;
				crtc = xcb_randr.xcb_randr_get_crtc_info(conn, info.crtc, res.config_timestamp);
			}
		end)
		:map(function(ctx)
			return {
				info = ctx.info;
				crtc = xcb_randr.xcb_randr_get_crtc_info_reply(conn, ctx.crtc, nil);
			}
		end)
		:filter(function(ctx)
			return ctx.crtc ~= nil
		end)
		:map(function(ctx)
			return {
				name = ffi.string(
					xcb_randr.xcb_randr_get_output_info_name(ctx.info),
					xcb_randr.xcb_randr_get_output_info_name_length(ctx.info)
				);
				x = ctx.crtc.x;
				y = ctx.crtc.y;
				width = ctx.crtc.width;
				height = ctx.crtc.height;
				type = 'randr';
			}
		end)
		:copy()
end

function x11.xinerama_screens()
	local err = ffi.new('xcb_generic_error_t*[1]', nil)
	local reply = xcb_xinerama.xcb_xinerama_query_screens_reply(conn, xcb_xinerama.xcb_xinerama_query_screens(conn), err)
	if err[0] ~= nil then
		error(err[0].error_code)
	end

	local len = xcb_xinerama.xcb_xinerama_query_screens_screen_info_length(reply)
	local iter = xcb_xinerama.xcb_xinerama_query_screens_screen_info_iterator(reply)
	local res = {}
	for i = 1, len do
		res[i] = {
			type = 'xinerama';
			name = 'xinerama-' .. tostring(i);
			x = iter.data.x_org;
			y = iter.data.y_org;
			width = iter.data.width;
			height = iter.data.height;
		}
		xcb_xinerama.xcb_xinerama_screen_info_next(iter)
	end
	return res
end

do
	local out_buffer
	local function reset()
		out_buffer = setmetatable({}, { __index = function(out_buffer, win)
			local out = {
				map = nil; -- true for map, false for unmap
				reparent = nil; -- {parent=, x=, y=}
				destroy = nil;
				configure = {};
				attributes = {};
				wait_for = {};
			}

			out_buffer[win] = out

			return out
		end })
	end
	reset()

	function x11.map(win)
		print('map', win)
		out_buffer[win].map = true
	end

	function x11.unmap(win)
		print('unmap', win)
		out_buffer[win].map = false
	end

	function x11.reparent(win, parent, x, y)
		print('repar', win, parent)
		local out = out_buffer[win]
		out.wait_for[parent] = true
		out.reparent = {
			parent = parent;
			x = x or 0;
			y = y or 0;
		}
	end

	function x11.configure_window(win, opts)
		print('configure', win)
		local out_opts = out_buffer[win].configure
		for k, v in pairs(opts) do
			out_opts[k] = v
		end
	end

	function x11.move(win, x, y, width, height)
		-- TODO: remove
		x11.configure_window(win, {
			x = x; y = y;
			width = width; height = height;
		})
	end

	local cwa = {
		{'back_pixmap', xcb.XCB_CW_BACK_PIXMAP, 'xcb_pixmap_t'};
		{'back_pixel', xcb.XCB_CW_BACK_PIXEL, 'uint32_t'};
		{'border_pixmap', xcb.XCB_CW_BORDER_PIXMAP, 'xcb_pixmap_t'};
		{'border_pixel', xcb.XCB_CW_BORDER_PIXEL, 'uint32_t'};
		{'bit_gravity', xcb.XCB_CW_BIT_GRAVITY, 'uint32_t'};
		{'win_gravity', xcb.XCB_CW_WIN_GRAVITY, 'uint32_t'};
		{'backing_stores', xcb.XCB_CW_BACKING_STORE, 'uint32_t'};
		{'backing_planes', xcb.XCB_CW_BACKING_PLANES, 'uint32_t'};
		{'backing_pixel', xcb.XCB_CW_BACKING_PIXEL, 'uint32_t'};
		{'override_redirect', xcb.XCB_CW_OVERRIDE_REDIRECT, 'uint32_t'};
		{'save_under', xcb.XCB_CW_SAVE_UNDER, 'uint32_t'};
		{'event_mask', xcb.XCB_CW_EVENT_MASK, 'uint32_t'};
		{'dont_propogate', xcb.XCB_CW_DONT_PROPAGATE, 'uint32_t'};
		{'colormap', xcb.XCB_CW_COLORMAP, 'xcb_colormap_t'};
		{'cursor', xcb.XCB_CW_CURSOR, 'xcb_cursor_t'};
	}

	local cw = {
		{'x', xcb.XCB_CONFIG_WINDOW_X, 'int32_t'};
		{'y', xcb.XCB_CONFIG_WINDOW_Y, 'int32_t'};
		{'width', xcb.XCB_CONFIG_WINDOW_WIDTH, 'uint32_t'};
		{'height', xcb.XCB_CONFIG_WINDOW_HEIGHT, 'uint32_t'};
		{'border_width', xcb.XCB_CONFIG_WINDOW_BORDER_WIDTH, 'uint32_t'};
		{'sibling', xcb.XCB_CONFIG_WINDOW_SIBLING, 'xcb_window_t'};
		{'stack_mode', xcb.XCB_CONFIG_WINDOW_STACK_MODE, 'uint32_t'};
	}

	function x11.change_window_attributes(win, attrs)
		print('chg attrs', win)
		local out_attrs = out_buffer[win].attributes
		for k, v in pairs(attrs) do
			out_attrs[k] = v
		end
	end

	function x11.destroy_window(win)
		print('destroy', win)
		out_buffer[win].destroy = true
	end

	function x11.flush_buffer(ord)
		if not ord then
			ord = {}
			for win, out in pairs(out_buffer) do
				ord[#ord + 1] = win
			end
		end
		while #ord > 0 do
			repeat
				local win = table.remove(ord, 1)

				local out = rawget(out_buffer, win)

				if not out then
					break
				end

				do
					local stop = false
					for dep in pairs(out.wait_for) do
						if rawget(out_buffer, dep) then
							ord[#ord + 1] = dep
							stop = true
						end
					end
					if stop then
						ord[#ord + 1] = win
						break
					end
				end

				if out.map == false then
					xcb.xcb_unmap_window(conn, win)
				end
				do
					local repar = out.reparent
					if repar then
						xcb.xcb_reparent_window(conn, win, repar.parent, repar.x, repar.y)
					end
				end
				if out.map == true then
					xcb.xcb_map_window(conn, win)
				end
				do
					local attrs = out.attributes
					local mask = 0
					local values = ffi.new('int32_t[15]')
					local i = 0
					for _, attr in ipairs(cwa) do
						if attrs[attr[1]] then
							mask = bit.bor(mask, attr[2])
							values[i] = ffi.cast(attr[3], attrs[attr[1]])
							i = i + 1
						end
					end
					if mask ~= 0 then
						xcb.xcb_change_window_attributes(conn, win, mask, values)
					end
				end
				do
					local configs = out.configure
					local mask = 0
					local values = ffi.new('int32_t[15]')
					local i = 0
					for _, config in ipairs(cw) do
						if configs[config[1]] then
							mask = bit.bor(mask, config[2])
							values[i] = ffi.cast(config[3], configs[config[1]])
							i = i + 1
						end
					end
					if mask ~= 0 then
						xcb.xcb_configure_window(conn, win, mask, values)
					end
				end

				out_buffer[win] = nil
			until true
		end
		x11.flush()
	end

	table.insert(x11.tick_tasks, 1, {'x11 out_buffer output', function()
		x11.flush_buffer()
	end})

	function x11.get_window_attributes(win)
		x11.flush_buffer({win})
		local cookie = xcb.xcb_get_window_attributes_unchecked(conn, win)
		return function()
			local reply = xcb.xcb_get_window_attributes_reply(conn, cookie, nil)
			return reply
		end
	end

	function x11.get_geometry(win)
		x11.flush_buffer({win})
		local cookie = xcb.xcb_get_geometry_unchecked(conn, win)
		return function()
			local reply = xcb.xcb_get_geometry_reply(conn, cookie, nil)
			return reply
		end
	end

	function x11.get_property(win, prop, length)
		x11.flush_buffer({win})
		local cookie = xcb.xcb_get_property(conn, 0, win, prop, xcb.XCB_GET_PROPERTY_TYPE_ANY, 0, length)
		return function()
			local reply = xcb.xcb_get_property_reply(conn, cookie, nil)
			return {
				ptr = xcb.xcb_get_property_value(reply);
				len = xcb.xcb_get_property_value_length(reply);
			}
		end
	end
end

do
	local gc_attrs = {
		{'function', xcb.XCB_GC_FUNCTION, 'uint32_t'};
		{'plane_mask', xcb.XCB_GC_PLANE_MASK, 'uint32_t'};
		{'foreground', xcb.XCB_GC_FOREGROUND, 'uint32_t'};
		{'background', xcb.XCB_GC_BACKGROUND, 'uint32_t'};
		{'line_width', xcb.XCB_GC_LINE_WIDTH, 'uint32_t'};
		{'line_style', xcb.XCB_GC_LINE_STYLE, 'uint32_t'};
		{'cap_style', xcb.XCB_GC_CAP_STYLE, 'uint32_t'};
		{'join_style', xcb.XCB_GC_JOIN_STYLE, 'uint32_t'};
		{'fill_style', xcb.XCB_GC_FILL_STYLE, 'uint32_t'};
		{'fill_rule', xcb.XCB_GC_FILL_RULE, 'uint32_t'};
		{'tile', xcb.XCB_GC_TILE, 'xcb_pixmap_t'};
		{'stipple', xcb.XCB_GC_STIPPLE, 'xcb_pixmap_t'};
		{'tile_stipple_origin_x', xcb.XCB_GC_TILE_STIPPLE_ORIGIN_X, 'int32_t'};
		{'tile_stipple_origin_y', xcb.XCB_GC_TILE_STIPPLE_ORIGIN_Y, 'int32_t'};
		{'font', xcb.XCB_GC_FONT, 'xcb_font_t'};
		{'subwindow_mode', xcb.XCB_GC_SUBWINDOW_MODE, 'uint32_t'};
		{'graphics_exposures', xcb.XCB_GC_GRAPHICS_EXPOSURES, 'int32_t'};
		{'clip_origin_x', xcb.XCB_GC_CLIP_ORIGIN_X, 'int32_t'};
		{'clip_origin_y', xcb.XCB_GC_CLIP_ORIGIN_Y, 'int32_t'};
		{'clip_mask', xcb.XCB_GC_CLIP_MASK, 'xcb_pixmap_t'};
		{'dash_offset', xcb.XCB_GC_DASH_OFFSET, 'uint32_t'};
		{'dash_list', xcb.XCB_GC_DASH_LIST, 'uint32_t'};
		{'arc_mode', xcb.XCB_GC_ARC_MODE, 'uint32_t'};
	}
	function x11.change_gc(gc, attrs)
		local mask = 0
		local values = ffi.new('int32_t[23]')
		local i = 0

		for _, attr in ipairs(gc_attrs) do
			if attrs[attr[1]] then
				mask = bit.bor(mask, attr[2])
				values[i] = ffi.cast(attr[3], attrs[attr[1]])
				i = i + 1
			end
		end

		xcb.xcb_change_gc(conn, gc, mask, values)
	end
end

function x11.flush()
	xcb.xcb_flush(conn)
end

function x11.sync()
	xcb_util.xcb_aux_sync(conn)
end

local event_types = {
	error = {'error', 'xcb_generic_error_t*'};
	CreateNotify = {'create_notify'};
	MapRequest = {'map_request'};
	DestroyNotify = {'destroy_notify'};
	ReparentNotify = {'reparent_notify'};
	MapNotify = {'map_notify'};
	UnmapNotify = {'unmap_notify'};
	ConfigureNotify = {'configure_notify'};
	Expose = {'expose'};
	DestroyNotify = {'destroy_notify'};
}

local handlers = {}

function x11.on(name, fn)
	local handlers_ = handlers[name]
	if not handlers_ then
		handlers_ = {}
		handlers[name] = handlers_
	end
	handlers_[#handlers_ + 1] = fn
end

x11.on('error', function(ev)
	io.stderr:write(string.format(
		'X error: request=%s error=%s\n',
		ffi.string(x11.xcb_util.xcb_event_get_request_label(ev.major_code)),
		ffi.string(x11.xcb_util.xcb_event_get_error_label(ev.error_code))
	))
end)

local function emit(name, ...)
	local handlers_ = handlers[name]
	if not handlers_ then return end

	for _, handler in ipairs(handlers_) do
		handler(...)
	end
end

-- this triggers the loop when there's data on the xcb fd
local xcb_poll = uv.new_poll(xcb.xcb_get_file_descriptor(conn))
uv.poll_start(xcb_poll, 'r', function(err, events)
	if err then
		error(err)
	end
end)

x11.tick_tasks[#x11.tick_tasks + 1] = {'x11 poll', function()
	print('poll')
	x11.flush()

	local unmaps = {}
	local reparents = {}
	local maps = {}
	
	while true do
		local ev = xcb.xcb_poll_for_event(conn)
		if ev == nil then break end

		local typ = ffi.string(xcb_util.xcb_event_get_label(bit.band(ev.response_type, bit.bnot(0x80))))

		local name = event_types[typ]

		if name then
			ev = ffi.cast(name[2] or ('xcb_' .. name[1] .. '_event_t*'), ev)
			-- print('  known event: ' .. tostring(typ) .. ' (' .. tostring(ev.response_type) .. ')')
			emit(name[1], ev)
		else
			print('unknown event: ' .. tostring(typ) .. ' (' .. tostring(ev.response_type) .. ')')
		end
	end

	x11.flush()
end}

do
	local state
	local function reset()
		state = setmetatable({}, { __index = function(t, k)
			local v = {
				state = nil;
				last_ev = nil;
			}

			t[k] = v

			return v
		end })
	end
	reset()

	local events = {}

	x11.on('map_notify', function(ev)
		local st = state[ev.window]
		if st.state == 'reparent_unmap' then
			local unmap_i
			for i, ev in ipairs(events) do
				if ev[2] == st.unmap_ev then
					unmap_i = i
				end
			end
			if unmap_i then
				table.remove(events, unmap_i)
			end
		end
		if st.state ~= 'map' and st.state ~= 'reparent_unmap' then
			table.insert(events, {'map_notify', ev})
			st.last_ev = ev
			st.map_ev = ev
		end
		st.state = 'map'
	end)

	x11.on('reparent_notify', function(ev)
		local st = state[ev.window]
		if st.state ~= 'reparent' and st.state ~= 'reparent_unmap' then
			table.insert(events, {'reparent_notify', ev})
			st.last_ev = ev
			st.repar_ev = ev

		-- now we know the state is reparent or reparent_unmap
		-- therefore we need to check if it's the same parameters
		elseif ev.parent ~= st.last_ev.parent or ev.x ~= st.last_ev.x or ev.y ~= st.last_ev.y or ev.override_redirect ~= st.last_ev.override_redirect then
			table.insert(events, {'reparent_notify', ev})
			st.last_ev = ev
			st.repar_ev = ev
			st.state = 'reparent'
		end
		if st.state == 'unmap' then
			st.state = 'reparent_unmap'
		elseif st.state ~= 'reparent_unmap' then
			st.state = 'reparent'
		end
	end)

	x11.on('unmap_notify', function(ev)
		local st = state[ev.window]
		if st.state ~= 'unmap' then
			table.insert(events, {'unmap_notify', ev})
			st.last_ev = ev
			st.unmap_ev = ev
		end
		st.state = 'unmap'
	end)

	x11.tick_tasks[#x11.tick_tasks + 1] = {'x11 smooth reparent', function()
		for _, ev in ipairs(events) do
			emit('smooth:' .. ev[1], ev[2])
		end
		reset()
		events = {}
	end}
end

-- this runs every time before waiting
local xcb_prepare = uv.new_prepare()
uv.prepare_start(xcb_prepare, function()
	for _, task in ipairs(x11.tick_tasks) do
		task[2]()
	end
end)

return x11
