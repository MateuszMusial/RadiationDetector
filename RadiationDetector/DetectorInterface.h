#pragma once
#include <string>

class DetectorInterface
{
public:
	virtual double detectAlphaRadiation() = 0;
	virtual double detectBetaRadiation() = 0;
	virtual double detectGammaRadiation() = 0;
	virtual bool isRadiationLethal(std::string radiationType, double radiotionLvel) = 0;
};

