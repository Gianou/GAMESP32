/*
#ifndef Display_OLED_H
#define Display_OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1325.h>
#include "../../config/Constants.h"

class DisplayOLED
{
public:
    DisplayOLED();
    void begin();
    // Adafruit_SSD1325 &getDisplay();
    //  TFT_eSPI &getTFT();
    //  TFT_eSprite &getSprite();

private:
    // TFT_eSPI tft;
    // TFT_eSprite sprite;
    Adafruit_SSD1325 display;
    int width;
    int height;
};

#endif
*/