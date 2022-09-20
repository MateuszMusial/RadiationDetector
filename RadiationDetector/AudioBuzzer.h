#pragma once
#include <windows.h>
#include "AudioBuzzerInterface.h"

class AudioBuzzer :
    public AudioBuzzerInterface
{
public:
     void soundAlarm(bool isleathal);
};

