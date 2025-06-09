#include "SensorArduino.hpp"

SensorArduino::SensorArduino() {
    pinMode(13, OUTPUT);
    registered = false;
}

// TODO: make sure that the format matches what the pi is sending
// format: num_sensors, num_pressures, <for each sensor> pin
// example: 1, 14

int SensorArduino::recvSerialByte(){
    while(!Serial.available()){}
    int ret = Serial.read();
    Serial.write(ret);
    return ret;
}

void SensorArduino::registerSensors() {
    // int num_sensors = recvSerialByte();
    int num_sensors = 1;
    this->num_pressures = num_sensors;

    Serial.println(num_sensors);

    int pressure_len = 0;

    this->pressure_sensors[num_pressures];

    for(int i = 0; i < num_sensors; i++) {
        // int pin = recvSerialByte();
        int pin = 14;
        Serial.println(pin);
        this->pressure_sensors[pressure_len] = PressureSensor(pin);
        pinMode(pin, OUTPUT);
        Serial.println(pressure_sensors[0].getPin());
        Serial.println(pressure_sensors[0].getPin());
        Serial.println("AAAAAAAAAAA");
        pressure_len++;
    }
    registered = true;
    Serial.println(pressure_sensors[0].getPin());
}

void SensorArduino::update(){
    Serial.println("Updating");
    Serial.println(pressure_sensors[0].getPin());
    if(!registered){
        return;
    }
    for(int i = 0; i < num_pressures; i++) {
        pressure_sensors[i].updatePressure();
    }
}

void SensorArduino::read() {
    for(int i = 0; i < this->num_pressures; i++) {
        sendData(this->pressure_sensors[i].getPin(), pressure_sensors[i].pressure);
    }
}

void SensorArduino::sendData(int pin, float val) {
    union cvt {
        float val;
        unsigned char byte_array[4];
    } x;
    x.val = val;

    Serial.println(pin);
    Serial.write(pin);
    // Serial.print(x.byte_array);
}

// Visual error for testing, turns LED on pin 13 on if there's an error
void SensorArduino::error(){
    digitalWrite(13, HIGH);
}

SensorArduino::~SensorArduino() {
    delete[] pressure_sensors;
}
