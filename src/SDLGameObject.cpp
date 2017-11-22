#include "SDLGameObject.h"
#define SDLGAMEOBJECT_H_

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
#include "TextureManager.h"
#endif

#ifndef GAME_H_
#define GAME_H_
#include "game.h"
#endif

SDLGameObject::SDLGameObject(const LoaderParams* param) : GameObject(param)
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
}

void SDLGameObject::clean()
{
}