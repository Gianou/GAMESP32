#ifndef Button_H
#define Button_H

#include <Arduino.h>
#include "AbstractInput.h"

class Button : public AbstractInput
{
public:
    Button(uint8_t pin);
    void begin();
    int getValue();

private:
    uint8_t pin;
    int value;
};

#endif