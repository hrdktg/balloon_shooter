#include "Player.h"

Player::Player(const LoaderParams* param): SDLGameObject(param)
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_x-=1;
	m_col=int((SDL_GetTicks()/100) % 6);
}

void Player::clean()
{
}

