#include "PaddleRight.h"

PaddleRight::PaddleRight(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
    hitBox = new HitBox(x, y, width, height);
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
    hitBox->setX(x);
    hitBox->setY(y);
}

void PaddleRight::render(Adafruit_SSD1325 &display)
{
    display.fillRect(x, y, width, height, WHITE);
}
