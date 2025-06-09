#include "Arduino.h"
#include "PressureSensor.hpp"

#ifndef SENSOR_ARDUINO_HPP
#define SENSOR_ARDUINO_HPP

class SensorArduino {
  private:
    // these maps map the pin to its respective sensor
    int num_pressures;

    // send data to pi every 50 milliseconds
    const int SEND_DELAY = 50;

    int recvSerialByte();
    bool registered = false;

  public:
    SensorArduino();
    ~SensorArduino();
    PressureSensor *pressure_sensors;
    void registerSensors();
    void read();
    void update();
    void sendData(int pin, float val);
    void error();
};

#endif
