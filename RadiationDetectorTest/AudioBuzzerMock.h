#pragma once
#include "AudioBuzzerInterface.h"
#include "gmock/gmock.h"
#include <iostream>

class AudioBuzzerMock :
    public AudioBuzzerInterface
{
public:
    MOCK_METHOD(void, soundAlarm, (), (override));
};

