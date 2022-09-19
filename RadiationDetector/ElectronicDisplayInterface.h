#pragma once
#include <string>

class ElectronicDisplayInterface
{
public:
	virtual void printMessage(std::string input) = 0;
};

