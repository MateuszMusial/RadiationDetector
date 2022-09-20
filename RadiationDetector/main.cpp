#include "AudioBuzzer.h"
#include "ElectronicDisplay.h"
#include "RadiationDetector.h"


int main() {

	RadiationDetector detectorObj;
	ElectronicDisplay displayObj;
	AudioBuzzer audioObj;

	while (true) {
		double radiationLevel;
		bool isLeathal = false;

		radiationLevel =  detectorObj.detectAlphaRadiation();
		isLeathal = detectorObj.isRadiationLethal("Alpha", radiationLevel);
		audioObj.soundAlarm(isLeathal);
		displayObj.printMessage(isLeathal);
		Sleep(2000);

		detectorObj.detectBetaRadiation();
		isLeathal = detectorObj.isRadiationLethal("Beta", radiationLevel);
		audioObj.soundAlarm(isLeathal);
		displayObj.printMessage(isLeathal);
		Sleep(2000);

		detectorObj.detectGammaRadiation();
		isLeathal = detectorObj.isRadiationLethal("Gamma", radiationLevel);
		audioObj.soundAlarm(isLeathal);
		displayObj.printMessage(isLeathal);
		Sleep(2000);
	}

}