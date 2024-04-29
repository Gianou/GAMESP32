#ifndef Paddle_Right_H
#define Paddle_Right_H

#include "../game_engine/AbstractGameObject.h"
#include "../managers/InputManager.h"
#include "../../config/Constants.h"

class PaddleRight : public AbstractGameObject
{
public:
    PaddleRight(int x, int y, int width, int height, int speed);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    RigidBody *getRigidBody() override { return rigidBody; };

private:
    int x;
    int y;
    int width;
    int height;
    int speed;

    RigidBody *rigidBody;
};
#endif