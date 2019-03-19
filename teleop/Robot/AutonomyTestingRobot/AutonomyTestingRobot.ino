/* VT Astrobotics 2019
 *  
 * AUTONOMOUS RC CAR
 *   Testing Autonomy on RC car through Serial communication
 *   Drive motor: BLDC RC car ESC
 *   Steering: Servo for left and right
 */


#include <Servo.h>
#include "robot_vars.h"

enum turn_dir {
  RIGHT,
  LEFT
};
enum drive_dir {
  FORWARD,
  BACKWARD,
  STOP
};

/* Constant speeds for testing purposes */
const int forwardSpeed = 1650;
const int reverseSpeed = 1250;

Servo driveMotor;
Servo steeringServo;

void init_motors() {
  driveMotor.attach(DRIVING);
  steeringServo.attach(STEERING);
}

/* Turn Steering Servo */
void turn(turn_dir tr_dir) {
  int towrite = (tr_dir == RIGHT) ? 180 : 0;
  steeringServo.write(towrite);
}

/* Drive ESC with PPM */
void drive(drive_dir dr_dir) {
  int towrite;
  if (dr_dir == STOP) towrite = 1500;
  else towrite = (dr_dir == FORWARD) ? forwardSpeed : reverseSpeed;
  driveMotor.writeMicroseconds(towrite);
}

void testdrive() {
  driveMotor.writeMicroseconds(1100);
}

void setup() {
  Serial.begin(BAUD_RATE);
  delay(10);
  init_motors();
}

byte serialCMD;

void loop() {
  // Read Serial command
//  if (Serial.available() > 0) {
//    serialCMD = Serial.read();
//    Serial.print("Serial Command: ");
//    Serial.println(serialCMD);
//  }
//  if (serialCMD == '1') turn(RIGHT);
//  else if (serialCMD == '2') turn(LEFT);
//  else if (serialCMD == '3') drive(FORWARD);
//  else if (serialCMD == '4') drive(BACKWARD);
//  else if (serialCMD == '5') drive(STOP);
//  delay(100);


  testdrive();


}
