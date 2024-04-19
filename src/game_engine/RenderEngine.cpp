#include "RenderEngine.h"

RenderEngine::RenderEngine()
{
}

void RenderEngine::setDisplay(Display *display)
{
    this->display = display;
}

void RenderEngine::update()
{
}

void RenderEngine::render()
{
    display->getSprite().pushSprite(0, 0); // reset screen
}
