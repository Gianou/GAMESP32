#ifndef SNAKE_SCORE_HANDLER_H
#define SNAKE_SCORE_HANDLER_H

class SnakeScoreHandler
{
public:
    SnakeScoreHandler();
    void reset();
    void setScore(int newScore) { score = newScore; }
    int getScore() { return score; }
    int getDisplayScore();

private:
    int score;
    int displayScore;
};

#endif