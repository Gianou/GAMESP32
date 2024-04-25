#ifndef Bounce_Sphere_H
#define Bounce_Sphere_H

#include "../game_engine/AbstractGameObject.h"
#include "../../config/Constants.h"

class BounceSphere : public AbstractGameObject
{
public:
    BounceSphere(int radius, int initialX, int initialY, int speedX, int speedY);
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
