#include "PressureSensor.hpp"

#define MAX_PRESSURE 1000
#define ROOM_PRESSURE 15

void PressureSensor::updatePressure() {
    Serial.println(this->pin);
}

uint8_t PressureSensor::getPin(){
    return this->pin;
}
