 const int IN1=11;
 const int IN2=3;

void setup() {

 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);

}

void goright (int degree)
{
  digitalWrite(IN2,HIGH);
  if(degree == 1)
  analogWrite(IN1,128);
  if(degree == 2 )
 
  analogWrite(IN1,225);
}
void goleft (int degree)
{
  digitalWrite(IN2,LOW);
  if(degree == 1)
  analogWrite(IN1,128);
  if(degree == 2 )
 
  analogWrite(IN1,225);
  
}
void gostraight ()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
}


