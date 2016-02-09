#pragma once
#include "object.h"
#include <string>

class NPC : public AObject
{
public:
	NPC()
	{

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