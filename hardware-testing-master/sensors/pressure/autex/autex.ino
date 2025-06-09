// Constants - need to configure these based on the pressure sensor
float MIN_PSI = 15;
float MAX_PSI = 1000;
float MIN_VOLTAGE = 0.5;
float MAX_VOLTAGE = 4.5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float psi = get_pressure(sensorVal);
  Serial.print("\tPressure: ");
  Serial.print(psi);
  Serial.println(" psi");  
  delay(100);
}

float map_val(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float get_pressure(int sensor_val) {
//  float voltage_diff = MAX_VOLTAGE - MIN_VOLTAGE;
//  float psi_diff = MAX_PSI - MIN_PSI;
//  float psi = (voltage - MIN_VOLTAGE) * (psi_diff / voltage_diff) + MIN_PSI;
//  float psi = map(0.65, MIN_VOLTAGE, MAX_VOLTAGE, MIN_PSI, MAX_PSI);
  float voltage = map_val(sensor_val, 0.00, 1024.00, 0.00, 5.00) + 0.0100;
  float psi = map_val(voltage, MIN_VOLTAGE, MAX_VOLTAGE, MIN_PSI, MAX_PSI);
  psi -= MIN_PSI;
  return psi;
}
