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

	TextureManager* Instance=TextureManager::getInstance();
	Instance->load("res/strip.png","animate",renderer);

	SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	SDL_RenderClear(renderer);
	    
	//m_go.load("animate",0,0,256,256);
	//m_player.load("animate",256,256,256,256);
	m_gameObj.push_back(new Player(new LoaderParams(0,0,256,256,"animate")));
	m_gameObj.push_back(new Enemy(new LoaderParams(256,256,256,256,"animate")));
	
return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//TextureManager::getInstance()->drawSprite("animate",0,0,256,256,1,curCol,renderer);
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
	for(vector<SDLGameObject*>::size_type i=0;i!=m_gameObj.size();i++)
	{
		m_gameObj[i]->update();
	}
	curCol=int(((SDL_GetTicks()/60)%6));
}
