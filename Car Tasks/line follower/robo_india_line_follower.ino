// declaring Shield
int dataPin = 8;        
int latchPin = 12;
int clockPin = 4;
int en = 7;
// declaring Sensor Pins.
int LeftSensor = A1;
int RightSensor = A0; 
int L_sensor_val = 0; // To store value from sensors. 
int R_sensor_val = 0; 

int threshold = 300; // Threshold value to distinguish black and white. 

void setup()
{   // setting up shield. 
    pinMode(dataPin, OUTPUT);      
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(en, OUTPUT);    
    digitalWrite(en, LOW);   

}

void loop()
{
L_sensor_val =  analogRead(LeftSensor);   // Reading Left sensor data
R_sensor_val =  analogRead(RightSensor);  // Reading Right sensor data


  if(L_sensor_val<threshold && R_sensor_val>threshold) {  // testing for left turn
    while (L_sensor_val<threshold && R_sensor_val>threshold){
      turn_right();  
      L_sensor_val =  analogRead(LeftSensor);
      R_sensor_val =  analogRead(RightSensor);
    }
  }
  else if(L_sensor_val>threshold && R_sensor_val<threshold){  // tesing for right turn
    while (L_sensor_val>threshold && R_sensor_val<threshold){
      turn_left();
      L_sensor_val =  analogRead(LeftSensor);
      R_sensor_val =  analogRead(RightSensor);
    }
 }
forward(); // Default movement is forward.
}

void forward(void){  // function for forward movement. 
        digitalWrite(latchPin, LOW);            
        shiftOut(dataPin, clockPin, LSBFIRST, 3);
        digitalWrite(latchPin, HIGH);  

}

void backward(void){   // function for forward movement. 
        digitalWrite(latchPin, LOW);            
        shiftOut(dataPin, clockPin, LSBFIRST, 164);
        digitalWrite(latchPin, HIGH);  
}

void turn_left(void){   // function for left turn. 
        digitalWrite(latchPin, LOW);            
        shiftOut(dataPin, clockPin, LSBFIRST, 161);
        digitalWrite(latchPin, HIGH);  
}

void turn_right(void){   // function for Right turn. 
        digitalWrite(latchPin, LOW);            
        shiftOut(dataPin, clockPin, LSBFIRST, 38);
        digitalWrite(latchPin, HIGH);  
}

void halt(void){        // function for stopping robot. 
        digitalWrite(latchPin, LOW);             
        shiftOut(dataPin, clockPin, LSBFIRST, 32);
        digitalWrite(latchPin, HIGH);  
}

