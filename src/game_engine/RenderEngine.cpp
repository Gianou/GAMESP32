#include "RenderEngine.h"

RenderEngine::RenderEngine() : display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS)
{
    /**/
    display.begin();
    display.display();
    display.clearDisplay();
}

void RenderEngine::update()
{
}

void RenderEngine::render(Adafruit_SSD1325 &display)
{
    display.display();
    display.clearDisplay();
}

Adafruit_SSD1325 &RenderEngine::getDisplay()
{
    return display;
}