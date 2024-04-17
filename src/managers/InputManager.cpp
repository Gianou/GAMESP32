#include "InputManager.h"

InputManager *InputManager::instance_ = nullptr;

InputManager *InputManager::getInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new InputManager();
    }
    return instance_;
}

void InputManager::addInput(AbstractInput *input)
{
    if (inputMap_.find(input->getName()) != inputMap_.end())
    {
        Serial.println("Error: Input with the same name already exists.");
        throw std::invalid_argument("Input with the same name already exists.");
    }
    inputMap_[input->getName()] = input;
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
    inputMap_.erase(name);
}

int InputManager::getInputValue(const String &name)
{
    auto it = inputMap_.find(name);
    if (it != inputMap_.end())
    {
        return it->second->getValue(); // Assuming AbstractInput::getValue() returns an int
    }
    return 0; // Or any default value indicating input not found
}