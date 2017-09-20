#include "game.h"

bool Game::init(const char* title)
{
	IMG_Init(IMG_INIT_JPG);
	IMG_Init(IMG_INIT_PNG);
	if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
	{
		window=SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCR_W,SCR_H,SDL_WINDOW_SHOWN);

		if(window!=0)
		{
			renderer=SDL_CreateRenderer(window,-1,0);
		}
	}
	else
	{
		cout<<"Error\n";
		return false;
	}
	isRunning=true;

	TextureManager* Instance=TextureManager::getInstance();
	Instance->load("res/strip.png","animate",renderer);

	SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	SDL_RenderClear(renderer);
	    
return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//m_textureManager.draw("animate",0,0,256,256,renderer);
	TextureManager::getInstance()->drawSprite("animate",0,0,256,256,1,curCol,renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
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
	curCol=int(((SDL_GetTicks()/60)%6));
}
