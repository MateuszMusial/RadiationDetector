#include "ElectronicDisplayMock.h"
#include "ElectronicDisplayInterface.h"
#include "AudioBuzzerMock.h"
#include "DetectorInterfaceMock.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <iostream>

TEST(ElectronicDisplayTest, isPrinted) {

	auto mockObj = std::make_shared<ElectronicDisplayMock>();
	EXPECT_CALL(*mockObj, printMessage("KFC")).Times(1);
	mockObj->printMessage("KFC");
}

TEST(AudioBuzzerTest, Beeep) {
	
	AudioBuzzerMock audio;
	EXPECT_CALL(audio, SoundAlarm()).Times(1);
	audio.SoundAlarm();
}

TEST(LowLevelRadiationTest, AlphaRadiation) {
	DetectorInterfaceMock detector;
	detector.detectAlphaRadiation();

	/*if (detector.detectAlphaRadiation().WillOnce(::testing::Return(150)) <= 2500) {
		EXPECT_FALSE(detector.isRadiationLethal("Alpha"));
	}*/
}

TEST(LowLevelRadiationTest, BetaRadiation) {
	DetectorInterfaceMock detector;

	EXPECT_CALL(detector, detectBetaRadiation()).WillOnce(testing::Return(1000));

	if(detector.detectBetaRadiation() <= 500)
		EXPECT_FALSE(detector.isRadiationLethal("Beta"));
}

TEST(LowLevelRadiationTest, GammaRadiation) {
	DetectorInterfaceMock detector;
	detector.detectGammaRadiation();

	if (detector.detectGammaRadiation())
		EXPECT_FALSE(detector.isRadiationLethal("Gamma"));

}

