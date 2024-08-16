#pragma once
#include <string>

#include "ClassAttributes.h"

class ClassCommand
{
public:
    ClassCommand(const ParameterType type, const std::string& name)
    {
        commandType = type;
        commandName = name;
    }

    ParameterType GetType() const { return commandType; }
    std::string GetName() const { return commandName; }

    
private:
    ParameterType commandType;
    std::string commandName;
};
