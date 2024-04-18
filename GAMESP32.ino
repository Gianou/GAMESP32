#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#define FRAME_DURATION_MS 1000

#include <SPI.h>
#include <TFT_eSPI.h>

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
#include "src/managers/InputManager.h"

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

TFT_eSPI tft = TFT_eSPI();

InputManager *inputManager = InputManager::getInstance();

void setup()
{
    Serial.begin(115200);

    // Add buttons and joystick axes to the input manager
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(48, 120);
    tft.print("Hello World!");
}

void loop()
{

    Serial.print("A : " + String(inputManager->getInputValue("Button A")) + " | ");
    Serial.print("B : " + String(inputManager->getInputValue("Button B")) + " | ");
    Serial.println("SW : " + String(inputManager->getInputValue("Button SW")));

    Serial.print("X : " + String(inputManager->getInputValue("X axis")) + " | ");
    Serial.println("Y : " + String(inputManager->getInputValue("Y axis")));

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
