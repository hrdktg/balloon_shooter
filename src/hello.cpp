#include "game.h"
#include "InputHandler.h"

int main(int argc,char* args[])
{
	Game::getInstance()->init("Hello");

	while(Game::getInstance()->running())
	{
		//InputHandler::getInstance()->handleInputs();
		Game::getInstance()->handleEvents();
		Game::getInstance()->update();
		Game::getInstance()->render();
	}

	Game::getInstance()->clean();

return 0;
}
