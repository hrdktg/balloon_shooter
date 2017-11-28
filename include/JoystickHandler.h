#ifndef JOYSTICKHANDLER_H_
#define JOYSTICKHANDLER_H_
#include <vector>
#include "Vector2d.h"
#include <SDL.h>
#include <map>
#include <SDL.h>
/*
class Joystickhandler
{
    private:
        int btnMap[13];
        bool m_isJoyConnected;
        
        //Contains a list of all connected joysticks
        std::vector<SDL_Joystick*>m_joy;

        std::vector<std::vector<int> >m_joyVal;        

    public:
        Joystickhandler() : m_isJoyConnected(false) {}
        void init();
        void clean();
        void update();
        bool isConnected();
};

#endif
*/
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