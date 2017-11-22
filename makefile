FLAGS=-std=c++11 -I/usr/include/SDL2 -Iinclude/ -Isrc/ -lSDL2 -lSDL2_image
SRC=src/hello.cpp src/game.cpp src/TextureManager.cpp src/GameObject.cpp src/Player.cpp src/Enemy.cpp src/SDLGameObject.cpp include/LoaderParams.h
CXXFLAGS=$(CPPFLAGS)
LDFLAGS=
LDLIBS=

all:
	g++ $(SRC) -o bin/hello $(FLAGS)

clean:
	rm bin/hello
