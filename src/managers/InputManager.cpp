#include "InputManager.h"

InputManager *InputManager::instance = nullptr;

InputManager *InputManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new InputManager();
    }
    return instance;
}

void InputManager::addInput(AbstractInput *input)
{
    if (inputMap.find(input->getName()) != inputMap.end())
    {
        Serial.println("Error: Input with the same name already exists.");
        throw std::invalid_argument("Input with the same name already exists.");
    }
    inputMap[input->getName()] = input;
    input->begin();
}

void InputManager::addInputs(std::initializer_list<AbstractInput *> inputs)
{
    for (auto input : inputs)
    {
        addInput(input);
    }
}

void InputManager::removeInput(const String &name)
{
    inputMap.erase(name);
}

int InputManager::getInputValue(const String &name)
{
    auto it = inputMap.find(name);
    if (it != inputMap.end())
    {
        return it->second->getValue();
    }
    return 0;
}