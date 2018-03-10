#include <Servo.h>

//====================================================
//Global Variable Starts
//====================================================
const int servopin =9;
Servo ultraservo;
//====================================================
//Global Variable Ends
//====================================================

void setup() 
{
ultraservo.attach(servopin);      // attach the signal pin of servo to pin9 of arduino
}

void loop()
{
  

}


void ObstaclAevoiding()
{
  int angle =0;
  int dis;
  for(angle = 90; angle < 180; angle+=5)   
  {                                  
    ultraservo.write(angle);
    dis = ultra
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

