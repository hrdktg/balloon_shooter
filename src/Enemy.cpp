#include "Enemy.h"

Enemy::Enemy(const LoaderParams* param): SDLGameObject(param)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_y+=1;
	m_x+=1;

	m_col=int(((SDL_GetTicks()/100)%6));
}

void Enemy::clean()
{
}