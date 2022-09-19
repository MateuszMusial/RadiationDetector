#pragma once
#include "ElectronicDisplayInterface.h"
#include "gmock/gmock.h"
#include <string>

class ElectronicDisplayMock : public ElectronicDisplayInterface {

public:
	MOCK_METHOD(void, printMessage, (std::string input), (override));

};
