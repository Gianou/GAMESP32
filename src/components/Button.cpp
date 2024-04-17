#include "Button.h"

Button::Button(uint8_t pin) : pin(pin) {}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

int Button::getValue()
{
    return digitalRead(pin);
}
