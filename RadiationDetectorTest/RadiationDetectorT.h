#pragma once
#include "AudioBuzzerInterface.h"
#include "DetectorInterface.h"
#include "../RadiationDetectorTest/AudioBuzzerMock.h"
#include "../RadiationDetectorTest/DetectorInterfaceMock.h"
#include "../RadiationDetectorTest/ElectronicDisplayMock.h"


class RadiationDetectorT : public DetectorInterface
{
public:
	RadiationDetectorT();
	AudioBuzzerMock* audioPtr;
	DetectorInterfaceMock* detectorPtr;
	ElectronicDisplayMock* displayPtr;

};

