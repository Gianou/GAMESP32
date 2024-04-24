#include "DemoBounceSphere.h"

DemoBounceSphere::DemoBounceSphere(int radius, int initialX, int initialY, int speedX, int speedY)
    : radius(radius), x(initialX), y(initialY), speedX(speedX), speedY(speedY)
{
}

void DemoBounceSphere::update()
{
    // Update position based on speed
    x += speedX;
    y += speedY;

    // Check bounds and bounce if necessary
    if (x - radius < 0 || x + radius > SCREEN_WIDTH)
    {
        speedX = -speedX;
    }
    if (y - radius < 0 || y + radius > SCREEN_HEIGHT)
    {
        speedY = -speedY;
    }
}

void DemoBounceSphere::render(TFT_eSprite &sprite)
{
    // Draw the sphere with 1 sprite per
    sprite.fillCircle(x, y, radius, TFT_WHITE);
}
