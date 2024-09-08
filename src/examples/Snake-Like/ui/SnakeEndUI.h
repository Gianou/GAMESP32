#ifndef SNAKE_END_UI_H
#define SNAKE_END_UI_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../game/SnakeScoreHandler.h"
#include "../../../managers/InputManager.h"
#include "../../../managers/SceneManager.h"

class SnakeEndUI : public AbstractGameObject
{
public:
    SnakeEndUI();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    SnakeScoreHandler *scoreHandler;
    void setScoreHandler(SnakeScoreHandler *newScoreHandler) { scoreHandler = newScoreHandler; }

private:
};

#endif
