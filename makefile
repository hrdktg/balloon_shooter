FLAGS = -std=c++11 -I/usr/include/SDL2 -Iinclude/ -Isrc/ -lSDL2 -lSDL2_image
SRCDIR = src/*.cpp
SRCFILES = include/InputHandler.h include/JoystickHandler.h
CXXFLAGS = $(CPPFLAGS)
LDFLAGS =
LDLIBS =

SRC = $(SRCDIR) $(SRCFILES)

all:
	g++ $(SRC) -o bin/hello $(FLAGS)

clean:
	rm bin/hello
