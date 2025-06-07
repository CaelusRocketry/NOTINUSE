#include <queue>
#include <string>
#include "Arduino.h"
#include <SD.h>
#include <HX711.h>
#include <Adafruit_MAX31856.h>



#define DELAY 500 // millis
#define NUM_VALVES 6

// Enums
enum ValveFlagState {
  NOTHING,
  OPEN,
  CLOSED,
};
using namespace std;

// Telem variables
queue<string> send_queue;
queue<string> ingest_queue;
string rcvd;

// Pressure variables
const int num_pressure_pins = 8;
int pressure_pins[] = {22, 23, 21, 20, 19, 38, 37, 14}; // PT 1-8
// int pressure_pins[] = {22, 23, 21, 20, 19, 38, 37, 14, 15, 16, 17, 18}; all 12 pins
int pressure_vals[num_pressure_pins];
int initial_pressures[num_pressure_pins];
int pressure_objs[num_pressure_pins];

// Thermo variables
const int num_thermo_pins = 4;
int thermo_pins[][4] = {{33, 0, 1, 32}, {34, 0, 1, 32}, {2, 0, 1, 32}, {31, 0, 1, 32}};
int thermo_vals[num_thermo_pins];
int initial_temps[num_thermo_pins];

// it's low IQ just go w it im not fighting arduino syntax
Adafruit_MAX31856 maxthermo1(thermo_pins[0][0], thermo_pins[0][1], thermo_pins[0][2], thermo_pins[0][3]);
Adafruit_MAX31856 maxthermo2(thermo_pins[1][0], thermo_pins[1][1], thermo_pins[1][2], thermo_pins[1][3]);
Adafruit_MAX31856 maxthermo3(thermo_pins[2][0], thermo_pins[2][1], thermo_pins[2][2], thermo_pins[2][3]);
Adafruit_MAX31856 maxthermo4(thermo_pins[3][0], thermo_pins[3][1], thermo_pins[3][2], thermo_pins[3][3]);
Adafruit_MAX31856 thermo_objs[] = {maxthermo1, maxthermo2, maxthermo3, maxthermo4};

// Load variables
const int num_load_cells = 3; // TODO: check load cell pin config
int load_pins[][3] = {
  {25, 26}, // U25 - 26, 25    not sure about order, if it doesnt work then reverse it
  {27, 28}, // U36 - 28, 27 not sure about order, if it doesnt work then reverse it 
  {29, 30} // U46 30, 29
};
int load_vals[num_load_cells];
int initial_thrust[num_load_cells];

// also low IQ but j go w it im not fighting arduino syntax
HX711 load1;
HX711 load2;
HX711 load3;

HX711 load_objs[] = {load1, load2, load3};
int calibration_factor = -7050;

// Valve stuff
const int num_solenoids = 6;
int solenoid_vals[] = {0, 0, 0, 0, 1, 0};

// Global variables
long start_time = 0;
long sensor_last_sent;
long valve_last_sent;

// Valve variables
int valve_pins[] = {2, 3, 4, 5, 6, 7};
ValveFlagState flag_stuff[NUM_VALVES];
bool valve_states[NUM_VALVES]; // OPEN = true, CLOSED = false

// HardwareSerial xbee = Serial3;
int led_state = 0;
long zero_factor = 0;

void setup() {
  // pinMode(13, OUTPUT);
  // digitalWrite(13, HIGH); 
  
  Serial.begin(9600);

  if(!SD.begin(BUILTIN_SDCARD)){
    Serial.println("Init failed");
    while(true) {
      Serial.println("youre bad");
    }
  }
  
  start_time = millis();

  for(int i = 0; i < num_pressure_pins; i++){
    pinMode(pressure_pins[i], INPUT);
    initial_pressures[i] = 0;
    pressure_vals[i] = 0;
  }

  for(int i = 0; i < num_thermo_pins; i++){
    initial_temps[i] = 0;
    thermo_vals[i] = 0;

    /// A;SLKFJASLKDFJ;LASKDFJ;SLDKFJ;SLKDFJ no default constructor
    thermo_objs[i].begin();
  }
  
  for(int i = 0; i < num_load_cells; i++){
    initial_thrust[i] = 0;
    load_vals[i] = 0;
    
    load_objs[i].begin(load_pins[i][0], load_pins[i][1]);
    
    load_objs[i].set_scale();
    
    load_objs[i].tare();   //<-- doesnt work?????? why doesnt this work???
  }

  Serial3.begin(9600);
}

