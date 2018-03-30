int m1f=13;
int m1b=12;
int m2f=11;
int m2b=4;
int sw1f,sw1b,sw2f,sw2b;
void setup() {
  pinMode  (13,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (4,OUTPUT);
 pinMode (9,INPUT);
 pinMode (8,INPUT);
  pinMode (7,INPUT);
  pinMode (6,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  sw1f=digitalRead(9);
  sw1b=digitalRead(8);
  sw2f=digitalRead(7);
  sw2b=digitalRead(6);
  if(sw1f==1)
  {
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(4,0);
  }
  else if (sw1b==1)
  {
     digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(4,1);

  }
  else if (sw2f==1)
  {
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(4,1);
  }
  else if (sw2b==1) {
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(4,0);
    
  }
  else{
    digitalWrite(13,0);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(4,0);
    
  }
  // put your main code here, to run repeatedly:

}
