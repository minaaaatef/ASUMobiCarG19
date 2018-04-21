 int motorpin = 11 ;
void setup() {
 pinMode ( motorpin ,OUTPUT);
 analogWrite(motorpin,0);
 Serial.begin(9600);

}

void loop() {
  if(Serial.available())
{
 char ch = Serial.read();
 if(ch>='0'&&ch<='9')
 {
  int speed =ch-'0';
  analogWrite(motorpin,speed*28);
 }
}
}
