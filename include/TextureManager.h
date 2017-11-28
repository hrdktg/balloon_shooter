#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include <string>
#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class TextureManager {
	private:
		static TextureManager* pInstance;
		TextureManager() {}
	public:
		
		static TextureManager* getInstance() 
		{
			if(pInstance==nullptr)
			{
				pInstance=new TextureManager();
			}
			return pInstance;
		}

		bool load(string fname,string id,SDL_Renderer* pRend);

		void draw(string id,int x,int y,int w,int h,SDL_Renderer* pRend,SDL_RendererFlip flip=SDL_FLIP_NONE);

		void drawSprite(string id,int x,int y,int w,int h,int curRow,int curFrame,SDL_Renderer* pRend,SDL_RendererFlip flip=SDL_FLIP_NONE);

		map<string, SDL_Texture*> m_textureMap;
		
};

#endif