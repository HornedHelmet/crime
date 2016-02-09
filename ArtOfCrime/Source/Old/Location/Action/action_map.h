#pragma once
#include "action.h"

#define action_macro first
#define skill_macro second

class ActionMap  : public std::map<skill, difficulty>
{
public:
	bool CanPreform(skill pskill, difficulty pdif);

};

