#ifndef Abstract_Game_Object_H
#define Abstract_Game_Object_H

// #include "TFT_eSPI.h"
#include <Adafruit_SSD1325.h>
#include <Adafruit_GFX.h>

#include "RigidBody.h"

class AbstractGameObject
{
public:
    virtual void update();
    virtual void render(Adafruit_SSD1325 &display);

    virtual RigidBody *getRigidBody() { return nullptr; };

private:
};
#endif