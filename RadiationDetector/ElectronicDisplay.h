#pragma once
#include "ElectronicDisplayInterface.h"
#include <iostream>

class ElectronicDisplay :
    public ElectronicDisplayInterface
{
public:
    void printMessage(bool isLeathal);
};

