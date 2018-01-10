FLAGS = -std=c++11 -I/usr/include/SDL2 -Ibase/include/ -Iinclude/ -Isrc/ -Ibase/src/ -lSDL2 -lSDL2_image
SRCDIR = base/src/*.cpp src/*.cpp
SRCFILES = 
CXXFLAGS = $(CPPFLAGS)
LDFLAGS =
LDLIBS =

SRC = $(SRCDIR) $(SRCFILES)

all:
	g++ $(SRC) -o bin/hello $(FLAGS)

clean:
	rm bin/hello
