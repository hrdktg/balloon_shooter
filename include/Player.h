#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_
#include "SDLGameObject.h"
#endif

class Player: public SDLGameObject
{
	public:
		Player(const LoaderParams* param);

		virtual void draw();
		virtual void update();
		virtual void clean();
};

