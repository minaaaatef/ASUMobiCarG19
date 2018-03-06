int x=0//counter variable
int r=6//raduis of wheel
int holes=3//holes on wheel
void count()
{x=x+1;
  }
  void exact (float dist,float velocity)
  {float dist2=(2*3.14*x*r*)/holes;//distance calculated 
   float decrease=((velocity)*(velocity))/2*dist;//acceleration to  stop 
   
   while(dist2!=dist)
   {
    forward (velocity);
    velocity=velocity-decrease;
   }
  
 
    }
void setup() {
  pinMode(2,OUTPUT);//interrupt pin
  
}

void loop() {
  
  attachInterrupt(digitalPinToInterrupt(2),count,HIGH);

}
