#include "SDLGameObject.h"
#include "TextureManager.h"
#include "game.h"

SDLGameObject::SDLGameObject(const LoaderParams* param)
{
    m_x=param->getX();
    m_y=param->getY();
    m_w=param->getW();
    m_h=param->getH();

    m_textureID=param->getTextureID();

    m_row=1;
    m_col=1;
}

void SDLGameObject::draw()
{
    TextureManager::getInstance()->drawSprite(m_textureID, m_x, m_y, m_w, m_h, m_row, m_col,Game::getInstance()->getRenderer());
}

void SDLGameObject::update() 
{
    if(m_textureID=="animate")
    {
        m_col = m_w * int((SDL_GetTicks()/100) % 6);
    }
}

void SDLGameObject::clean()
{
}