#include "game.h"


bool Game::init(const char* title)
{
	if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
	{
		ptr_window=SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCR_W,SCR_H,SDL_WINDOW_SHOWN);

		if(ptr_window!=0)
		{
			ptr_renderer=SDL_CreateRenderer(ptr_window,-1,0);
		}
	}
	else
	{
		cout<<"Error\n";
		return false;
	}
//Draw Window
//Set to black
SDL_SetRenderDrawColor(ptr_renderer,0,0,0,255);
isRunning=true;
return true;
}

void Game::render()
{
	//Clear the window to show black color
	SDL_RenderClear(ptr_renderer);

	//Show the window
	SDL_RenderPresent(ptr_renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(ptr_window);
	SDL_DestroyRenderer(ptr_renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event evt;
	if(SDL_PollEvent(&evt))
	{
		switch(evt.type)
		{
			case SDL_QUIT:
				isRunning=false;
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
	cout<<"hur\n";
}
