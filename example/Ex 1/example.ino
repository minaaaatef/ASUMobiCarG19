const int led=12;
const int ldr=13;
int sw;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  sw=digitalRead(13);
  if(sw==1)
  {
    digitalWrite(led,1);
    
  }
  else{
    digitalWrite(led,0);
  }
  // put your main code here, to run repeatedly:

}
