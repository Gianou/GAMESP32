#include "ScoreUI.h"

ScoreUI::ScoreUI(ScoreHandler *scoreHandler) : scoreHandler(scoreHandler) {}

void ScoreUI::update()
{
}

void ScoreUI::render(Adafruit_SSD1325 &display)
{
    int left = scoreHandler->getLeftPlayerScore();
    int right = scoreHandler->getRightPlayerScore();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24, 12);
    display.println(String(left));
    display.setCursor(100, 12);
    display.println(String(right));
}
