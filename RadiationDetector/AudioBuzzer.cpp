#include "AudioBuzzer.h"

void AudioBuzzer::soundAlarm(bool isleathal)
{
	if (isleathal) {
		Beep(440, 150);
		Beep(523, 200);
		Beep(700, 400);
	}
}
