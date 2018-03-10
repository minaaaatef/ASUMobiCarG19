#include <Servo.h>
//====================================================
//Global Variable Starts
//====================================================
char data;
const int MspeedPin = 3;
const int MenablePin = 4;
const int IN1=11;
const int IN2=3;
const int TrigerUltra = 8;
const int EchoUltra = 7;
const int servopin =9;
Servo ultraservo;
//====================================================
//Global Variable Ends
//====================================================

void setup() 
{
 Serial.begin(9600);

// Ultra setup starts
 pinMode(TrigerUltra, OUTPUT);
pinMode(EchoUltra, INPUT); 
digitalWrite(TrigerUltra, LOW);
// Ultra setup ends

// motors setup starts
pinMode(MspeedPin,OUTPUT);
pinMode(MenablePin,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
// motors setup ends

ultraservo.attach(servopin);      // attach the signal pin of servo to pin9 of arduino
}

  
  void loop()
{
if(Serial.available())
  {
     data = Serial.read();
     if(data=='a') Easy_drive();
  }
}

void GoRight (int degree)
{
  digitalWrite(IN2,HIGH);
  if(degree == 1 )  analogWrite(IN1,128);
  if(degree == 2 )  analogWrite(IN1,225);
}
void GoLeft (int degree)
{
  digitalWrite(IN2,LOW);
  if(degree == 1 )  analogWrite(IN1,128);
  if(degree == 2 )  analogWrite(IN1,225);
  
}
void GoStraight ()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
}




void motor(char Mdirection,int MSpeed)
{
 if (Mdirection=='f')
  {
    digitalWrite(MenablePin,HIGH);
    if (MSpeed==1) analogWrite(MspeedPin, 51);
    if (MSpeed==2) analogWrite(MspeedPin, 102);
    if (MSpeed==3) analogWrite(MspeedPin, 153);
    if (MSpeed==3) analogWrite(MspeedPin, 204);
    if (MSpeed==5) analogWrite(MspeedPin, 255);
  }
else if(Mdirection=='b')
  {
    digitalWrite(MenablePin,LOW);
    if (MSpeed==1) analogWrite(MspeedPin, 51);
    if (MSpeed==2) analogWrite(MspeedPin, 102);
    if (MSpeed==3) analogWrite(MspeedPin, 153);
    if (MSpeed==3) analogWrite(MspeedPin, 204);
    if (MSpeed==5) analogWrite(MspeedPin, 255);
  }
}

void stop ()
{
  digitalWrite(MspeedPin,LOW);
  digitalWrite(MenablePin,LOW);
}


int ultra()
{
double Time;
int Distance; 
digitalWrite(TrigerUltra, HIGH);
delayMicroseconds(10);
digitalWrite(TrigerUltra, LOW);
Time = pulseIn(EchoUltra, HIGH);
if (Time==0) return 500;
Distance= Time*0.01715;
return Distance;
}


void ObstaclAevoiding()
{
  int angle =0;
  int dis;
  for(angle = 90; angle < 180; angle+=5)   
  {                                  
    ultraservo.write(angle);
    dis = ultra();
    if (dis>400) 
    {
		ultraservo.write(90);
        if (angle<135) 
        {
          GoRight(1);
          while(dis<400){dis=ultra();}
          GoStraight();
         return;
        }
                if (angle>135) 
        {
          GoRight(2);
          while(dis<40){dis=ultra();}
          GoStraight();
          return;
        }
    }
    delay(15);                       
  }
ultraservo.write(90);
   
  for(angle = 90; angle > 0; angle-=10)   
  {                                  
    ultraservo.write(angle);
    dis = ultra();
    if (dis>400)
    {
		ultraservo.write(90);
        if (angle>45) 
        {
          GoLeft(1);
          while(dis<400){dis=ultra();}
          GoStraight();
         return;
        }
		if (angle<45) 
        {
          GoLeft(2);
          while(dis<400){dis=ultra();}
          GoStraight();
          return;
        }
    }
    delay(15);                       
  } 
  


}




void Easy_drive ()
{
  int MovingForward=0;
  int MovingBack=0;
  int dis;
  int Mspeed =1;
  while(1)
  {
  
    dis = ultra();
    if((dis<200)&&(MovingForward=1))
    {
      motor('f',2);
      ObstaclAevoiding();
	  motor('f',Mspeed);
    }
    if(Serial.available())
    {
      data = Serial.read();
      if(data=='f') {motor('f',Mspeed);MovingForward=1;}
      if(data=='b') {motor('b',Mspeed);MovingBack=1;}
      if(data=='l') GoLeft(1);
      if(data=='L') GoLeft(2);
      if(data=='r') GoRight(1);
      if(data=='R') GoRight(2);
      if(data=='S') GoStraight();
      if(data=='s') {stop();MovingBack=0;MovingForward=0;}
      if((data=='F')&&(Mspeed<5)) {Mspeed++;}
      if((data=='B')&&(Mspeed>1)) {Mspeed--;}
	    if(data=='a') {return;}
   }  
  
}
}



