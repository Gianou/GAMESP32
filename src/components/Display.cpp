#include "Display.h"

Display::Display(int width, int height)
    : width(width), height(height), tft(TFT_eSPI()), sprite(&tft)
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

    sprite.createSprite(width, height);

    Serial.print("Default color depth : ");
    Serial.println(sprite.getColorDepth());
    // sprite.setColorDepth(8);
    // Serial.print("New color depth : ");
    // Serial.println(sprite.getColorDepth());
}

TFT_eSPI &Display::getTFT()
{
    return tft;
}
TFT_eSprite &Display::getSprite()
{
    return sprite;
}