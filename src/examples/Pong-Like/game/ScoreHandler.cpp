#include "ScoreHandler.h"

void ScoreHandler::setLeftPlayerScore(int newScore)
{
    leftPlayerScore = newScore;
}
void ScoreHandler::setRightPlayerScore(int newScore)
{
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
