#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#include <SPI.h>
#include <TFT_eSPI.h>

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"

Button buttonA = Button(BUTTON_A_PIN);
Button buttonB = Button(BUTTON_B_PIN);
Button buttonSW = Button(SW);
JoystickAxis xAxis = JoystickAxis(VRX);
JoystickAxis yAxis = JoystickAxis(VRY);

TFT_eSPI tft = TFT_eSPI();

void setup()
{
    Serial.begin(115200);

    buttonA.begin();
    buttonB.begin();
    buttonSW.begin();
    xAxis.begin(); // does nothing
    yAxis.begin(); // does nothing

    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(48, 120);
    tft.print("Hello World!");
}

void loop()
{
    Serial.print("A : " + String(buttonA.getValue()) + " | ");
    Serial.print("B : " + String(buttonB.getValue()) + " | ");
    Serial.println("SW : " + String(buttonSW.getValue()));

    Serial.print("X : " + String(xAxis.getValue()) + " | ");
    Serial.println("Y : " + String(yAxis.getValue()));
    delay(100);
}
