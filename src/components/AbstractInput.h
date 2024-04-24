#ifndef Abstract_Input_H
#define Abstract_Input_H

#include <Arduino.h>

class AbstractInput
{
public:
    virtual void begin();
    virtual int getValue();
    virtual String getName();
};
#endif