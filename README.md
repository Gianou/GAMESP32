# GAMESP32 Iteration 1 - Hello World

Game Engine for ESP32 based gaming console. This repository shows the development steps of a Game Engine meant to run on custom ESP32-S3 gaming device.  
  
The project was realised for my bachelor thesis, Coding a 2D Game Engine for ESP32: A Showcase of Design Patterns, in software development at Haaga-Helia University of Applied Sciences.

## Software Setup

### Dependencies

This project requires the following librairies:
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)

### Configuration

#### TFT_eSPI Configuration
The [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) library requires some configuration :
```
// TFT_Setup thingy

```

## Hardware Setup

### Components Used

- ESP32-S3-WROOM-1-N16R8 
- 3.5inch 480x320 MCU SPI Serial TFT LCD Module Display with an ILI9488 driver and an SD card slot
- Buttons
- Joystick

### Wiring Instructions

- Button A
    - A 1 → Pin 37
    - A 2 → GND
- Button B
    - B 1 → Pin 21
    - B 2 → GND
- Joystick
    - GND → GND
    - 5V → 3v3
    - VRX → 8
    - VRY → 3
    - SW → 46
- Display
    - VCC → 3V3
    - GND → GND
    - CS → 15
    - RESET → 4
    - DC/RS → 2
    - SDI/(MOSI) → 11
    - SCK → 12
    - LED → 3V3
    - SDO(MISO) → 13

    
## Running the Project



## License
To be defined

