#ifndef Demo_Paddle_H
#define Demo_Paddle_H

#include "../game_engine/AbstractGameObject.h"
#include "../managers/InputManager.h"

class DemoPaddle : public AbstractGameObject
{
public:
    DemoPaddle(int x, int y, int width, int height, int speed);
    void update() override;
    void render(TFT_eSprite &sprite) override;

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
};
#endif