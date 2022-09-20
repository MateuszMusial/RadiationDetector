#pragma once
#include <string>

class ElectronicDisplayInterface
{
public:
	virtual void printMessage(bool isLeathal) = 0;
};

