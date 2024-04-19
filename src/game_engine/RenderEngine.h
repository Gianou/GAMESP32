#ifndef Render_Engine_H
#define Render_Engine_H

#include <vector>
#include <algorithm>
#include "AbstractGameObject.h"
#include "../components/Display.h"

class RenderEngine : public AbstractGameObject
{
public:
    RenderEngine();
    void update();
    void render();
    void setDisplay(Display* display);

private:
    Display *display;
};

#endif