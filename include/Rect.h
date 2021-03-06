#ifndef RECT_H
#define RECT_H

#include "include/Vec2.h"
#include <iostream>
#include <cmath>

class Rect
{
public:
    Rect();
    Rect(float x, float y, float w, float h);
    void Move(Vec2 v);
    Vec2 Center();
    float DistRect(Rect r1);
    bool IsIn(Vec2 v);

    float x;
    float y;
    float w;
    float h;
};

#endif // RECT_H
