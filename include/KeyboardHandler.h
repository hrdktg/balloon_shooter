#include <SDL.h>

class KeyboardHandler
{
    private:
        const Uint8* m_key;
    public:
        void handleEvt(SDL_Event &evt);
        bool isKeyDown(SDL_Scancode key);
};