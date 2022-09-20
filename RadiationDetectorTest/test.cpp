#include "ElectronicDisplayMock.h"
#include "ElectronicDisplayInterface.h"
#include "AudioBuzzerMock.h"
#include "DetectorInterfaceMock.h"
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <iostream>

using ::testing::Return;

TEST(ElectronicDisplayTest, isPrinted) {

	auto mockObj = std::make_shared<ElectronicDisplayMock>();
	EXPECT_CALL(*mockObj, printMessage("KFC")).Times(1);
	mockObj->printMessage("KFC");
}

TEST(AudioBuzzerTest, Beeep) {

	AudioBuzzerMock audio;
	EXPECT_CALL(audio, soundAlarm()).Times(1);
	audio.soundAlarm();
}

TEST(LowLevelRadiationTest, AlphaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();

	EXPECT_CALL(*mockObj, detectAlphaRadiation()).WillOnce(Return(200));		// Radiation detect test
	double val1 = mockObj->detectAlphaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(false));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_FALSE(val2);
}

TEST(LowLevelRadiationTest, BetaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();

	EXPECT_CALL(*mockObj, detectBetaRadiation()).WillOnce(Return(200));		// Radiation detect test
	double val1 = mockObj->detectBetaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(false));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_FALSE(val2);
}

TEST(LowLevelRadiationTest, GammaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();

	EXPECT_CALL(*mockObj, detectGammaRadiation()).WillOnce(Return(200));		// Radiation detect test
	double val1 = mockObj->detectGammaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(false));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_FALSE(val2);
}

/*----------------- HIGH LEVEL RADIATION TESTS --------------*/

TEST(HighLevelRadiationTest, AlphaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();
	auto mockBuzzer = std::make_shared<AudioBuzzerMock>();

	EXPECT_CALL(*mockObj, detectAlphaRadiation()).WillOnce(Return(3000));		// Radiation detect test
	double val1 = mockObj->detectAlphaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(true));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_TRUE(val2);

	EXPECT_CALL(*mockBuzzer, soundAlarm());
	if (val2) {
		mockBuzzer->soundAlarm();
	}
}

TEST(HighLevelRadiationTest, BetaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();
	auto mockBuzzer = std::make_shared<AudioBuzzerMock>();

	EXPECT_CALL(*mockObj, detectBetaRadiation()).WillOnce(Return(2000));		// Radiation detect test
	double val1 = mockObj->detectBetaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(true));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_TRUE(val2);

	EXPECT_CALL(*mockBuzzer, soundAlarm());
	if (val2) {
		mockBuzzer->soundAlarm();
	}
}

TEST(HighLevelRadiationTest, GammaRadiation) {

	std::string radiationType;

	auto mockObj = std::make_shared<DetectorInterfaceMock>();
	auto mockDisplay = std::make_shared<ElectronicDisplayMock>();
	auto mockBuzzer = std::make_shared<AudioBuzzerMock>();

	EXPECT_CALL(*mockObj, detectGammaRadiation()).WillOnce(Return(1600));		// Radiation detect test
	double val1 = mockObj->detectGammaRadiation();
	std::string radiationLevel = std::to_string(val1);

	EXPECT_CALL(*mockDisplay, printMessage(radiationLevel)).Times(1);			// display radiation level test
	mockDisplay->printMessage(radiationLevel);

	EXPECT_CALL(*mockObj, isRadiationLethal(radiationType, val1)).WillOnce(Return(true));  // warning lethal radiation test
	bool val2 = mockObj->isRadiationLethal(radiationType, val1);
	EXPECT_TRUE(val2);

	EXPECT_CALL(*mockBuzzer, soundAlarm());
	if (val2) {
		mockBuzzer->soundAlarm();
	}
}