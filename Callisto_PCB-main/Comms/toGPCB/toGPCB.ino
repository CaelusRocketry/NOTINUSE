char incomingByte = ""; // for incoming serial data
String incomingBytes = "";
int d1num = 0;
int d2num = 0;
int d3num = 0;
int d4num = 0;

int pins[16];

int readPls = 0;
void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600); 
  Serial.begin(9600);}


void loop() {
  
  // send data only when you receive data:
  if (Serial3.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial3.read();
    
    // say what you got:
    Serial3.println(incomingByte);
    if(incomingByte == 'p'){
      readPls = 1;
    }
    if(incomingByte == 'q'){
      readPls = 0;
      incomingBytes.concat(incomingByte);
      if(incomingBytes.length() == 6){
        if(incomingBytes.charAt(1) >= 97){d1num = incomingBytes.charAt(1) - 87;} else{d1num = incomingBytes.charAt(1) - 48;}
        if(incomingBytes.charAt(2) >= 97){d2num = incomingBytes.charAt(2) - 87;} else{d2num = incomingBytes.charAt(2) - 48;}
        if(incomingBytes.charAt(3) >= 97){d3num = incomingBytes.charAt(3) - 87;} else{d3num = incomingBytes.charAt(3) - 48;}
        if(incomingBytes.charAt(4) >= 97){d4num = incomingBytes.charAt(4) - 87;} else{d4num = incomingBytes.charAt(4) - 48;}

        pins[0] = d1num/8;pins[1] = (d1num-pins[0]*8)/4;pins[2] = (d1num-pins[0]*8-pins[1]*4)/2; pins[3] = d1num%2;
        pins[4] = d2num/8;pins[5] = (d2num-pins[4]*8)/4;pins[6] = (d2num-pins[4]*8-pins[5]*4)/2; pins[7] = d2num%2;
        pins[8] = d3num/8;pins[9] = (d3num-pins[8]*8)/4;pins[10] = (d3num-pins[8]*8-pins[9]*4)/2; pins[11] = d3num%2;
        pins[12] = d4num/8;pins[13] = (d4num-pins[12]*8)/4;pins[14] = (d4num-pins[12]*8-pins[13]*4)/2; pins[15] = d4num%2;
        
        Serial.print(String(pins[0])+String(pins[1])+String(pins[2])+String(pins[3]));Serial.print(" ");
        Serial.print(String(pins[4])+String(pins[5])+String(pins[6])+String(pins[7]));Serial.print(" ");
        Serial.print(String(pins[8])+String(pins[9])+String(pins[10])+String(pins[11]));Serial.print(" ");
        Serial.print(String(pins[12])+String(pins[13])+String(pins[14])+String(pins[15]));Serial.println();
        
        
        
      }
      incomingBytes = "";
    }
    if(readPls == 1){
      incomingBytes.concat(incomingByte);
    }
  }
  delay(2);
}
