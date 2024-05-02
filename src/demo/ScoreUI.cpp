#include "ScoreUI.h"

ScoreUI::ScoreUI(ScoreHandler *scoreHandler) : scoreHandler(scoreHandler) {}

void ScoreUI::update()
{
    // Update logic for the score UI
}

void ScoreUI::render(Adafruit_SSD1325 &display)
{
    int left = scoreHandler->getLeftPlayerScore();
    int right = scoreHandler->getRightPlayerScore();
    // display.println(String(left), 24, 12);
    // display.println(String(right), 100, 12);
}
