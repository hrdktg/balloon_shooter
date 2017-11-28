#include "InputHandler.h"
#include <SDL.h>
#include "game.h"

InputHandler* InputHandler::pInstance=0;

void InputHandler::handleEvents()
{
    //if(hJoy.isConnected()) hJoy.update();
    
    SDL_Event evt;
    while(SDL_PollEvent(&evt))
    {
        switch(evt.type)
        {
            case SDL_QUIT:
                Game::getInstance()->quit();
                break;
            
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEMOTION:
                hMouse.handleEvt(evt);
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                hKey.handleEvt(evt);
                break;
            default:
                break;
        }
    }

}

vector2d InputHandler::getPos()
{
    return vector2d(hMouse.getX(),hMouse.getY());
}

void InputHandler::init()
{
    
}
