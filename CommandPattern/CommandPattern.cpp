
#include <iostream>
#include <string>
#include "EnhancedClass.h"

static bool GetTypeIfPossible(const std::string& typeString, ParameterType& type)
{
    int typeInt;
    
    try
    {
        typeInt = std::stoi(typeString);
    }
    catch (...)
    {
        return false;
    }

    if(typeInt < 0 || typeInt > 2)
    {
        return false;
    }

    type = static_cast<ParameterType>(typeInt);
    return true;
}

static void GetInput(EnhancedClass* targetClass)
{
    ParameterType type = Function;
    std::string typeString;

    std::cout << "Input type(0 ~ 2) or undo(z): ";
    std::getline(std::cin, typeString);

    if(typeString == "z")
    {
        targetClass->Undo();
        return;
    }

    if(GetTypeIfPossible(typeString, type))
    {
        std::string name;
        std::cout << "Input name: ";
        std::getline(std::cin, name);

        targetClass->Add(type, name);
    }
}

int main(int argc, char* argv[])
{
    EnhancedClass* newClass = new EnhancedClass();

    while(true)
    {
        GetInput(newClass);
    }
    
    return 0;
}
