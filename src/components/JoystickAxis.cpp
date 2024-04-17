#include "JoystickAxis.h"

JoystickAxis::JoystickAxis(uint8_t pin, String name) : pin(pin), name(name) {}

void JoystickAxis::begin()
{
}

int JoystickAxis::getValue()
{
    return analogRead(pin);
}

String JoystickAxis::getName()
{
    return name;
}
