#include "Button.h"

Button::Button(uint8_t pin, String name) : pin(pin), name(name) {}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

int Button::getValue()
{
    return digitalRead(pin);
}

String Button::getName()
{
    return name;
}
