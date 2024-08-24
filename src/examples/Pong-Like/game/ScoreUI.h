#ifndef Score_UI_H
#define Score_UI_H

#include "ScoreHandler.h"
#include "../../../game_engine/AbstractGameObject.h"

class ScoreUI : public AbstractGameObject
{
public:
    ScoreUI(ScoreHandler *scoreHandler);
    void update() override;
    void render(Adafruit_SSD1325 &display) override;

    // HitBox *getHitBox() { return nullptr; };

private:
    ScoreHandler *scoreHandler;
};

#endif