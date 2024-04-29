#ifndef Abstract_Game_Object_H
#define Abstract_Game_Object_H

#include "TFT_eSPI.h"
#include "RigidBody.h"

class AbstractGameObject
{
public:
    virtual void update();
    virtual void render(TFT_eSprite &sprite);

    virtual RigidBody *getRigidBody() { return nullptr; };

private:
};
#endif