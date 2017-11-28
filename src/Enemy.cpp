#include "Enemy.h"
#include <SDL.h>
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* param): SDLGameObject(param)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
    m_x=InputHandler::getInstance()->getPos().getX();
    m_y=InputHandler::getInstance()->getPos().getY();
    
	m_col=m_w*int(((SDL_GetTicks()/100)%6));
}

void Enemy::clean()
{
}