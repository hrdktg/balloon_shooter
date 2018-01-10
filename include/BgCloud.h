#include "SDLGameObject.h"

class BgCloud: public SDLGameObject
{		
	public:
		BgCloud(const LoaderParams* param) : SDLGameObject(param) { }

		virtual void draw();
		virtual void update();
		//virtual void clean();
};