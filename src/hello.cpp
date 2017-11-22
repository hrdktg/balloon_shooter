#include "game.h"

using namespace std;



int main(int argc,char* args[])
{
	Game::getInstance()->init("Hello");

	while(Game::getInstance()->running())
	{
		Game::getInstance()->handleEvents();
		Game::getInstance()->update();
		Game::getInstance()->render();
	}

	Game::getInstance()->clean();

return 0;
}
