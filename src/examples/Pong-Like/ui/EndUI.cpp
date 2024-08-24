#include "EndUI.h"

EndUI::EndUI() {}
void EndUI::update()
{
    // instanciate and add UI object and Controller
    InputManager *inputManager = InputManager::getInstance();
    SceneManager *sceneManager = SceneManager::getInstance();
    if (!inputManager->getInputValue("Button B"))
    {
        sceneManager->setCurrentGameScene("Start");
    }
}

void EndUI::render(Adafruit_SSD1325 &display)
{

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(12, 12);
    display.print("Game Over");
    display.setTextSize(1);

    display.setCursor(12, 38);
    display.println("Press B to go back");
}
