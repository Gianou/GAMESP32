#include "JoystickAxis.h"

JoystickAxis::JoystickAxis(uint8_t pin) : pin(pin) {}

void JoystickAxis::begin()
{
}

int JoystickAxis::getValue()
{
    return analogRead(pin);
}
