#include "Food.h"

Food::Food(int x, int y, int size) : x(x), y(y), size(size)
{
    initialX = x;
    initialY = y;
    hitBox = new HitBox(x, y, size, size);
}

void Food::update()
{
}

void Food::render(Adafruit_SSD1325 &display)
{
    display.fillRect(x, y, size, size, WHITE);
}

void Food::respawn(int newX, int newY)
{
    // Respawn food at a random position within screen bounds
    x = newX;
    y = newY;
    hitBox->setX(x);
    hitBox->setY(y);
}

void Food::reset()
{
    x = initialX;
    y = initialY;
    hitBox->setX(x);
    hitBox->setY(y);
}
