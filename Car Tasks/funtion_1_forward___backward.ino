const int pin3 = 3 ;
const int pin4 = 4;
void setup() {
  // put your setup code here, to run once:
pinMode( pin3,OUTPUT);
pinMode (pin4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}
void motor ( char Mdirection , int Mspeed )
{
  if (Mdirection=='f')
  {
  digitalWrite(pin4 , 1);
   if (Mspeed ==1)
   analogWrite(pin3 ,51);
   if (Mspeed ==2)
   analogWrite(pin3,102);
   if (Mspeed==3)
   analogWrite(pin3,153);
   if(Mspeed==4)
   analogWrite(pin3,204);
   if (Mspeed==5)
   analogWrite(pin3,255);
  }
  if(Mdirection=='b')
  {
    digitalWrite(pin4, 0);
    if(Mspeed==1)
    analogWrite(pin3,51);
    if(Mspeed==2)
    analogWrite(pin3,102);
    if(Mspeed==3)
    analogWrite (pin3,153);
    if (Mspeed==4)
    analogWrite(pin3,204);
    if (Mspeed==5)
    analogWrite(pin3,255);
  }

}

