#ifndef Render_Engine_H
#define Render_Engine_H

#include <vector>
#include <algorithm>
#include <TFT_eSPI.h>
#include "AbstractGameObject.h"
#include "../components/Display.h"

class RenderEngine : public AbstractGameObject
{
public:
    RenderEngine();
    void update() override;
    void render(TFT_eSprite &sprite) override;

private:
};

#endif