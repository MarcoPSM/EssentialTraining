
// TemperatureSensor.h
class TemperatureSensor {
  public:
    virtual ~TemperatureSensor() {}
    virtual float readTemperature() = 0; // Interface
};

// Fan.h
class Fan {
  public:
    void turnOn();
    void turnOff();
    bool isOn() const;

  private:
    bool on = false;
};

// TemperatureController.h
class TemperatureController {
  public:
    TemperatureController(TemperatureSensor &sensor, Fan &fan)
        : sensor(sensor), fan(fan) {}

    void checkTemperature() {
        float temp = sensor.readTemperature();
        if (temp > 25.0) {
            fan.turnOn();
        } else {
            fan.turnOff();
        }
    }

  private:
    TemperatureSensor &sensor;
    Fan &fan;
};
