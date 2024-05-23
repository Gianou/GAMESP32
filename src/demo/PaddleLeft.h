#ifndef Paddle_Left_H
#define Paddle_Left_H

#include "../game_engine/AbstractGameObject.h"
#include "../managers/InputManager.h"
#include "../../config/Constants.h"

class PaddleLeft : public AbstractGameObject
{
public:
    PaddleLeft(int x, int y, int width, int height, int speed);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

    HitBox *getHitBox() override { return hitBox; };

private:
    int x;
    int y;
    int width;
    int height;
    int speed;

    HitBox *hitBox;
};
#endif