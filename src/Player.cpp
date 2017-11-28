#include "Player.h"
#include <SDL.h>
#include "InputHandler.h"

Player::Player(const LoaderParams* param): SDLGameObject(param)
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::clean()
{
}

void Player::update()
{
    m_x+=1;
	m_col = m_w * int((SDL_GetTicks()/100) % 6);
}