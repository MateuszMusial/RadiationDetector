#include "ElectronicDisplay.h"

void ElectronicDisplay::printMessage(bool isLeathal)
{
	if (isLeathal)
		std::cout << "\n\tALARM!!! TOO HIGH RADIATION!\n" << std::endl;
	else
		std::cout << "\n\tRadiation level isn't dangerous.\n" << std::endl;

}
