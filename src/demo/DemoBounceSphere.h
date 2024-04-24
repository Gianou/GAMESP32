#ifndef DEMO_BOUNCE_SPHERE_H
#define DEMO_BOUNCE_SPHERE_H

#include "../game_engine/AbstractGameObject.h"
#include "../../config/Constants.h"

class DemoBounceSphere : public AbstractGameObject
{
public:
    DemoBounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    // private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;
};

#endif
