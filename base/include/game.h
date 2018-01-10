#ifndef GAME_H_
#define GAME_H_
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

using namespace std;

class Game {
	public:
		bool init(const char* title);
		void handleEvents();
		void update();
		void render();
		void clean();
		void quit();

		bool running() { return isRunning; }

		static Game* getInstance()
		{
			if(pInstance==nullptr)
			{
				pInstance=new Game();
			}
			return pInstance;
		}

		SDL_Renderer* getRenderer() const { return renderer; }
		int getSCRW();
		int getSCRH();

	private:
		static Game* pInstance;
		Game() {}
		
		//Resolution of display
		int SCR_W=384*1;
		int SCR_H=216;
		
		bool isRunning;

		int curCol;

		SDL_Window* window=0;
		SDL_Renderer* renderer=0;

		vector<SDLGameObject*> m_gameObj;
		void gameInit();
		void gameLoop();
};

#endif