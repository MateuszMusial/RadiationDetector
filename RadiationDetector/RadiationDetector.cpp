#include "RadiationDetector.h"

RadiationDetector::RadiationDetector()
{
}

double RadiationDetector::detectAlphaRadiation()
{

	std::random_device radiation;
	std::mt19937 rng(radiation());
	std::uniform_int_distribution<std::mt19937::result_type> radiationLvl(0, (4000));

	double radiationLevel = radiationLvl(rng);
	return radiationLevel;
}

double RadiationDetector::detectBetaRadiation()
{

	std::random_device radiation;
	std::mt19937 rng(radiation());
	std::uniform_int_distribution<std::mt19937::result_type> radiationLvl(0, (3000));

	double radiationLevel = radiationLvl(rng);
	return radiationLevel;
}

double RadiationDetector::detectGammaRadiation()
{
	std::random_device radiation;
	std::mt19937 rng(radiation());
	std::uniform_int_distribution<std::mt19937::result_type> radiationLvl(0, (2500));

	double radiationLevel = radiationLvl(rng);
	return radiationLevel;
}

bool RadiationDetector::isRadiationLethal(std::string radiationType, double radiationLvel)
{
	bool isLeathal = false;

	if (radiationType == "Alpha") {
		if (radiationLvel <= 2000) {

		}
		else {
			isLeathal = true;
		}
	}
	else if (radiationType == "Beta") {

		if (radiationLvel <= 1500) {
		}
		else {
			isLeathal = true;
		}
	}
	else if (radiationType == "Gamma") {

		if (radiationLvel <= 1000) {

		}
		else {
			isLeathal = true;
		}
	}
	return isLeathal;
}
