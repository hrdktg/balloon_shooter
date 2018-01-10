#include "MouseHandler.h"
#include "Vector2d.h"
#include <iostream>

void MouseHandler::handleEvt(SDL_Event& evt)
{
    if(evt.type==SDL_MOUSEMOTION)
    {
        xpos=evt.motion.x;
        ypos=evt.motion.y;
    }
    else
    {
        bool isDown=false;
        if(evt.type==SDL_MOUSEBUTTONDOWN) isDown=true;

        switch(evt.button.button)
        {
            case SDL_BUTTON_LEFT:
                left=isDown;
                break;
            case SDL_BUTTON_MIDDLE:
                mid=isDown;
                break;
            case SDL_BUTTON_RIGHT:
                right=isDown;
                break;
        }
    }
}

bool MouseHandler::isPressedL()
{
    return left;
}

bool MouseHandler::isPressedM()
{
    return mid;
}

bool MouseHandler::isPressedR()
{
    return right;
}

int MouseHandler::getX()
{
    return xpos;
}

int MouseHandler::getY()
{
    return ypos;
}
