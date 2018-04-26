int channel_A_pin = 0 ;
void setup() {
 Serial.begin(115200);

}

void loop() {
int value = analogRead (channel_A_pin); 
value = ( value >> 2)& 0xFF ;
Serial.print(value , BYTE );
delayMicroseconds(100); 

}
