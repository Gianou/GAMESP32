## Iteration 0 - Hello World

This chapter details the initial steps taken to prepare for the development of the game engine. It includes the selection of components for the gaming device, wiring the components, setting up the development environment, and testing the components. The goal by the end of this iteration is to be fully prepared for the development of the actual game engine.

### Device & Components

To develop a game engine for ESP32, a gaming device is required. For this project, a custom device was built, and this section covers the components selected for this device.

#### ESP32 Microcontroller

The core of the device is the ESP32 microcontroller. Specifically, the ESP32-S3-WROOM-1-N16R8 was chosen for its Flash and PSRAM performance. With 16 MB of Flash and 8 MB of PSRAM, it offers ample memory for storing code and handling graphics.

#### Display

For displaying the game graphics, a 3.5-inch 480x320 MCU SPI Serial TFT LCD Module Display with an ILI9488 driver and an SD card slot was chosen. This display was selected for its size, resolution, compatibility with the Bodmer/TFT_eSPI library, and the presence of an SD card slot.

#### Speaker

Audio output is provided by an Adafruit STEMMA 3885 Speaker with Audio Amplifier. This speaker module was chosen for its compact size and integrated amplifier.

#### Inputs

The gaming device utilizes buttons and a joystick for user input. The buttons are push-buttons, and the joystick consists of two potentiometers and a push-button.

### Wiring

The wiring for the gaming device is as follows:

- Button A:
  - A1 → Pin 37
  - A2 → GND
- Button B:
  - B1 → Pin 21
  - B2 → GND
- Joystick:
  - GND → GND
  - 5V → 3v3
  - VRX → 8
  - VRY → 3
  - SW → 46
- Display:
  - VCC → 3V3
  - GND → GND
  - CS → 15
  - RESET → 4
  - DC/RS → 2
  - SDI/(MOSI) → 11
  - SCK → 12
  - LED → 3V3
  - SDO(MISO) → 13

- Speaker:
  - ???

### Development Environment

To begin developing the game engine code, an integrated development environment (IDE) is required. Visual Studio Code with the Arduino extension was chosen for its integrated Git tools, PowerShell terminals, and familiarity.

### Testing the Components

The final step of Iteration 0 involves testing each component to ensure proper functionality and wiring. This includes testing buttons, the joystick, and the display.

#### Buttons

Buttons are tested using the following Arduino sketch:

```cpp
#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_A_PIN, INPUT_PULLUP);
    pinMode(BUTTON_B_PIN, INPUT_PULLUP);
}

void loop() {
    Serial.print("A : " + String(digitalRead(BUTTON_A_PIN)) + " | ");
    Serial.println("B : " + String(digitalRead(BUTTON_B_PIN)));
    delay(100);
}
```

#### Joystick
The joystick is tested using the following Arduino sketch:
```cpp
#define VRX 8
#define VRY 3
#define SW 46

void setup() {
    Serial.begin(115200);
    pinMode(SW, INPUT_PULLUP);
}

void loop() {
    Serial.print("X : " + String(analogRead(VRX)) + " | ");
    Serial.print("Y : " + String(analogRead(VRY)) + " | ");
    Serial.println("SW : " + String(digitalRead(SW)));

    delay(100);
}
```
#### Display
The display is tested using the TFT_eSPI library and the following code:
```cpp
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
    tft.init();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(5);
    tft.setCursor(48, 120);
    tft.print("Hello World!");
}

void loop() {
}

```