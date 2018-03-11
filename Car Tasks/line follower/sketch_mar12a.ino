

#define LS 5 // Left Sensor
#define RS 6 // Right Sensor
#define LM1 8
#define LM2 9
#define RM1 10
#define RM2 11






void setup() {
  // put your setup code here, to run once:
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}


     

void right() {
 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

}

