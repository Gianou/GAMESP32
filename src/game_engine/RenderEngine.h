#ifndef Render_Engine_H
#define Render_Engine_H

#include <vector>
#include <algorithm>

#include <Adafruit_SSD1325.h>
#include <Adafruit_GFX.h>

#include "AbstractGameObject.h"
#include "../components/Display.h"
#include "../../config/Constants.h"

class RenderEngine : public AbstractGameObject
{
public:
    RenderEngine();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    Adafruit_SSD1325 &getDisplay();

private:
    Adafruit_SSD1325 display;
};

#endif