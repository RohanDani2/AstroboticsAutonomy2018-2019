#include <Servo.h>
#include <ESC.h>

/* This example shows how to use an ESC controller that can go
 * forward and backard
 */

ESC esc(ESC::MODE_FORWARD_BACKWARD);

void setup() 
{
  esc.attach(2);
} 
 
void loop() 
{ 
    esc.setSpeed(0);
    esc.setDirection(ESC::FORWARD);
    esc.setSpeed(100);
    delay(1000);
    esc.setSpeed(0);
    esc.setDirection(ESC::BACKWARD);
    esc.setSpeed(100);
    delay(1000);
} 



//#include <Servo.h>//Using servo library to control ESC
//
//Servo esc; //Creating a servo class with name as esc
//
//void setup()
//
//{
//
//esc.attach(2); //Specify the esc signal pin,Here as D8
//
//esc.writeMicroseconds(1000); //initialize the signal to 1000
//
//Serial.begin(9600);
//
//}
//
//void loop()
//
//{
//
//int val; //Creating a variable val
//
//val= analogRead(A0); //Read input from analog pin a0 and store in val
//
//val= map(val, 0, 1023,1000,2000); //mapping val to minimum and maximum(Change if needed) 
//
//esc.writeMicroseconds(val); //using val as the signal to esc
//
//}



//#include <Servo.h>
//
//Servo myservo;  // create servo object to control a servo
//// twelve servo objects can be created on most boards
//
//int pos = 0;    // variable to store the servo position
//
//void setup() {
//  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
//}
//
//void loop() {
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//}
