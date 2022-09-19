#include "RadiationDetectorT.h"

RadiationDetector::RadiationDetector()	
{
	 auto audioPtr = std::make_shared<AudioBuzzerMock>();
}
