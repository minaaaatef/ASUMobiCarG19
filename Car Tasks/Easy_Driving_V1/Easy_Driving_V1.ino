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

int L = ;
int R = ; 
int C = ; 
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
// line follower setup starts 
pinMode(L,INPUT);
pinMode(R,INPUT);
pinMode(C,INPUT);
// line follower setup ends



ultraservo.attach(13);      // attach the signal pin of servo to pin9 of arduino
ultraservo.write(0);
delay(500);
ultraservo.write(90);
delay(500);
ultraservo.write(180);
delay(500);
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

 /*

int test;
test=freesearching();
Serial.print(test, DEC);
ultraservo.write(90);
delay(100);
 */ 
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

/*
void ObstaclAevoiding()
{
  int angle =0;
  int dis;
  for(angle = 90; angle < 180; angle+=5)   
  {                                  
    ultraservo.write(angle);
    dis = ultra();
    if (dis>200) 
    {
		ultraservo.write(90);
     delay (100);
        if (angle<135) 
        {
          GoRight(1);
           dis = ultra();
          while(dis<300)
          {
            dis=ultra();
           if (dis<100){stop();break;} 
          }
        //  delay(1000);
          GoStraight();
         return;
        }
                if (angle>135) 
        {
          GoRight(2);
          dis = ultra();
          while(dis<300)
          {
            dis=ultra();
           if (dis<100){stop();break;} 
          }
          GoStraight();
          return;
        }
    }
    delay(15);                       
  }
ultraservo.write(90);
   
  for(angle = 90; angle > 0; angle-=5)   
  {                                  
    ultraservo.write(angle);
    dis = ultra();
    if (dis>200)
    {
		ultraservo.write(90);
   delay (100);
        if (angle>45) 
        {
          GoLeft(1);
          dis = ultra();
          while(dis<300)
          {
            dis=ultra();
           if (dis<100){stop();break;} 
          }
          GoStraight();
         return;
        }
		if (angle<45) 
        {
          GoLeft(2);
          dis = ultra();
              while(dis<300)
          {
            dis=ultra();
           if (dis<100){stop();break;} 
          }
          GoStraight();
          return;
        }
    }
    delay(15);                       
  } 
  


}

*/


int freesearching()
{
int x,test;
for(x=0;x<180;x+=30)
{
  ultraservo.write(x);
delay(200);
test=ultra();
if (test>400) return x;
}
stop();
}


void obsticle ()
{
  int x = freesearching();
  ultraservo.write(90);
  Serial.print(x,DEC);
  Serial.print("/n");
  if (x<60) {GoLeft(2);return;}
  if (x<90) {GoLeft(1);return;}
  if (x=90) {return;}
  if (x<120) {GoRight(1);return;}
  if (x>120) {GoRight(2);return;}
  delay(5000);
  GoStraight();
}



void Easy_drive ()
{
  int MovingForward=0;
  int MovingBack=0;
  int dis;
  int Mspeed =2;
  while(1)
  {
    if(MovingForward==1)
    {
    dis=ultra();
    if(dis<70) stop();
    if(dis>70&&dis<300) obsticle();
    GoStraight();
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

void linefollower ()
{
  motor('f',2);
  if(digitalRead(L)==1)
  {
    GoLeft(2);
    while(digitalRead(C)==0){delay(50);}
    GoStraight;
  }
    if(digitalRead(R)==1)
  {
    GoRight(2);
    while(digitalRead(C)==0){delay(50;}
    GoStraight;
  }
}



