#pragma once
#include <random>

#include "DetectorInterface.h"

class RadiationDetector :
    public DetectorInterface
{
public:
    RadiationDetector();

	double detectAlphaRadiation();
	double detectBetaRadiation();
	double detectGammaRadiation();
	bool isRadiationLethal(std::string radiationType, double radiationLvel);

};

