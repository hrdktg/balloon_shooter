#include "game.h"

Game* Game::pInstance=0;

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

	InputHandler::getInstance()->init();
	SDL_RenderClear(renderer);

	gameInit();
return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	for(vector<SDLGameObject*>::size_type i=0;i!=m_gameObj.size();i++)
	{
		m_gameObj[i]->draw();
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
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
	InputHandler::getInstance()->handleEvents();
}

void Game::update()
{
	gameLoop();
	for(vector<SDLGameObject*>::size_type i=0;i!=m_gameObj.size();i++)
	{
		m_gameObj[i]->update();
	}
}

void Game::quit()
{
	isRunning=false;
}

int Game::getSCRH()
{
	return SCR_H;
}

int Game::getSCRW()
{
	return SCR_W;
}