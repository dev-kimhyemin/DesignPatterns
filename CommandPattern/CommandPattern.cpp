
#include <iostream>

#include "EnhancedClass.h"

static void GetInput(EnhancedClass* targetClass)
{
    ParameterType type = Function;
    std::string typeString;
    int typeInt;
    std::string name;
    
    std::cout << "Input type(0 ~ 2) or undo(z): ";
    std::cin >> typeString;

    if(typeString == "z")
    {
        targetClass->Undo();
        return;
    }

    try
    {
        typeInt = std::stoi(typeString);
    }
    catch (...)
    {
        return;
    }
    
    if(typeInt < 0 || typeInt > 2)
    {
        return;
    }

    type = static_cast<ParameterType>(typeInt);
    
    std::cout << "Input name: ";
    std::cin >> name;

    targetClass->Add(type, name);
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
