#include <AccelStepper.h>


// AccelStepper library from Arduino 
//  May make additional changes in the Android App for the auto UP / DOWN w/out holding the buttons



 AccelStepper stepper(AccelStepper::FULL2WIRE, 8, 9);

 int spd = 1000;    // The current speed in steps/second
 int sign = 1;      // Either 1, 0 or -1

int ledPin = 13;     For testing LED light to ensure BlueTooth connection 



 
 void setup()
 { 
  pinMode(ledPin, OUTPUT);
  ledPin = LOW; 

  
   Serial.begin(9600);
   stepper.setMaxSpeed(1000);
   stepper.setSpeed(1000);   
  
 }




 void loop()
 { 
   char c;
   if(Serial.available()) {
     c = Serial.read();

     if (c == 'a') {
        digitalWrite(13, HIGH);
     }
     if (c == 'b') {
        digitalWrite(13, LOW);
     }
      
     if (c == 'f') {  // forward
       sign = 1;
     }
     if (c == 'r') {  // reverse
       sign = -1;
     }
     if (c == 's') {  // stop
       sign = 0;
     }
     if (c == '1') {  // super slow
       spd = 10;
     }
     if (c == '2') {  // slow
       spd = 100;
     }
     if (c == '3') {  // medium
       spd = 300;
     }
        if (c == '4') {  // Fast
       spd = 500;
     }
   
        if (c == '5') {  // medium
       spd = 700;
     }
   
        if (c == '6') {  // medium
       spd = 1000;
     }
     Serial.println(c);
     stepper.setSpeed(sign * spd);
   }
   stepper.runSpeed();
 }
