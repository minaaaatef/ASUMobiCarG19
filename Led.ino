int i ;
void setup() 
{
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  for (i=4;i<8;i++)
  {
 digitalWrite(i,HIGH);
 delay(1000);
 digitalWrite(i,LOW);
 delay(1000);
  }
}
