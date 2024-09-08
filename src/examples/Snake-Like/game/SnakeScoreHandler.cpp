#include "SnakeScoreHandler.h"

SnakeScoreHandler::SnakeScoreHandler() {}

int SnakeScoreHandler::getDisplayScore()
{
    if (displayScore < score * 100)
    {
        displayScore += 3;
    }
    if (displayScore > score * 100)
    {
        displayScore = score * 100;
    }
    return displayScore;
}

void SnakeScoreHandler::reset()
{
    score = 0;
    displayScore = 0;
}