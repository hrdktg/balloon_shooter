#include "TextureManager.h"
#include "Vector2d.h"

TextureManager* TextureManager::pInstance=nullptr;

bool TextureManager::load(string fname,string id,SDL_Renderer* pRend)
{
	SDL_Surface* tpSurface = IMG_Load(fname.c_str());

	if(tpSurface==0) 
	{
		cout<<"Error loading:"<<fname<<"\n";
		return false;
	}

	SDL_Texture* tpTexture = SDL_CreateTextureFromSurface(pRend,tpSurface);

	SDL_FreeSurface(tpSurface);

	if(tpTexture!=0)
	{
		cout<<"Loaded:"<<fname<<"\n";
		m_textureMap[id]=tpTexture;
		return true;
	}

return false;
}

vector2d TextureManager::getDimension(std::string id)
{
	int m_w=0, m_h=0;
	if(m_textureMap[id]!=NULL)
		SDL_QueryTexture(m_textureMap[id], NULL, NULL, &m_w, &m_h);
	else
	{
		cout<<"Texture ID not mapped:"<<id<<"\n";
	}
	
	return vector2d(m_w,m_h);
}

void TextureManager::draw(std::string id,int x,int y,int w,int h,SDL_Renderer* pRend,SDL_RendererFlip flip)
{
	srcRect={0,0,w,h};
	destRect={x,y,w,h};
	
	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}

void TextureManager::draw(std::string id,SDL_Rect &srcR,SDL_Rect &destR,SDL_Renderer* pRend,SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcR,&destR,0,0,flip);
}
/*
void TextureManager::drawScaled(std::string id,int x,int y,int sw,int sh,int dw,int dh,SDL_Renderer* pRend,SDL_RendererFlip flip)
{
	srcRect={0,0,sw,sh};
	destRect={x,y,dw,dh};
	vector2d temp=TextureManager::getInstance()->getDimension(id);
	
	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}
*/

void TextureManager::drawSprite(std::string id, int x,int y,int w,int h,int curRow,int curCol,SDL_Renderer *pRend,SDL_RendererFlip flip)
{
	srcRect={curCol, curRow, w, h};
	destRect={x, y, w, h};

	SDL_RenderCopyEx(pRend,m_textureMap[id],&srcRect,&destRect,0,0,flip);
}
