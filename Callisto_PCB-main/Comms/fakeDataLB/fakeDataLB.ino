int s1 = 1;
int s2 = 1;
int s3 = 1;
int s4 = 1;

int s5 = 1;
int s6 = 0;
int s7 = 1;
int s8 = 0;

int s9 = 1;
int s10 = 1;
int s11 = 0;
int s12 = 0;

int s13 = 1;
int s14 = 1;
int s15 = 1;
int s16 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  String d1 = String(s1*8 + s2*4 + s3*2 + s4,HEX);
  String d2 = String(s5*8 + s6*4 + s7*2 + s8,HEX);
  String d3 = String(s9*8 + s10*4 + s11*2 + s12,HEX);
  String d4 = String(s13*8 + s14*4 + s15*2 + s16,HEX);
  
  Serial3.println("p"+d1+d2+d3+d4+"q"); 
  delay(50);
}
