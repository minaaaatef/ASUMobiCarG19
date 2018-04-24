int IN1 = 3; 
int IN2 = 5; 
int IN3 = 6; 
int IN4 = 9; 
int RS=10;
int CS=12;
int LS=11;


int speed;
int direction;

void setup() 
{
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(LS,INPUT);
pinMode(RS,INPUT);
pinMode(CS,INPUT);
speed = 255/2;
 Serial.begin(9600);
}

void loop() 
{
linefollower ();
}


void forward()
{
   digitalWrite(IN1,LOW);
   analogWrite(IN2, speed);
   digitalWrite(IN3,LOW);
   analogWrite(IN4, speed);
}

void Backward()
{
   digitalWrite(IN2,LOW);
   analogWrite(IN1, speed);
   digitalWrite(IN4,LOW);
   analogWrite(IN3, speed);
}

void left()
{
   digitalWrite(IN3,LOW);
   analogWrite(IN4, speed);
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW);
}

void right()
{
   digitalWrite(IN1,LOW);
   analogWrite(IN2, speed);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
}
void stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}



void linefollower ()
{
speed=70;
   while(1)
  {
  if( (( digitalRead(LS) && digitalRead(RS) && digitalRead(CS) )||( !digitalRead(LS) && !digitalRead(RS) && digitalRead(CS) ) ))  
    {
      forward();
      Serial.write("forward");
    }

 else   if ( (!digitalRead(LS) && digitalRead(RS) ) )  
    {
      right();
      while(digitalRead(CS));
      Serial.write("right");
    }

  else   if ( ( digitalRead(LS) && !digitalRead(RS)) )  
    {
      left();
       while(digitalRead(CS));
        Serial.write("left");
    }

   else if ( ( !(digitalRead(LS)) && !(digitalRead(RS)) && !(digitalRead(CS)) ) )  
    {
     // stop();
        Serial.write("stop");
    }
    else 
    {delay(10); Serial.write("else");stop();}
    
 }
}




