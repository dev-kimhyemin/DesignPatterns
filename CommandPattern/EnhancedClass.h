#pragma once

#include <stack>
#include <string>
#include "ClassFile.h"
#include "ClassCommand.h"

class ClassFile;

class EnhancedClass
{
public:
    EnhancedClass()
    {
        headerFile = new ClassFile();
        cppFile = new ClassFile();
    }
    
    void Add(ParameterType type, const std::string& name);
    void Undo();

private:
    void Print() const;
    void ExecuteToFiles(const bool bIsAdd, ParameterType type, const std::string& name) const;
    
    std::stack<ClassCommand> commands;
    
    ClassFile* headerFile;
    ClassFile* cppFile;
};
