#ifndef Joystick_Axis_H
#define Joystick_Axis_H

#include <Arduino.h>
#include "AbstractInput.h"

class JoystickAxis : public AbstractInput
{
public:
    JoystickAxis(uint8_t pin, String name);
    void begin();
    int getValue();
    String getName();

private:
    uint8_t pin;
    int value;
    String name;
};

#endif