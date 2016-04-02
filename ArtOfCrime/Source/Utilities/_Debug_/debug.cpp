#include "debug.h"
#include <iostream>

void Debug::Print(std::string msg)
{
	std::cout << msg << std::endl;
}

void Debug::Print(Type type, std::string msg, std::string file, std::string method)
{
	switch (type)
	{
	case Debug::warning:
		Print("Warning: " + msg + " @" + file + ":" + method);
		break;
	case Debug::error:
		Print("Error: " + msg + " @" + file + ":" + method);
		break;
	case Debug::critical:
		Print("Critical: " + msg + " @" + file + ":" + method);
		exit(EXIT_FAILURE);
		break;
	default:
		Print(msg);
		break;
	}
}