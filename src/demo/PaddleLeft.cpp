#include "PaddleLeft.h"

PaddleLeft::PaddleLeft(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
    rigidBody = new RigidBody(x, y, width, height);
}

void PaddleLeft::update()
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

    // Update rigidBody place
    rigidBody->setX(x);
    rigidBody->setY(y);
}

void PaddleLeft::render(Adafruit_SSD1325 &display)
{
    display.fillRect(x, y, width, height, WHITE);
}
