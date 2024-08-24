#include "SnakeStartUI.h"

SnakeStartUI::SnakeStartUI() {}

void SnakeStartUI::update()
{
    // Start the game when a button is pressed
    InputManager *inputManager = InputManager::getInstance();
    SceneManager *sceneManager = SceneManager::getInstance();
    if (!inputManager->getInputValue("Button A"))
    {
        sceneManager->setCurrentGameScene("Snake Game");
    }
}

void SnakeStartUI::render(Adafruit_SSD1325 &display)
{
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(12, 12);
    display.println("Snake-Like");
    display.setTextSize(1);

    display.setCursor(12, 38);
    display.println("Press A to start");
}
