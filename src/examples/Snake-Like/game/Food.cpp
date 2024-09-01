#include "Food.h"

Food::Food(int x, int y, int size) : x(x), y(y), size(size)
{
    hitBox = new HitBox(x, y, size, size);
}

void Food::update()
{
}

void Food::render(Adafruit_SSD1325 &display)
{
    display.fillRect(x, y, size, size, WHITE);
}

void Food::respawn()
{
    // Respawn food at a random position within screen bounds
    x = random(0, SCREEN_WIDTH / size) * size;
    y = random(0, SCREEN_HEIGHT / size) * size;
    hitBox->setX(x);
    hitBox->setY(y);
}
