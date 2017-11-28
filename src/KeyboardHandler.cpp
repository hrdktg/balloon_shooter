#include "KeyboardHandler.h"
#include <iostream>

void KeyboardHandler::handleEvt(SDL_Event &evt) 
{
    m_key=SDL_GetKeyboardState(0);
}

bool KeyboardHandler::isKeyDown(SDL_Scancode key)
{
    if(m_key!=0)
    {
        if(m_key[key]==1)
        {
            return true;
        }
        else
            return false;
    }
    return false;
}