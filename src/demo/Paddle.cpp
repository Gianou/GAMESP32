#include "Paddle.h"

Paddle::Paddle(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
}

void Paddle::update()
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
    // Check for screen boundaries
    if (y < 0)
    {
        y = 0;
    }
    if (y + height > SCREEN_HEIGHT)
    {
        y = SCREEN_HEIGHT - height;
    }
}

void Paddle::render(TFT_eSprite &sprite)
{
    sprite.fillRect(x, y, width, height, TFT_WHITE);
}