void saveData(string message){
  File savefile;
  savefile = SD.open("blackbox.txt", FILE_WRITE);
  if(savefile){
    Serial.println("Saving");
    savefile.println(message.c_str());
    savefile.close();
  }else{
    Serial.println("Couldn't save to blackbox.txt");
  }
}

float map_value(float x, float in_min, float in_max, float out_min, float out_max) {
    float in_width = in_max - in_min;
    float out_width = out_max - out_min;
    float factor = out_width / in_width;
    return (x - in_min) * factor + out_min;
}

float readPressureSensor(int pin){
    float pwmVal = analogRead(pin);
    // float voltage = map_value(pwmVal, 0, 1024, 0.5, 4.5) + 0.0100;
    // float psi = map_value(voltage, 0.5, 4.5, 15, 1000) - 15;
    return pwmVal;
}

void pressureRead(){
  for(int i = 0; i < num_pressure_pins; i++){
    float val = readPressureSensor(pressure_pins[i]);
    pressure_vals[i] = val;
  }
}

void thermoRead(){
  for(int i = 0; i < num_thermo_pins; i++){
    float val = thermo_objs[i].readThermocoupleTemperature();
    thermo_vals[i] = val;
  }
}

void loadRead(){
  for(int i = 0; i < num_load_cells; i++){
    load_objs[i].set_scale(calibration_factor);
    float val = load_objs[i].get_units();

    if(val < 0) {
      val *= -1;
    }

    load_vals[i] = val;
  }
}

void xbeeRead(){
  while(Serial3.available()){
    char msg = Serial3.read();
    string msg_str(1, msg);
    rcvd.append(msg_str);
    
  }
  Serial.println(("XBee: Recieved: " + rcvd).c_str());

  size_t packet_start = rcvd.find('^');
  if(packet_start != string::npos) {
      size_t packet_end = rcvd.find('$', packet_start);
      if (packet_end != string::npos) {
          string incoming_packet = rcvd.substr(packet_start + 1, packet_end - packet_start - 1);
          Serial.println(("XBee: Received Full Packet: " + incoming_packet).c_str());
          
          ingest_queue.push(incoming_packet);

          rcvd = rcvd.substr(packet_end + 1);
      }
  }

}

string hex(long w) {
  if(w == 0) {
    return "0";
  }
    bool negative = false;
    if(w < 0){
        w = -w;
        negative = true;
    }

    size_t hex_len = sizeof(long) << 1;
    static const char* digits = "0123456789ABCDEF";
    std::string ret(hex_len,'0');
    
    for (size_t i = 0, j = (hex_len - 1) * 4; i < hex_len; ++i, j -= 4) {
        ret[i] = digits[(w >> j) & 0x0f];
    }
    
    int start = 0;
    
    while(ret[start] == '0') {
        start++;
    }
    
    string to_return_final = ret.substr(start);
    
    if(to_return_final == "") {
        return "0";
    } 
    else {
        if(negative){
          to_return_final = "-" + to_return_final;
        }
        return to_return_final;
    }
}

string generateChecksum(string packet) {
  int ascii_sum = 0;
    for (int i = 0; i < packet.length(); i++) {
        ascii_sum += i * (int)(packet[i]);
    }
    // Modulus of 999 restricts the checksum to three digits
    return hex(ascii_sum % 999);
}

