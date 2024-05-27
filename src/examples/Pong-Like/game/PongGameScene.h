#ifndef Pong_Game_Scene_H
#define Pong_Game_Scene_H

#include "../../../game_engine/GameScene.h"
#include "ScoreHandler.h"
#include "ScoreUI.h"
#include "../../../game_engine/CollisionDetector.h"

class PongGameScene : public GameScene
{
public:
    PongGameScene(String name);

    void onEnterScene() override;
    void onExitScene() override;

    CollisionDetector *getCollisionDetector();
    ScoreHandler *getScoreHandler();

private:
    std::vector<AbstractGameObject *> gameObjects;
    CollisionDetector *collisionDetector;
    ScoreHandler *scoreHandler;
    ScoreUI *scoreUI;
};

#endif