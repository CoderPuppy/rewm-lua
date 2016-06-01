.PHONY: all

all: xcb.h

xcb.h: xcb.pre.h
	cpp $< | ag -v '^#' | sed 's/\([0-9]\+\)L/\1/g' > $@
