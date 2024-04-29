#include "ScoreUI.h"

ScoreUI::ScoreUI(ScoreHandler *scoreHandler) : scoreHandler(scoreHandler) {}

void ScoreUI::update()
{
    // Update logic for the score UI
}

void ScoreUI::render(TFT_eSprite &sprite)
{
    int left = scoreHandler->getLeftPlayerScore();
    int right = scoreHandler->getRightPlayerScore();
    sprite.drawString(String(left), 24, 12);
    sprite.drawString(String(right), 100, 12);
}
