#ifndef Abstract_Game_Object_H
#define Abstract_Game_Object_H

#include "TFT_eSPI.h"

class AbstractGameObject
{
public:
    virtual void update();
    virtual void render(TFT_eSprite &sprite);

private:
};
#endif