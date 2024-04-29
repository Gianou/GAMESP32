#ifndef Score_UI_H
#define Score_UI_H

#include "../game_engine/AbstractGameObject.h"
#include "ScoreHandler.h"

class ScoreUI : public AbstractGameObject
{
public:
    ScoreUI(ScoreHandler *scoreHandler);
    void update() override;
    void render(TFT_eSprite &sprite) override;

    RigidBody *getRigidBody() { return nullptr; };

private:
    ScoreHandler *scoreHandler;
};

#endif