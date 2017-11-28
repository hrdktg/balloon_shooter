#include "SDLGameObject.h"

class Enemy: public SDLGameObject
{
	public:
		Enemy(const LoaderParams* param);

		virtual void draw();
		virtual void update();
		virtual void clean();
};

