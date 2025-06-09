#include "Arduino.h"
#include "SensorArduino.hpp"
#include "PressureSensor.hpp"

#define SLAVE_ADDRESS 0x04

const int BAUD = 19200;
const int SEND_DATA_COMMAND = 255;

//SensorArduino sensor_arduino;

void setup() {
  Serial.begin(BAUD);
//  sensor_arduino.registerSensors();
  int pin = 14;
  PressureSensor *pressures;
  pressures = new PressureSensor[1];
  pressures[0] = PressureSensor(14);
  PressureSensor temp;
  Serial.println(temp.getPin());
  Serial.println(pressures[0].getPin());
  Serial.println(pressures[0].getPin());
  Serial.println("AAAAAAAAAAA"); 
}

void loop() {
//  Serial.println("Looping");
//  sensor_arduino.update();
//  if(Serial.available()){
//    int data = Serial.read();
//    if(data == SEND_DATA_COMMAND){
//      sensor_arduino.read();
//    }
//  }
//  delay(100);
}
