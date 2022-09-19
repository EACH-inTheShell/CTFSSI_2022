.PHONY: all

all: packed

packed: unpacked
	rm -f $@
	upx --best -o $@ $<

unpacked: main.c
	gcc --static -o $@ $<
