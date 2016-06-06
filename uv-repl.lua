local uv = require 'luv'
local repl = require 'repl' :clone()

local history = ''

local work = uv.new_work(
	function(prompt, history)
		local ln = require 'linenoise'
		for line in history:gmatch '([^\n]*)\n' do
			ln.historyadd(line)
		end
		return ln.linenoise(prompt .. ' ')
	end,
	function(line)
		if line then
			history = history .. line .. '\n'
			repl:prompt(repl:handleline(line))
		else
			p('C-c')
			for _, tile in pairs(tiles.cache) do
				if tile.type == 'clw' then
					x11.reparent(tile.clw.xwin, x11.screen.root)
					x11.flush_buffer()
					x11.xcb_util.xcb_aux_sync(x11.conn)
				end
			end
			uv.stop()
		end
	end
)

function repl:showprompt(prompt)
	uv.queue_work(work, prompt, history)
end

function repl:displayresults(results)
	if results.n == 0 then
		return
	end

	print(unpack(results, 1, results.n))
end

function repl:displayerror(err)
	print(err)
end

local ctx = repl:getcontext()
ctx.pl = require 'pl.import_into' ()
ctx.uv = uv
ctx.ffi = require 'ffi'
ctx.xtend = require 'xtend'
ctx.x11 = require 'x11'
ctx.clws, ctx.tiles = unpack(require 'windows')

repl:loadplugin 'autoreturn'
repl:loadplugin 'keep_last_eval'
repl:loadplugin 'semicolon_suppress_output'

repl:prompt(1)
