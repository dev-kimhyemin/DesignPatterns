#include "EnhancedClass.h"

#include <iostream>


void EnhancedClass::Add(const ParameterType type, const std::string& name)
{
    commands.emplace(type, name);
    ExecuteToFiles(true, type, name);

    Print();
}

void EnhancedClass::Undo()
{
    if(commands.empty())
    {
        std::cout << "Class is empty\n";
        return;
    }
    
    const ClassCommand prevCommand = commands.top();
    commands.pop();
    ExecuteToFiles(false, prevCommand.GetType(), prevCommand.GetName());

    Print();
}

void EnhancedClass::Print() const
{
    std::string str;

    str.append("**********\n");
    str.append("Header File: \n");
    str.append(headerFile->GetList());
    str.append("**********\n");
    str.append("Cpp File: \n");
    str.append(cppFile->GetList());
    str.append("**********\n");
    str.append("\n\n");

    std::cout << str;
}

void EnhancedClass::ExecuteToFiles(const bool bIsAdd, const ParameterType type, const std::string& name) const
{
    auto execute = [&](ClassFile& file, const std::string& std)
    {
        if(bIsAdd)
            file.AddLine(std);
        else
            file.RemoveLine(std);
    };
    
    switch (type)
    {
    case Function:
        execute(*headerFile, name);
        execute(*cppFile, name);
        break;
    case Property:
        execute(*headerFile, name);
        break;
    case Include:
        execute(*cppFile, name);
        break;
    }
}

