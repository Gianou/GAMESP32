#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#include <SPI.h>
#include <TFT_eSPI.h>

#include "src/components/Button.h"

Button buttonA = Button(BUTTON_A_PIN);
Button buttonB = Button(BUTTON_B_PIN);
Button buttonSW = Button(SW);

TFT_eSPI tft = TFT_eSPI();

void setup()
{
    Serial.begin(115200);

    buttonA.begin();
    buttonB.begin();
    buttonSW.begin();

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
    delay(100);
}
