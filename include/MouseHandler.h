#include <SDL.h>
#include "Vector2d.h"

class MouseHandler {
    private:
        bool left,mid,right;
        int xpos,ypos;
    public:
        MouseHandler() : left(false), mid(false), right(false) {}
        void clean();
        void update();
        void handleEvt(SDL_Event& evt);
        bool isPressedL();
        bool isPressedM();
        bool isPressedR();
        int getX();
        int getY();
};