#include "Arduino.h"

#ifndef PRESSURE_SENSOR_HPP
#define PRESSURE_SENSOR_HPP

class PressureSensor {
    private:
        uint8_t pin;
    public:
        float pressure;
        PressureSensor() : pin(0), pressure(0){}
        PressureSensor(uint8_t myPin) : pin(myPin), pressure(0){}
        void updatePressure();
        uint8_t getPin();
};

#endif
