#include "action_map.h"



bool ActionMap::CanPreform(skill pskill, difficulty pdif)
{
	if (pdif > this->find(pskill)->skill_macro)
	{
		return true;
	}
	return false;
}