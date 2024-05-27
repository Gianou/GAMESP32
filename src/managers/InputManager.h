#ifndef InputManager_h
#define InputManager_h

#include <Arduino.h>
#include <map>
#include "../components/AbstractInput.h"

class InputManager
{
public:
    static InputManager *getInstance();

    InputManager(const InputManager &) = delete;
    void operator=(const InputManager &) = delete;
    void addInput(AbstractInput *input);
    void addInputs(std::initializer_list<AbstractInput *> inputs);
    void removeInput(const String &name);
    int getInputValue(const String &name);

private:
    InputManager() {}
    static InputManager *instance;
    std::map<String, AbstractInput *> inputMap;
};

#endif