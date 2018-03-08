int x=0;//counter variable
int r=6;//raduis of wheel
int holes=3;//holes on wheel
void count()
{x=x+1;
  }
  void exact (float dist)
  {
    int n=(dist/2*3.14*r)*holes;
   motor (f,4);
   if(x==0.90*(float)n)
   {motor (f,2);
   }

    if (x==n)
      stopcar();
    }
void setup() {
  pinMode(2,OUTPUT);//interrupt pin
  
}

void loop() {
  
  attachInterrupt(digitalPinToInterrupt(2),count,HIGH);

}
