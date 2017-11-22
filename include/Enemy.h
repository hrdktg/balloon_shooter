#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_
#include "SDLGameObject.h"
#endif

class Enemy: public SDLGameObject
{
	public:
		Enemy(const LoaderParams* param);

		virtual void draw();
		virtual void update();
		virtual void clean();
};

