local ffi = require 'ffi'
local pl = require 'pl.import_into' ()
local uv = require 'luv'

local x = {}

-- Load xcb
local xcb, xcb_randr, xcb_xinerama
do
	local h = io.open('xcb.h', 'r')
	local d = h:read '*a'
	h:close()
	ffi.cdef(d)

	xcb = ffi.load 'xcb'
	xcb_randr = ffi.load 'xcb-randr'
	xcb_xinerama = ffi.load 'xcb-xinerama'
	xcb_util = ffi.load 'xcb-util'

	x.xcb = xcb
	x.xcb_randr = xcb_randr
	x.xcb_xinerama = xcb_xinerama
	x.xcb_util = xcb_util
end

-- Connect
local con, setup, screen
do
	local scrid = ffi.new('int[1]', 1)
	con = xcb.xcb_connect(nil, scrid)
	setup = xcb.xcb_get_setup(con)
	screen = xcb_util.xcb_aux_get_screen(con, scrid[0])
end
-- TODO
x.conn = con
x.setup = setup
x.screen = screen

-- Load atoms
local A
do
	A = {}
	for _, atom in ipairs({
		'_NET_WM_NAME';
	}) do
		A[atom] = xcb.xcb_intern_atom(con, 0, #atom, atom)
	end
	for name, req in pairs(A) do
		A[name] = xcb.xcb_intern_atom_reply(con, req, nil).atom
	end
end
x.A = A

function x.randr_outputs()
	local res = xcb_randr.xcb_randr_get_screen_resources_current_reply(con, xcb_randr.xcb_randr_get_screen_resources_current(con, screen.root), nil)

	local ptr = xcb_randr.xcb_randr_get_screen_resources_current_outputs(res)
	return pl.seq(pl.tablex.range(0, xcb_randr.xcb_randr_get_screen_resources_current_outputs_length(res)))
		:map(function(i)
			return xcb_randr.xcb_randr_get_output_info(con, ptr[i], res.config_timestamp)
		end)
		:map(function(cookie)
			return xcb_randr.xcb_randr_get_output_info_reply(con, cookie, nil)
		end)
		:filter(function(info)
			return info ~= nil and info.crtc ~= nil
		end)
		:map(function(info)
			return {
				info = info;
				crtc = xcb_randr.xcb_randr_get_crtc_info(con, info.crtc, res.config_timestamp);
			}
		end)
		:map(function(ctx)
			return {
				info = ctx.info;
				crtc = xcb_randr.xcb_randr_get_crtc_info_reply(con, ctx.crtc, nil);
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

function x.xinerama_screens()
	local err = ffi.new('xcb_generic_error_t*[1]', nil)
	local reply = xcb_xinerama.xcb_xinerama_query_screens_reply(con, xcb_xinerama.xcb_xinerama_query_screens(con), err)
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

local handlers = {}
x.handlers = handlers

return x
