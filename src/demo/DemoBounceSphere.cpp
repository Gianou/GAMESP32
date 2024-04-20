#include "DemoBounceSphere.h"

DemoBounceSphere::DemoBounceSphere(int radius, int initialX, int initialY, int speedX, int speedY, int screenWidth, int screenHeight)
    : radius(radius), x(initialX), y(initialY), speedX(speedX), speedY(speedY), screenWidth(screenWidth), screenHeight(screenHeight)
{
}

void DemoBounceSphere::update()
{
    // Update position based on speed
    x += speedX;
    y += speedY;

    // Check bounds and bounce if necessary
    if (x - radius < 0 || x + radius > screenWidth)
    {
        speedX = -speedX;
    }
    if (y - radius < 0 || y + radius > screenHeight)
    {
        speedY = -speedY;
    }
}

void DemoBounceSphere::render(TFT_eSprite &sprite)
{
    // Draw the sphere
    sprite.fillCircle(x, y, radius, TFT_WHITE);
}
