
#define trigPin 10
#define echoPin 12
#include <AFMotor.h>


int sound = 250;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(115200); 
 motor1.setSpeed(200);
 motor2.setSpeed(200);
 motor3.setSpeed(200);
 motor4.setSpeed(200);
 
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);


}

void loop() {
 uint8_t i;
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;


 if (distance <= 10) {
   
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
   motor3.run(BACKWARD);
   motor4.run(BACKWARD);
   delay(100);
}
 else {
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);
   delay(10);
 }
 

