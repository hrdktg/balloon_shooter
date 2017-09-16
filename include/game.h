#include <SDL.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Game {
	private:
	//Resolution of display
	const int SCR_W=640;
	const int SCR_H=480;
	bool isRunning;

	SDL_Window* ptr_window=0;
	SDL_Renderer* ptr_renderer=0;

	public:
	Game() 
	{
		cout<<"Nothing\n";
       	}
	~Game()
	{
		cout<<"Nothing2\n";
       	}

	bool init(const char* title);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
};

