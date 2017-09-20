#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "TextureManager.h"
using namespace std;

class Game {
	private:
	//Resolution of display
	const int SCR_W=640;
	const int SCR_H=480;
	bool isRunning;

	int curCol;

	SDL_Window* window=0;
	SDL_Renderer* renderer=0;
	
	public:
	Game() 
	{
		cout<<"Loading\n";
       	}
	~Game()
	{
		cout<<"Bye\n";
       	}

	bool init(const char* title);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
};

