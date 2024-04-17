#ifndef Joystick_Axis_H
#define Joystick_Axis_H

#include <Arduino.h>
#include "AbstractInput.h"

class JoystickAxis : public AbstractInput
{
public:
    JoystickAxis(uint8_t pin);
    void begin();
    int getValue();

private:
    uint8_t pin;
    int value;
};

#endif