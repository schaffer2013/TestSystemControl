/*
Full Control for Single Muscle
*/

#include <Servo.h>

Servo inValveServo;
Servo outValveServo;
int inValvePin = 9;
int outValvePin = 10;

int inValvePos = 0;    // variable to store the servo position
int outValvePos = 0;

int pos=0;

int pumpPressPin=A0;
int muscPressPin=A1;
int pumpPressReading=0;
int muscPressReading=0;

void setup()
{
  inValveServo.attach(inValvePin);  // attaches the servo on pin 9 to the servo object
  outValveServo.attach(outValvePin);
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 180) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    inValveServo.write(pos);
    outValveServo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 180 ) // goes from 180 degrees to 0 degrees
  {
    inValveServo.write(pos);
    outValveServo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
  }
  pumpPressReading=readingToPSI(analogRead(pumpPressPin));
  muscPressReading=readingToPSI(analogRead(muscPressPin));
}

float readingToPSI(int reading){
  float volt=reading/1023;
  float PSI=81.879*volt-78.228;
  return PSI
}
