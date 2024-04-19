#include "Display.h"

Display::Display() : tft(TFT_eSPI()), sprite(&tft)
{
}

void Display::begin()
{
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(6);
    tft.setCursor(48, 120);
    tft.print("GAMESP32");

    sprite.createSprite(480, 320);
}

TFT_eSPI &Display::getTFT()
{
    return tft;
}
TFT_eSprite &Display::getSprite()
{
    return sprite;
}