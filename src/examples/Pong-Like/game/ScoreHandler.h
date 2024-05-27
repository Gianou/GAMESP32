#ifndef Score_Handler_H
#define Score_Handler_H

#include "../../../managers/SceneManager.h"

class ScoreHandler
{
public:
    ScoreHandler();
    int leftPlayerScore = 0;
    int rightPlayerScore = 0;
    void setLeftPlayerScore(int newScore);
    void setRightPlayerScore(int newScore);
    int getLeftPlayerScore();
    int getRightPlayerScore();

private:
};

#endif