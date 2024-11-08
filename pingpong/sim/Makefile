VFLAGS = -O3 --x-assign fast --x-initial fast --noassert 
SDL_CFLAGS = `sdl2-config --cflags`
SDL_LDFLAGS = `sdl2-config --libs`


pingpong: pingpong.exe

%.exe: %.mk
	make -C ./obj_dir -f Vmain.mk

%.mk: main.sv
	verilator ${VFLAGS} -I.. -cc $< --exe main.cpp -o main -CFLAGS "${SDL_CFLAGS}" -LDFLAGS "${SDL_LDFLAGS}"

all: pong

clean:
	rm -rf ./obj_dir

.PHONY: all clean
