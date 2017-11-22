#include <SDL.h>
#include <SDL_image.h>
#ifndef LOADERPARAMS_H_
#define LOADERPARAMS_H_
#include "LoaderParams.h"
#endif
using namespace std;


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
