#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#define FRAME_DURATION_MS 1000

#include <SPI.h>

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
#include "src/components/Display.h"
#include "src/managers/InputManager.h"
#include "src/game_engine/RenderEngine.h"

// The whole inputs and outputs process is complex and could use a factory or something

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Display display = Display();
RenderEngine renderEngine = RenderEngine();

InputManager *inputManager = InputManager::getInstance();

void setup()
{
    Serial.begin(115200);

    // Add buttons and joystick axes to the input manager
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    display.begin();
    renderEngine.setDisplay(&display);
}

void loop()
{

    Serial.print("A : " + String(inputManager->getInputValue("Button A")) + " | ");
    Serial.print("B : " + String(inputManager->getInputValue("Button B")) + " | ");
    Serial.println("SW : " + String(inputManager->getInputValue("Button SW")));

    Serial.print("X : " + String(inputManager->getInputValue("X axis")) + " | ");
    Serial.println("Y : " + String(inputManager->getInputValue("Y axis")));
    renderEngine.update();
    renderEngine.render();

    waitUntilEndOfFrame();
}

void waitUntilEndOfFrame()
{
    static unsigned long lastLoop;
    while (millis() - lastLoop < FRAME_DURATION_MS)
    {
    }
    lastLoop = millis();
}
