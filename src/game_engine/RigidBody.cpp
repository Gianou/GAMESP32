#include "RigidBody.h"

RigidBody::RigidBody(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height)
{
}

void RigidBody::setX(int newX)
{
    x = newX;
}

void RigidBody::setY(int newY)
{
    y = newY;
}