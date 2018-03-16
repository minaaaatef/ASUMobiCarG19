#include <Servo.h>
//====================================================
//Global Variable Starts
//====================================================
char data;
const int IN1 = 3;
const int IN2 = 5;
const int IN3=6;
const int IN4=11;
const int TrigerUltra = 8;
const int EchoUltra = 9;
const int servopin =13;
Servo ultraservo;
int dis1;
//====================================================
//Global Variable Ends
//====================================================

void setup() 
{
 Serial.begin(9600);

// Ultra setup start
 pinMode(TrigerUltra, OUTPUT);
pinMode(EchoUltra, INPUT); 
digitalWrite(TrigerUltra, LOW);
// Ultra setup ends
// motors setup starts
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
// motors setup ends

ultraservo.attach(13);      // attach the signal pin of servo to pin9 of arduino
ultraservo.write(90);
}

  
  void loop()
{
  
  Serial.write('a');
if(Serial.available())
  {
     data = Serial.read();
     if(data=='a') Easy_drive();
  }
  
  // dis1 = ultra();
 // Serial.write(dis1);
  //delay(5000);




  
//  delay(1000);
//ultraservo.write(10);
}

void GoRight (int degree)
{
  digitalWrite(IN3,LOW);
  if(degree == 1 )  analogWrite(IN4,128);
  if(degree == 2 )  analogWrite(IN4,225);
}

void GoLeft (int degree)
{
  digitalWrite(IN4,LOW);
  if(degree == 1 )  analogWrite(IN3,128);
  if(degree == 2 )  analogWrite(IN3,225);
  
}
void GoStraight ()
{
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
}




void motor(char Mdirection,int MSpeed)
{
 if (Mdirection=='f')
  {
    digitalWrite(IN1,LOW);
   
    if (MSpeed==1) analogWrite(IN2, 51);
    if (MSpeed==2) analogWrite(IN2, 102);
    if (MSpeed==3) analogWrite(IN2, 153);
    if (MSpeed==3) analogWrite(IN2, 204);
    if (MSpeed==5) analogWrite(IN2, 255);
    
  }
else if(Mdirection=='b')
  {
    digitalWrite(IN2,LOW);
    if (MSpeed==1) analogWrite(IN1, 51);
    if (MSpeed==2) analogWrite(IN1, 102);
    if (MSpeed==3) analogWrite(IN1, 153);
    if (MSpeed==3) analogWrite(IN1, 204);
    if (MSpeed==5) analogWrite(IN1, 255);
  }
}

void stop ()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
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
          delay(1000);
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
    if(MovingForward==1)
    {
      if (dis<200)
    {
      motor('f',2);
      ObstaclAevoiding();
	  motor('f',Mspeed);
    }
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



