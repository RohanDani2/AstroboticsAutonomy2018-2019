/* VT Astrobotics 2019
   AUTONOMOUS RC CAR
     Testing Autonomy on RC car through Serial communication
     Drive motor: BLDC RC car ESC
     Steering: Servo for left and right
*/


#include <Servo.h>

/* Motor Pins */
#define DRIVING_RIGHT    3
#define DRIVING_LEFT     5

#define BAUD_RATE   115200

enum dir {
  CW,
  CC,
  FOR,
  BACK,
  STOP
};

/* Constant speeds for testing purposes */
const int stopSpeed = 1500;
const int forwardSpeed = 1400;
const int backwardSpeed = 1600;
const int turnSpeed = 100;

Servo driveMotor_Left;
Servo driveMotor_Right;

byte serialCMD;

void init_motors() {
  driveMotor_Left.attach(DRIVING_LEFT);
  driveMotor_Right.attach(DRIVING_RIGHT);
}

/* Drive ESC with PPM */
void drive(dir command) {
  if (command == STOP) {
    driveMotor_Left.writeMicroseconds(stopSpeed);
    driveMotor_Right.writeMicroseconds(stopSpeed);
  }else if (command == FOR) {
    driveMotor_Left.writeMicroseconds(forwardSpeed);
    driveMotor_Right.writeMicroseconds(forwardSpeed);
  }else if (command == BACK) {
    driveMotor_Left.writeMicroseconds(backwardSpeed);
    driveMotor_Right.writeMicroseconds(backwardSpeed);
  }else if (command == CC) {
    driveMotor_Left.writeMicroseconds(stopSpeed-turnSpeed);
    driveMotor_Right.writeMicroseconds(stopSpeed+turnSpeed);
  }
  else if (command == CW) {
    driveMotor_Left.writeMicroseconds(stopSpeed+turnSpeed);
    driveMotor_Right.writeMicroseconds(stopSpeed-turnSpeed);
  }
}

void setup() {
  Serial.begin(BAUD_RATE);
  //Serial.println("*");
  delay(10);
  init_motors();
}

void loop() {
    if (Serial.available() > 0) {
      serialCMD = Serial.read(); 
      Serial.println(serialCMD);
    } 
//  Serial.println(0);
//  Serial.println(1);

//  if (serialCMD == 0) drive(STOP);
//  else if (serialCMD == 1) drive(FOR);
//  else if (serialCMD == 2) drive(BACK);
//  else if (serialCMD == 3) drive(CC);
//  else if (serialCMD == 4) drive(CW);

//  drive(FOR);
//  delay(2000);
//  drive(STOP);
//  delay(2000);
//  drive(BACK);
//  delay(2000);
//  drive(STOP);
//  delay(4000);
//  drive(CC);
//  delay(2000);
//  drive(STOP);
//  delay(2000);
//  drive(CW);
//  delay(2000);
//  drive(STOP);
//  delay(4000);

}
