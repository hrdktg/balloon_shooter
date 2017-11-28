#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game {
	public:
		bool init(const char* title);
		void handleEvents();
		void update();
		void render();
		void clean();

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
	private:
		static Game* pInstance;
		Game() {}
		//Resolution of display
		const int SCR_W=640;
		const int SCR_H=480;
		bool isRunning;

		int curCol;

		SDL_Window* window=0;
		SDL_Renderer* renderer=0;

		vector<SDLGameObject*> m_gameObj;

};

