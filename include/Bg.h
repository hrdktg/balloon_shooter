#include "SDLGameObject.h"
#include "game.h"

class Bg: public SDLGameObject
{		
    private:
        int isWrapped=1;
        int scw, sch;
        int vx, vy;

	public:
		Bg(const LoaderParams* param) : SDLGameObject(param) 
        { 
            vx=0,vy=0;
            scw=Game::getInstance()->getSCRW();
            sch=Game::getInstance()->getSCRH();
        }

		virtual void draw();
		virtual void update();
        virtual void setVel(int v_x,int v_y);
		//virtual void clean();
};