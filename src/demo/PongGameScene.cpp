#include "PongGameScene.h"

PongGameScene::PongGameScene(String name) : GameScene(name)
{
    collisionDetector = new CollisionDetector();
    scoreHandler = new ScoreHandler();
    scoreUI = new ScoreUI(scoreHandler);
    addGameObject(scoreUI);
}
CollisionDetector *PongGameScene::getCollisionDetector()
{
    return collisionDetector;
}

ScoreHandler *PongGameScene::getScoreHandler()
{
    return scoreHandler;
}

void PongGameScene::onExitScene()
{
    Serial.println("Exiting " + getName());
}
void PongGameScene::onEnterScene() { Serial.println("Entering " + getName()); }