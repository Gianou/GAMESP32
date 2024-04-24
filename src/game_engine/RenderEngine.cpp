#include "RenderEngine.h"

RenderEngine::RenderEngine()
{
}

void RenderEngine::update()
{
}

void RenderEngine::render(TFT_eSprite &sprite)
{
    sprite.pushSprite(0, 0);
    sprite.fillSprite(TFT_BLACK);
}
