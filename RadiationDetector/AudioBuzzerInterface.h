#pragma once
#include <windows.h>

class AudioBuzzerInterface
{
public:
	virtual void soundAlarm(bool isleathal)= 0;
};

