#ifndef Button_H
#define Button_H

#include <Arduino.h>
#include "AbstractInput.h"

class Button : public AbstractInput
{
public:
    Button(uint8_t pin, String name);
    void begin();
    int getValue();
    String getName();

private:
    uint8_t pin;
    int value;
    String name;
};

#endif