#include "view_manager.h"

bool IsMarkedForDeletion(std::pair<std::unique_ptr<View>, bool> const& view)
{
	if (view.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}
