#include "HitBox.h"

HitBox::HitBox(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height)
{
}

void HitBox::setX(int newX)
{
    x = newX;
}

void HitBox::setY(int newY)
{
    y = newY;
}