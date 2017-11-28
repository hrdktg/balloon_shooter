#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "LoaderParams.h"
#include <SDL.h>
#include <SDL_image.h>

class GameObject
{
	public:

		virtual void draw()=0;
		virtual void update()=0;
		virtual void clean()=0;

	protected:
		GameObject(const LoaderParams* param) {}
		virtual ~GameObject() {}
};
#endif