#ifndef Start_UI_H
#define Start_UI_H

#include "../../../game_engine/AbstractGameObject.h"

#include "../../../managers/InputManager.h"
#include "../../../managers/SceneManager.h"

class StartUI : public AbstractGameObject
{
public:
    StartUI();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

private:
};

#endif