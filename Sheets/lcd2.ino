#include <LiquidCrystal.h>
LiquidCrystal LCD1(8,9,4,5,6,7);
float temp;
const int LM =A0;
void setup() {
  LCD1.begin(16,2);
  
  // put your setup code here, to run once:

}

void loop() {
  temp= analogRead(LM);
  temp = (5*temp*100)/1024;
  LCD1.setCursor(6,0);
  LCD1.print(temp);
  
  // put your main code here, to run repeatedly:

}
