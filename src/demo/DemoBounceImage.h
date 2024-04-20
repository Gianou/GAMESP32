#ifndef DEMO_BOUNCE_IMAGE_H
#define DEMO_BOUNCE_IMAGE_H

#include "../game_engine/AbstractGameObject.h"

class DemoBounceImage : public AbstractGameObject
{
public:
    DemoBounceImage(int width, int height, int initialX, int initialY, int speedX, int speedY, int screenWidth, int screenHeight);
    void update() override;
    void render(TFT_eSprite &sprite) override;

private:
    int width;
    int height;
    int x;
    int y;
    int speedX;
    int speedY;
    int screenWidth;
    int screenHeight;
};

#endif
