
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "Fan.h"
#include "TemperatureController.cpp"

// Mock do sensor
class MockTemperatureSensor : public TemperatureSensor {
  public:
    float readTemperature() override {
        return mock().actualCall("readTemperature").returnDoubleValue();
    }
};

TEST_GROUP(TemperatureControllerTests) {
    Fan fan;
    MockTemperatureSensor sensor;
    TemperatureController *controller;

    void setup() { controller = new TemperatureController(sensor, fan); }

    void teardown() {
        delete controller;
        mock().clear();
    }
};

TEST(TemperatureControllerTests, TurnsFanOnWhenTempAbove25) {
    mock().expectOneCall("readTemperature").andReturnValue(30.0);
    controller->checkTemperature();
    CHECK_TRUE(fan.isOn());
}

TEST(TemperatureControllerTests, TurnsFanOffWhenTempBelow25) {
    mock().expectOneCall("readTemperature").andReturnValue(20.0);
    controller->checkTemperature();
    CHECK_FALSE(fan.isOn());
}
