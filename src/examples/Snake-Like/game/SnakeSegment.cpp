#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(int x, int y, int size) : x(x), y(y), size(size)
{
    hitBox = new HitBox(x, y, size, size);
}

void SnakeSegment::update()
{
    // Segments don’t update individually; the Snake class manages movement
    hitBox->setX(x);
    hitBox->setY(y);
}

void SnakeSegment::render(Adafruit_SSD1325 &display)
{
    display.fillRect(x, y, size, size, WHITE);
}

void SnakeSegment::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int SnakeSegment::getX()
{
    return x;
}

int SnakeSegment::getY()
{
    return y;
}
