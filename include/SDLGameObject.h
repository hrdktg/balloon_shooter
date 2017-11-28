#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_
#include "GameObject.h"
#include <iostream>

class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const LoaderParams* param);

        virtual void draw();
        virtual void update();
        virtual void clean();

    protected:
        int m_x,m_y;
        int m_w,m_h;

        int m_row,m_col;
        
        std::string m_textureID;
};
#endif