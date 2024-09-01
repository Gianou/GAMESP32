#include "SnakeEndUI.h"

SnakeEndUI::SnakeEndUI() {}

void SnakeEndUI::update()
{
    // Return to the start menu when a button is pressed
    InputManager *inputManager = InputManager::getInstance();
    SceneManager *sceneManager = SceneManager::getInstance();
    if (!inputManager->getInputValue("Button B"))
    {
        sceneManager->setCurrentGameScene("Start");
    }
}

void SnakeEndUI::render(Adafruit_SSD1325 &display)
{
    display.clearDisplay();
    display.setCursor(10, 20);
    display.print("Game Over!");
    display.setCursor(10, 35);
    display.print("Score: ");
    // display.print(finalScore);
    display.setCursor(10, 50);
    display.print("Press Start to Retry");
}

void SnakeEndUI::setFinalScore(int score)
{
    finalScore = score;
}
