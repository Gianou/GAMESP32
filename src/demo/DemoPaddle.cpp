#include "DemoPaddle.h"

DemoPaddle::DemoPaddle(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
}

void DemoPaddle::update()
{
    InputManager *inputManager = InputManager::getInstance();
    if (inputManager->getInputValue("Y axis") > 2000)
    {
        y += speed;
    }
    else if (inputManager->getInputValue("Y axis") < 1900)
    {
        y -= speed;
    }
}
void DemoPaddle::render(TFT_eSprite &sprite)
{
    sprite.fillRect(x, y, width, height, TFT_WHITE);
}