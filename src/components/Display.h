#ifndef Display_H
#define Display_H

#include <TFT_eSPI.h>

class Display
{
public:
    Display(int width, int height);
    void begin();
    TFT_eSPI &getTFT();
    TFT_eSprite &getSprite();

private:
    TFT_eSPI tft;
    TFT_eSprite sprite;
    int width;
    int height;
};

#endif
