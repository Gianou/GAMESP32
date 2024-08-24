#ifndef SNAKE_END_UI_H
#define SNAKE_END_UI_H

#include "../../../game_engine/AbstractGameObject.h"
#include "../../../managers/InputManager.h"
#include "../../../managers/SceneManager.h"

class SnakeEndUI : public AbstractGameObject
{
public:
    SnakeEndUI();
    void update() override;
    void render(Adafruit_SSD1325 &display) override;
    void setFinalScore(int score);

private:
    int finalScore;
};

#endif
