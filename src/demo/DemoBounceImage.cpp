#include "DemoBounceImage.h"
#include "RainbowSquare.h"

DemoBounceImage::DemoBounceImage(int width, int height, int initialX, int initialY, int speedX, int speedY, int screenWidth, int screenHeight)
    : width(width), height(height), x(initialX), y(initialY), speedX(speedX), speedY(speedY), screenWidth(screenWidth), screenHeight(screenHeight)
{
}

void DemoBounceImage::update()
{
    // Update position based on speed
    x += speedX;
    y += speedY;

    // Check bounds and bounce if necessary
    if (x - width < 0 || x + width > screenWidth)
    {
        speedX = -speedX;
    }
    if (y - height < 0 || y + height > screenHeight)
    {
        speedY = -speedY;
    }
}

void DemoBounceImage::render(TFT_eSprite &sprite)
{
    // Draw the sphere
    sprite.pushImage(x, y, width, height, RainbowSquare);
}
