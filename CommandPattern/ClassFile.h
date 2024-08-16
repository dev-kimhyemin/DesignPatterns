#pragma once
#include <list>
#include <string>

class ClassFile
{
public:
    void AddLine(const std::string& name)
    {
        nameList.push_back(name);
    }

    void RemoveLine(const std::string& name)
    {
        nameList.remove(name);
    }

    std::string GetList() const
    {
        std::string str;

        for (const std::string& name : nameList)
        {
            str.append(name + "\n");
        }

        return str;
    }
    
private:
    std::list<std::string> nameList;
};
