#include "PaddleRight.h"

PaddleRight::PaddleRight(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
    rigidBody = new RigidBody(x, y, width, height);
}

void PaddleRight::update()
{
    InputManager *inputManager = InputManager::getInstance();
    if (!inputManager->getInputValue("Button B"))
    {
        y += speed;
    }
    else if (!inputManager->getInputValue("Button A"))
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

    // Update rigidBody place
    rigidBody->setX(x);
    rigidBody->setY(y);
}

void PaddleRight::render(TFT_eSprite &sprite)
{
    sprite.fillRect(x, y, width, height, TFT_WHITE);
}
