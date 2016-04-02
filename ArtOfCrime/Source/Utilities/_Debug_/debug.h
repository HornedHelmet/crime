#pragma once
#include <string>

class Debug
{
public:
	enum Type
	{
		warning,
		error,
		critical
	};

	static void Print(std::string msg);
	static void Print(Type type, std::string msg, std::string file, std::string method);


};

