void setup() {
  for(int i=13;i>=9;i--){
    pinMode(i,OUTPUT);
  }
  // put your setup code here, to run once:

}

void loop() {
  for(int i=13;i>=9;i--){
    digitalWrite(i,1);
    delay(1000);
    
  }
  // put your main code here, to run repeatedly:

}
