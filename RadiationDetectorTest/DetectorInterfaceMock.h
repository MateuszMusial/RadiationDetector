#pragma once
#include "DetectorInterface.h"
#include <string>
#include "gmock/gmock.h"


class DetectorInterfaceMock : public DetectorInterface {
public:

	MOCK_METHOD(double, detectAlphaRadiation, (), (override));
	MOCK_METHOD(double, detectBetaRadiation, (), (override));
	MOCK_METHOD(double, detectGammaRadiation, (), (override));
	MOCK_METHOD(bool, isRadiationLethal, (std::string radiationType, double radiationLevel), (override));
};