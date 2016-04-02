#pragma once
#include "object.h"
#include <string>

class Location : public AObject
{
public:
    Location(std::string name)
    {
        m_name = name;
    }

    std::string GetName()
    {
        return m_name;
    }

    void SetName(std::string name)
    {
        m_name = name;
    }

private:
    std::string m_name;
};