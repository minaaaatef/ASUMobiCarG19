
// stopcar
const int pin2,pin3;

void setup() {
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  

}

void stopcar() {

  digitalWrite(pin2,0);
  digitalWrite(pin3,0);

}
