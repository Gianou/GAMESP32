#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup()
{
    Serial.begin(115200);
    pinMode(BUTTON_A_PIN, INPUT_PULLUP);
    pinMode(BUTTON_B_PIN, INPUT_PULLUP);
    pinMode(SW, INPUT_PULLUP);

    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(48, 120);
    tft.print("Hello World!");
}

void loop()
{
    Serial.print("A : " + String(digitalRead(BUTTON_A_PIN)) + " | ");
    Serial.print("B : " + String(digitalRead(BUTTON_B_PIN)) + " | ");
    Serial.println("SW : " + String(digitalRead(SW)));

    Serial.print("X : " + String(analogRead(VRX)) + " | ");
    Serial.println("Y : " + String(analogRead(VRY)));

    delay(100);
}
