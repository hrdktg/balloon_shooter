FLAGS=-std=c++11 -I/usr/include/SDL2 -Iinclude/ -lSDL2
CXXFLAGS=$(CPPFLAGS)
LDFLAGS=
LDLIBS=

all:
	g++ src/hello.cpp src/game.cpp -o bin/hello $(FLAGS)

clean:
	rm bin/hello
