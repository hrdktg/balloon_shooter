#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include "JoystickHandler.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"

class InputHandler : JoystickHandler, KeyboardHandler, MouseHandler {
    private:
        static InputHandler* pInstance;
        
        //JoystickHandler hJoy;
        KeyboardHandler hKey;
        MouseHandler hMouse; 

        InputHandler() {}
        ~InputHandler() {}
    public:
        static InputHandler* getInstance()
		{
			if(pInstance==nullptr)
			{
				pInstance=new InputHandler();
			}
			return pInstance;
		}

        void handleEvents();
        void init();  
        vector2d getPos();
        bool isKeyDown(SDL_Scancode k);
};

#endif