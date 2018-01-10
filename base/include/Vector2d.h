#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class vector2d
{
    private:
        int x,y;
    public:
        vector2d() : x(0), y(0) {}
        vector2d(int vx,int vy) : x(vx), y(vy) {}
        int getX();
        int getY();
};

#endif