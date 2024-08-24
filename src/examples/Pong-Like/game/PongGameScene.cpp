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
void PongGameScene::onEnterScene()
{
    Serial.println("Entering " + getName());
    // Reset the scores
    scoreHandler->setLeftPlayerScore(0);
    scoreHandler->setRightPlayerScore(0);
    // scoreHandler->setWinner("");
    //  Should reset the ball and paddles
}