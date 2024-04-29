#ifndef Paddle_H
#define Paddle_H

#include "../game_engine/AbstractGameObject.h"
#include "../game_engine/AbstractRigidBody.h"
#include "../managers/InputManager.h"
#include "../../config/Constants.h"

class Paddle : public AbstractGameObject,
               public AbstractRigidBody
{
public:
    Paddle(int x, int y, int width, int height, int speed);
    void update() override;
    void render(TFT_eSprite &sprite) override;
    int getX() override { return x; }
    int getY() override { return y; }
    int getWidth() override { return width; }
    int getHeight() override { return height; }

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
};
#endif