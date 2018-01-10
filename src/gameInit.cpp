#include "game.h"
#include "BgCloud.h"
#include "Bg.h"

void Game::gameInit()
{
    SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
    for(int i=0;i<5;i++)
    {
        std::string fname="bg"+to_string(i+1);
        TextureManager::getInstance()->load("res/"+fname+".png",fname,renderer);
        m_gameObj.push_back(new Bg(new LoaderParams(fname,0,0,384,216,384,216)));
        m_gameObj[m_gameObj.size()-1]->setVel(-1*i,0);
    }

    //TextureManager::getInstance()->load("res/cloud.png","cloud",renderer);

   // m_gameObj.push_back(new BgCloud(new LoaderParams("cloud",0,0,50,40,100,100)));
    //m_gameObj.push_back(new BgCloud(new LoaderParams("cloud",200,60,50,40)));
	//m_gameObj.push_back(new Player(new LoaderParams("animate",0,0,256,256)));
	//m_gameObj.push_back(new Enemy(new LoaderParams("animate",256,256,256,256)));
}