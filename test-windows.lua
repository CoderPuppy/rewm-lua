function clws.tile(xwin)
	local clw = {
		xwin = xwin;
	}

	local tile = {
		clw = clw;
	}
	clw.tile = tile

	-- create frame window
	-- reparent client window under frame window

	function clw.button_press(ev)
		-- allow events
		tiles.focus(tile)
	end

	function tile.focus()
		-- focus client window
	end

	return clw
end

function clws.tabbed()
	local tile = {
		children = {};
	}
	
	-- create window
	
	function tile.add(new)
		local i
		if tile.active then
			i = tile.children[tile.active]
		else
			i = tile.children.n
		end
		for j = i + 1, tile.children.n do
			tile.children[tile.children[j]] = j + 1
		end
		table.insert(tile.children, i, new)
		tile.children[new] = i + 1
		tile.children.n = tile.children.n + 1
		tile.activate(new)

		if tile.parent then
			x11.reparent(child.xwin, tile.xwin)
			child.move {
				parent = tile;
				x = 0;
				y = 18;
				width = tile.width;
				height = tile.height - 18;
			}
		end
	end

	function tile.activate(child)
		if tile.is_mapped then
			if tile.active then
				tile.active.off()
			end
		end
		tile.ative = child
		if tile.mapped then
		end
	end
end

function tiles.focus(tile)
	tiles.activate(tile)
	focused = tile
	tile.focus()
end

function tiles.activate(tile)
	tile.parent.activate(tile)
end
