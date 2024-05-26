#include "StartUI.h"

StartUI::StartUI() {}
void StartUI::update()
{
    // instanciate and add UI object and Controller
    InputManager *inputManager = InputManager::getInstance();
    SceneManager *sceneManager = SceneManager::getInstance();
    if (!inputManager->getInputValue("Button A"))
    {
        sceneManager->setCurrentGameScene("Pong Game");
    }
}

void StartUI::render(Adafruit_SSD1325 &display)
{
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(24, 12);
    display.println("Pong-Like");
    display.setTextSize(1);

    display.setCursor(12, 38);
    display.println("Press a button to start");
}
