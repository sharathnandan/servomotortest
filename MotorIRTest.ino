// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

// Adapted by B. Frank, 2021/09/23 for Mod 1
// This sketch will check the IR sensor connected to A0 once per second; if it detects
// an object in front of the sensor it will drive the motor for one second. Otherwise it will
// turn the motor off for one second.

#include <AFMotor.h>

AF_DCMotor DCmotor(1, MOTOR12_1KHZ); // DC motor connected to M1 on motor control board
bool IRstate = false;

void setup() {

  
  Serial.begin (115200);    // set up Serial library at 115200 bps
  Serial.println("Motor test!");

  // Set motor direction
 
  DCmotor.run(RELEASE);

}

void loop() {
  uint8_t i;
  IRstate = digitalRead(A0);
  if (IRstate == false) { // If an object is in front of the sensor then turn the motor on for 1 sec
      DCmotor.run(FORWARD);
      DCmotor.setSpeed(255);
      delay(1000);
  }
  else { // turn the motor off if there is no object in front of the sensor
    DCmotor.run(RELEASE);
    delay(1000);
  }
  

}
