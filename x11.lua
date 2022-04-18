local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local xtend = require './xtend'

local x11 = {}
x11.tick_tasks = {}

-- print('loading x11', i(require))

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
	print(conn, scrid[0], screen)
end
-- TODO
x11.conn = conn
x11.setup = setup
x11.screen = screen

-- Atoms
do
	x11.A = {
		NONE = 0;
		ANY = 0;
		PRIMARY = 1;
		SECONDARY = 2;
		ARC = 3;
		ATOM = 4;
		BITMAP = 5;
		CARDINAL = 6;
		COLORMAP = 7;
		CURSOR = 8;
		CUT_BUFFER0 = 9;
		CUT_BUFFER1 = 10;
		CUT_BUFFER2 = 11;
		CUT_BUFFER3 = 12;
		CUT_BUFFER4 = 13;
		CUT_BUFFER5 = 14;
		CUT_BUFFER6 = 15;
		CUT_BUFFER7 = 16;
		DRAWABLE = 17;
		FONT = 18;
		INTEGER = 19;
		PIXMAP = 20;
		POINT = 21;
		RECTANGLE = 22;
		RESOURCE_MANAGER = 23;
		RGB_COLOR_MAP = 24;
		RGB_BEST_MAP = 25;
		RGB_BLUE_MAP = 26;
		RGB_DEFAULT_MAP = 27;
		RGB_GRAY_MAP = 28;
		RGB_GREEN_MAP = 29;
		RGB_RED_MAP = 30;
		STRING = 31;
		VISUALID = 32;
		WINDOW = 33;
		WM_COMMAND = 34;
		WM_HINTS = 35;
		WM_CLIENT_MACHINE = 36;
		WM_ICON_NAME = 37;
		WM_ICON_SIZE = 38;
		WM_NAME = 39;
		WM_NORMAL_HINTS = 40;
		WM_SIZE_HINTS = 41;
		WM_ZOOM_HINTS = 42;
		MIN_SPACE = 43;
		NORM_SPACE = 44;
		MAX_SPACE = 45;
		END_SPACE = 46;
		SUPERSCRIPT_X = 47;
		SUPERSCRIPT_Y = 48;
		SUBSCRIPT_X = 49;
		SUBSCRIPT_Y = 50;
		UNDERLINE_POSITION = 51;
		UNDERLINE_THICKNESS = 52;
		STRIKEOUT_ASCENT = 53;
		STRIKEOUT_DESCENT = 54;
		ITALIC_ANGLE = 55;
		X_HEIGHT = 56;
		QUAD_WIDTH = 57;
		WEIGHT = 58;
		POINT_SIZE = 59;
		RESOLUTION = 60;
		COPYRIGHT = 61;
		NOTICE = 62;
		FONT_NAME = 63;
		FAMILY_NAME = 64;
		FULL_NAME = 65;
		CAP_HEIGHT = 66;
		WM_CLASS = 67;
		WM_TRANSIENT_FOR = 68;
	}
	for name, atom in pairs(x11.A) do
		x11.A[atom] = name
	end
	x11.A[0] = nil
	
	setmetatable(x11.A, { __index = function(_, arg)
		if type(arg) == 'string' then
			local name = arg
			name = name:upper()
			local atom = rawget(x11.A, name)
			if atom then
				return atom
			end
			p('interning atom', name)
			atom = xcb.xcb_intern_atom_reply(conn, xcb.xcb_intern_atom(conn, 0, #name, name), nil).atom
			x11.A[name] = atom
			x11.A[atom] = name
			return atom
		elseif type(arg) == 'number' then
			local atom = arg
			if atom == 0 then
				return nil
			end
			p('getting atom name', atom)
			local reply = xcb.xcb_get_atom_name_reply(conn, xcb.xcb_get_atom_name(conn, atom), nil)
			local name = ffi.string(
				xcb.xcb_get_atom_name_name(reply),
				xcb.xcb_get_atom_name_name_length(reply)
			)
			p('name', name)
			x11.A[name] = atom
			x11.A[atom] = name
			return name
		else
			error('bad atom type: ' .. type(atom))
		end
	end })

	for _, name in ipairs {
			'_NET_WM_NAME';
	} do
		local _ = x11.A[name]
	end
end

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
	if reply == nil then
		x11.error(err[1])
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

-- graphics context
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
	FocusIn = {'focus_in'};
	ButtonPress = {'button_press'};
	PropertyNotify = {'property_notify'};
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

function x11.error(err)
	io.stderr:write(string.format(
		'X error: request=%s error=%s\n',
		ffi.string(x11.xcb_util.xcb_event_get_request_label(err.major_code)),
		ffi.string(x11.xcb_util.xcb_event_get_error_label(err.error_code))
	))
end
x11.on('error', function(ev)
	x11.error(ev)
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
	x11.time = xcb.XCB_TIME_CURRENT_TIME
	p('poll')
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
			p('  known event: ' .. tostring(typ) .. ' (' .. tostring(ev.response_type) .. ')')
			emit(name[1], ev)
		else
			p('unknown event: ' .. tostring(typ) .. ' (' .. tostring(ev.response_type) .. ')')
		end
	end

	x11.flush()
end}

for _, name in ipairs({
	'key_press';
	'button_press';
	'motion_notify';
	'enter_notify';
	'property_notify';
	'selection_clear';
	'selection_request';
	'selection_notify';
}) do
	x11.on(name, function(ev)
		x11.time = ev.time
	end)
end

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

do
	local out_buffer = {}

	local job_types = {}

	local function buffer(name, typ, opts)
		if not job_types[typ] then
			error('unknown job type: ' .. tostring(typ))
		end
		p('buffer', name)
		out_buffer[name] = xtend({
			name = name;
			typ = typ;
			opts = opts;
			wait_for = {};
		}, job_types[typ](name, opts))
	end

	-- General window
	do
		-- Job Type
		do
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

			function job_types.win(name, opts)
				local old = out_buffer[name]
				if old then
					old = old.opts
				else
					old = {}
				end
				opts = xtend.deep(old, opts)
				local win = opts.win
				local job = {
					fn = function()
						if opts.destroy then
							xcb.xcb_destroy_window(conn, win)
							return
						end

						if opts.map == false then
							xcb.xcb_unmap_window(conn, win)
						end
						if opts.reparent then
							local repar = opts.reparent
							xcb.xcb_reparent_window(conn, win, repar.parent, repar.x, repar.y)
						end
						if opts.map == true then
							xcb.xcb_map_window(conn, win)
						end
						if opts.attributes then
							local attrs = opts.attributes
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
						if opts.configure then
							local configs = opts.configure
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
					end;
					wait_for = {};
					opts = opts;
				}
				if opts.reparent then
					job.wait_for['win:' .. opts.reparent.parent] = true
				end
				return job
			end
		end

		function x11.map(win)
			buffer('win:' .. win, 'win', {
				win = win;
				map = true;
			})
		end

		function x11.unmap(win)
			buffer('win:' .. win, 'win', {
				win = win;
				map = false;
			})
		end

		function x11.reparent(win, parent, x, y)
			buffer('win:' .. win, 'win', {
				win = win;
				reparent = {
					parent = parent;
					x = x or 0;
					y = y or 0;
				};
			})
		end

		function x11.configure_window(win, opts)
			buffer('win:' .. win, 'win', {
				win = win;
				configure = opts;
			})
		end

		function x11.move(win, x, y, width, height)
			-- TODO: remove
			x11.configure_window(win, {
				x = x; y = y;
				width = width; height = height;
			})
		end

		function x11.change_window_attributes(win, attrs)
			buffer('win:' .. win, 'win', {
				win = win;
				attributes = attrs;
			})
		end

		function x11.destroy_window(win)
			buffer('win:' .. win, 'win', {
				win = win;
				destroy = true;
			})
		end

		function x11.get_window_attributes(win)
			x11.flush_buffer({'win:' .. win})
			local cookie = xcb.xcb_get_window_attributes_unchecked(conn, win)
			return function()
				local reply = xcb.xcb_get_window_attributes_reply(conn, cookie, nil)
				return reply
			end
		end

		function x11.get_geometry(win)
			x11.flush_buffer({'win:' .. win})
			local cookie = xcb.xcb_get_geometry_unchecked(conn, win)
			return function()
				local reply = xcb.xcb_get_geometry_reply(conn, cookie, nil)
				return reply
			end
		end
	end

	-- Window Properties
	do
		-- TODO: x11.set_property
		function x11.get_property(win, prop, length)
			x11.flush_buffer({'win:' .. win .. ':property:' .. x11.A[prop]})
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

	-- Input Focus
	do
		function job_types.focus(name, opts)
			local old = out_buffer[name]
			if old then
				old = old.opts
			else
				old = {}
			end
			opts = xtend.deep(old, opts)
			return {
				fn = function()
					xcb.xcb_set_input_focus(conn, opts.revert_to, opts.win, x11.time or xcb.XCB_TIME_CURRENT_TIME)
				end;
				wait_for = { ['win:' .. opts.win] = true; };
				opts = opts;
			}
		end

		function x11.focus(win, revert_to)
			buffer('focus', 'focus', {
				win = win;
				revert_to = revert_to or xcb.XCB_INPUT_FOCUS_NONE;
			})
		end
	end

	local waits = {}
	function x11.wait(name, wait_for)
		local wait = waits[name]
		if not wait then
			wait = {}
			waits[name] = wait
		end
		wait[wait_for] = {}
	end

	function x11.flush_buffer(ord)
		p('flush', ord and table.concat(ord, ', ') or '*')
		if not ord then
			ord = {}
			for win, out in pairs(out_buffer) do
				ord[#ord + 1] = win
			end
		end
		while #ord > 0 do
			repeat
				local win = table.remove(ord, 1)

				local out = out_buffer[win]

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
					local wait = waits[win]
					if wait then
						for dep in pairs(wait) do
							if rawget(out_buffer, dep) then
								ord[#ord + 1] = dep
								stop = true
							end
						end
					end
					if stop then
						ord[#ord + 1] = win
						break
					end
				end

				out.fn()

				out_buffer[win] = nil
				waits[win] = nil
			until true
		end
		x11.flush()
	end

	table.insert(x11.tick_tasks, 1, {'x11 out_buffer output pre', function()
		x11.flush_buffer()
	end})

	table.insert(x11.tick_tasks, {'x11 out_buffer output post', function()
		x11.flush_buffer()
	end})
end

return x11
