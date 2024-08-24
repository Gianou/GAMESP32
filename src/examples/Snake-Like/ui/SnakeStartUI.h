#ifndef SNAKE_START_UI_H
#define SNAKE_START_UI_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../../../managers/SceneManager.h"
#include "../../../managers/InputManager.h"

class SnakeStartUI : public AbstractGameObject
{
public:
    SnakeStartUI();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
};

#endif
