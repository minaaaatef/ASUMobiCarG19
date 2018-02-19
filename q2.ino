int yellow =4;
int green=5;
int red=6;
int blue=7;
void setup() {
  pinMode (yellow,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (red,OUTPUT);
  pinMode (blue,OUTPUT);
  

}

void loop() {
  digitalWrite (yellow,HIGH);
  digitalWrite (green,LOW);
  digitalWrite (red,LOW);
  digitalWrite (blue,LOW);
  delay(1000);
  digitalWrite (yellow,LOW);
 digitalWrite (green,HIGH);
  digitalWrite (red,LOW);
  digitalWrite (blue,LOW);
  delay(1000);
 
   digitalWrite (yellow,LOW);
 digitalWrite (green,LOW);
  digitalWrite (red,HIGH);
  digitalWrite (blue,LOW);
  delay(1000);
   digitalWrite (yellow,LOW);
 digitalWrite (green,LOW);
  digitalWrite (red,LOW);
  digitalWrite (blue,HIGH);
  delay(1000);
}
