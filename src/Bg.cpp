#include "Bg.h"
#include "game.h"

void Bg::update()
{
    m_x+=vx;
    if(abs(m_x)>=scw) m_x=0;
}

void Bg::draw()
{
    SDL_Rect srcR,destR;
    
    //Part2->
    srcR={0,0,abs(m_x),m_h};
    //cout<<"SRC:0,0,"<<abs(m_x)<<","<<m_h<<"\n";
    destR={scw-abs(m_x),0,abs(m_x),m_h};
    //cout<<"DES:"<<scw-abs(m_x)<<",0,"<<abs(m_x)<<","<<m_h<<"\n";
    TextureManager::getInstance()->draw(m_textureID,srcR,destR,Game::getInstance()->getRenderer());
    //TextureManager::getInstance()->draw(m_textureID,m_x,m_y,scw,sch, Game::getInstance()->getRenderer());

    //Part1->
    srcR={abs(m_x),0,scw-abs(m_x),m_h};
    destR={0,0,scw-abs(m_x),m_h};
    TextureManager::getInstance()->draw(m_textureID,srcR,destR,Game::getInstance()->getRenderer());
}

void Bg::setVel(int v_x,int v_y)
{
    vx=v_x;
    vy=v_y;
}

