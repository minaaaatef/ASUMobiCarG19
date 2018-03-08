int TriggerPin =9;
int EchoPin =10;
float distance;
long period;

void setup() {
  pinMode (TriggerPin,OUTPUT);
  pinMode (EchoPin,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin,LOW);
  period= pulseIn(EchoPin,HIGH);
  distance=period*0.034/2;
  Serial.println(distance);
  
  // put your main code here, to run repeatedly:

}
