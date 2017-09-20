#include "TextureManager.h"

/*
TextureManager* getInstance()
{
	if(pInstance==0)
	{
		pInstance=new TextureManager();
		return pInstance;
	}
	return pInstance;
}
*/
TextureManager* TextureManager::pInstance=nullptr;

bool TextureManager::load(string fname,string id,SDL_Renderer* pRend)
{
	SDL_Surface* tpSurface = IMG_Load(fname.c_str());

	if(tpSurface==0) return false;

	SDL_Texture* tpTexture = SDL_CreateTextureFromSurface(pRend,tpSurface);

	SDL_FreeSurface(tpSurface);

	if(tpTexture!=0)
	{
		m_textureMap[id]=tpTexture;
		return true;
	}

return false;
}

void TextureManager::draw(string id,int x,int y,int w,int h,SDL_Renderer* pRend,SDL_RendererFlip flip)
{
	SDL_Rect srcRect={0,0,w,h};
	SDL_Rect destRect={x,y,w,h};
	
	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}


void TextureManager::drawSprite(string id,int x,int y,int w,int h,int curRow,int curCol,SDL_Renderer *pRend,SDL_RendererFlip flip)
{
	SDL_Rect srcRect={256*curCol, curRow-1, w, h};
	SDL_Rect destRect={x, y, w, h};

	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}


