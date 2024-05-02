#ifndef CONSTANTS_H
#define CONSTANTS_H

const int BUTTON_A_PIN = 37;
const int BUTTON_B_PIN = 21;

const int VRX = 7;
const int VRY = 3;
const int SW = 46;

const int FRAME_DURATION_MS = 33;
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

// If using software SPI, define CLK and MOSI
const int OLED_CLK = 13;
const int OLED_MOSI = 11;

// These are neede for both hardware & softare SPI
const int OLED_CS = 10;
const int OLED_RESET = 9;
const int OLED_DC = 8;

// const uint16_t WHITE = 0xFFFF;

#endif