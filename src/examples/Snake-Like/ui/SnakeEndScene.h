#ifndef SNAKE_END_SCENE_H
#define SNAKE_END_SCENE_H

#include "../../../game_engine/GameScene.h"
#include "../game/SnakeScoreHandler.h"

class SnakeEndScene : public GameScene
{
public:
    SnakeEndScene(String name);
    SnakeScoreHandler *scoreHandler;

private:
};
#endif
