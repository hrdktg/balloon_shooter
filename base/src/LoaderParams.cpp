#include "LoaderParams.h"

LoaderParams::LoaderParams(std::string textureID, int x,int y,bool anim)
{
    isAnim=anim;
    isScaled=false;
	m_textureID=textureID;
	m_x=x; m_y=y;
	vector2d temp=TextureManager::getInstance()->getDimension(textureID);
	m_w=temp.getX();
	m_h=temp.getY();
}

LoaderParams::LoaderParams(std::string textureID, int x,int y,int sw,int sh,int dw,int dh)
{
    isScaled=true;
    m_textureID=textureID;
	m_x=x; m_y=y;
    m_w=sw; m_h=sh;
    m_dw=dw;
    m_dh=dh;
}

