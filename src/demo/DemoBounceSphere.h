#ifndef DEMO_BOUNCE_SPHERE_H
#define DEMO_BOUNCE_SPHERE_H

#include "../game_engine/AbstractGameObject.h"

class DemoBounceSphere : public AbstractGameObject
{
public:
    DemoBounceSphere(int radius, int initialX, int initialY, int speedX, int speedY, int screenWidth, int screenHeight);
    void update() override;
    void render(TFT_eSprite &sprite) override;

private:
    int radius;
    int x;
    int y;
    int speedX;
    int speedY;
    int screenWidth;
    int screenHeight;
};

#endif
