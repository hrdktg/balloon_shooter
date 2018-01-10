#ifndef JOYSTICKHANDLER_H_
#define JOYSTICKHANDLER_H_
#include <vector>
#include "Vector2d.h"
#include <SDL.h>
#include <map>
#include <SDL.h>

class JoystickHandler
{
    private:
        bool m_isJoyConnected;
        std::map<int,SDL_GameController* > m_joy;
    public:
        JoystickHandler() : m_isJoyConnected(false) {}
        void clean();
        void update();
        bool isConnected();
        void addController(int jID);
        void removeController(int jID);
};

#endif