void sensorControl(){
  if(millis() - sensor_last_sent > DELAY) {

    string data = "DAT|" + hex(millis()) + "|";
    for(int i = 0; i < num_pressure_pins; i++) {
      data += "1";
      if(i == 5) {
        data += "P";  
      }
      else {
        data += hex(static_cast<long>(i + 1));
      }

      data += hex(static_cast<long>(pressure_vals[i]));
      data += ",";
    }

    // read from thermo vals
    for(int i = 0; i < num_thermo_pins; i++) { 
      string locations = "9ABC";
      data += "0";
      data += locations[i];
      data += hex(static_cast<long>(thermo_vals[i]));
      data += ",";
      Serial.println(static_cast<long>(thermo_vals[i]));
      Serial.println("ooga booga");
    }

    //read from load vals
    for(int i = 0; i < num_load_cells; i++) {
      string locations = "DEF";
      data += "2";
      data += locations[i];
      data += hex(static_cast<long>(load_vals[i]));
      data += ",";
    }

    data = data.substr(0, data.length()-1);

    send_queue.push(data);
    sensor_last_sent = millis();
  }
}

void valveControl() {
  if(millis() - valve_last_sent > DELAY) {
    string data = "VDT|" + hex(millis()) + "|";

    for(int i = 0; i < num_solenoids; i++) {
      data += "0";
      data += hex(static_cast<long>(i + 1));
      data += hex(static_cast<long>(solenoid_vals[i]));
      data += ",";
    }

    string mod_data = data.substr(0, data.length()-1);

    send_queue.push(mod_data);
    valve_last_sent = millis();
  }
}

void telemControl(){
  while(!(ingest_queue.empty())){
    string packet = ingest_queue.front();
    ingest_queue.pop();

    packet = packet.substr(1, packet.size()-1); //Gets rid of ^ and $ at beginning/end of packet 
    const int numDelimiters = 3;
    string tokens[4] = {};
    for(int i=0; i<numDelimiters; i++){
      int delimIdx = packet.find("|");
      tokens[i] = packet.substr(0, delimIdx);
      packet = packet.substr(delimIdx+1);
    }
    tokens[3] = packet;
    string header = tokens[0]; 
    string msg = tokens[2];
    //Need try-catch here?
    if(header == "SAC") {
      char const *msg_converted = msg.c_str();
      int valve_location = static_cast<int>(msg_converted[0]);
      ValveFlagState actuation_type = static_cast<ValveFlagState>(msg_converted[1]);
      flag_stuff[valve_location] = actuation_type;
    }
    else if(header == "HRT"){
      string heartbeat = "HRT|"  + hex(millis()) + "OK";
      send_queue.push(heartbeat);
    }
    else{
      continue; //Ignore packet if header is unrecognized
    }
  }
}


void pressureControl(){
  
}

void stageControl(){
  
}

void valveActuate(){
  for(int i = 0; i < NUM_VALVES; i++){
    if(flag_stuff[i] == NOTHING){
      continue;
    }
    if(flag_stuff[i] == OPEN && valve_states[i] == false){
      // TODO: Do NO instead of just NC
      digitalWrite(valve_pins[i], HIGH);
    }
    else if(flag_stuff[i] == CLOSED && valve_states[i] == true){
      // TODO: Do NO instead of just NC
      digitalWrite(valve_pins[i], LOW);
    }
  }
}

void telemActuate(){
  while (!(send_queue.empty())) {
      string checksum = generateChecksum(send_queue.front());
      string to_send = "^" + send_queue.front() + "|" + checksum + "$";
      send_queue.pop();

      saveData(to_send); // TODO: find a better place to put this

      char const *c = to_send.c_str();
      Serial.println(("\nSENDING PACKET: " + to_send).c_str());
      Serial3.write(c);
  }

}



int main(int argc, char** argv) {
  setup();
  Serial.println("Running MCL uwu");

  while(true) {
    Serial.println("iteration");
    pressureRead();
    
    thermoRead();
    
    loadRead();
    xbeeRead();
    

    sensorControl();
    valveControl();
    // TODO: TelemControl
    telemControl();
    // TODO: PressureControl
    pressureControl();
    // TODO: StageControl
    stageControl();

    // TODO: ValveActuate
    valveActuate();
    telemActuate();

    // Save registry to file
    delay(50);
    // digitalWrite(13, led_state);
    
    if(led_state == 0) {
      led_state = 1;
    }
    else {
      led_state = 0;
    }
  }

}
