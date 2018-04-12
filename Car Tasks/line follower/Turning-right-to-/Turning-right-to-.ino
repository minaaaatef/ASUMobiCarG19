int L = ;
int R = ; 
int C = ; 

void setup() 
{
pinMode(L,INPUT);
pinMode(R,INPUT);
pinMode(C,INPUT);
}

void loop() {

}

void linefollower ()
{
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

