#include "BgCloud.h"
#include "game.h"

void BgCloud::update()
{
    if(m_x%2==0) m_x-=1; else m_x-=12;
    if(!isScaled)
    {
        if(m_w+m_x<=0)
        {
            m_x=Game::getInstance()->getSCRW()+m_w;
        }
    }
    else
    {
        if(m_dw+m_x<=0)
        {   
            m_x+=1;
            m_x=Game::getInstance()->getSCRW()+m_dw;
        }
    }

}

void BgCloud::draw()
{
  
    TextureManager::getInstance()->draw(m_textureID,m_x,m_y,m_w,m_h, Game::getInstance()->getRenderer());
  
}
