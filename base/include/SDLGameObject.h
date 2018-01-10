#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_
#include "LoaderParams.h"
#include <iostream>

class SDLGameObject
{
    public:
        SDLGameObject(const LoaderParams* param);

        virtual void draw();
        virtual void update();
        virtual void clean();
        virtual void setVel(int aa,int bb);

    protected:
        int m_x,m_y;
        int m_w,m_h;
        int m_dw,m_dh;
        bool isAnim;
        bool isScaled;

        int m_row, m_col;
        std::string m_textureID;
};
#endif