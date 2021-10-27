CFLAGS = -g -O2 -std=c99

all: sperse_file hole_punching

sperse_file: sperse_file.c
	gcc $^ -o $@ $(CFLAGS)

hole_punching: hole_punching.c
	gcc $^ -o $@ $(CFLAGS)

.PHONY: clean

clean:
	$(RM) sperse_file /tmp/file.hole hole_punching /tmp/file_nohole /tmp/file_withhole
