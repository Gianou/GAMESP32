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

    Serial.print("TFT PSRAM enabled : ");
    /* Doesnt ever return enable true
    Serial.print("TFT PSRAM enabled : ");
    Serial.println(tft.getAttribute(PSRAM_ENABLE));
    tft.setAttribute(PSRAM_ENABLE, true);
    Serial.print("TFT PSRAM enabled : ");
    Serial.println(tft.getAttribute(PSRAM_ENABLE));
    */

    sprite.createSprite(width, height);

    Serial.print("Default color depth : ");
    Serial.println(sprite.getColorDepth());

    /* Disabling the PSRAM did not change anything
        Serial.print("PSRAM enabled : ");
        Serial.println(sprite.getAttribute(PSRAM_ENABLE));
        sprite.setAttribute(PSRAM_ENABLE, false);
        Serial.print("PSRAM enabled : ");
        Serial.println(sprite.getAttribute(PSRAM_ENABLE));
        */

    /*
        sprite.setColorDepth(1);
        Serial.print("New color depth : ");
        Serial.println(sprite.getColorDepth());
        */
}

TFT_eSPI &Display::getTFT()
{
    return tft;
}
TFT_eSprite &Display::getSprite()
{
    return sprite;
}