#ifndef End_UI_H
#define End_UI_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../../../game_engine/GameScene.h"

#include "../../../managers/InputManager.h"
#include "../../../managers/SceneManager.h"

class EndUI : public AbstractGameObject
{
public:
    EndUI();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

private:
};

#endif