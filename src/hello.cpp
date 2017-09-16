#include "game.h"

using namespace std;


Game* ptr_game=0;

int main(int argc,char* args[])
{
	ptr_game=new Game();
	ptr_game->init("Hello");

	while(ptr_game->running())
	{
		ptr_game->handleEvents();
		ptr_game->update();
		ptr_game->render();
	}

	ptr_game->clean();

return 0;
}
