#include "ScoreHandler.h"

ScoreHandler::ScoreHandler() {}

void ScoreHandler::setLeftPlayerScore(int newScore)
{
    if (newScore >= 11)
    {
        // left player wins

        SceneManager *sceneManager = SceneManager::getInstance();
        sceneManager->setCurrentGameScene("End");
    }
    leftPlayerScore = newScore;
}
void ScoreHandler::setRightPlayerScore(int newScore)
{
    if (newScore >= 11)
    {
        // right player wins

        SceneManager *sceneManager = SceneManager::getInstance();
        sceneManager->setCurrentGameScene("End");
    }
    rightPlayerScore = newScore;
}
int ScoreHandler::getLeftPlayerScore()
{
    return leftPlayerScore;
}
int ScoreHandler::getRightPlayerScore()
{
    return rightPlayerScore;
}
