core.*: programa
	rm -f core.*
	env -i ./$< <<<"eits{4g0r4_c0m0_g3r4_um_c0r3_dump}"

programa: main.s
	gcc -o $@ -nostartfiles -nostdlib $<
	strip $@
