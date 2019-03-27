#include <Servo.h>

#define DEBUG 1

#include "robot_vars.h"

// Robot operation state
int op_mode;

/* VESC Motors */
Servo leftDrive;
Servo rightDrive;
Servo bucketDig;
Servo bucketLift;

float readBattVolt() {
  int rawVoltageReading = analogRead(VOLT_SENSOR);
  float vIN = (rawVoltageReading * 5.0) / 204.8;
  #ifdef DEBUG
  Serial.print("Voltage Reading: ");
  Serial.println(vIN);
  #endif
  return vIN;
}

// Initialize motor and ESC control
void init_motors() {
  leftDrive.attach(LOCO_LEFT);
  rightDrive.attach(LOCO_RIGHT);
  bucketDig.attach(BUCKET_DIG);
  bucketLift.attach(BUCKET_LIFT);
}

void initLinearActuators() {
  pinMode(L_RELAY_K1, OUTPUT);
  pinMode(L_RELAY_K2, OUTPUT);
  pinMode(L_RELAY_K3, OUTPUT);
  pinMode(L_RELAY_K4, OUTPUT);
}

void stopActuators() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, LOW);
  digitalWrite(L_RELAY_K3, LOW);
  digitalWrite(L_RELAY_K4, LOW);
}

void retractActuator() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, HIGH);
  digitalWrite(L_RELAY_K3, HIGH);
  digitalWrite(L_RELAY_K4, LOW);
}

void extendActuator() {
  digitalWrite(L_RELAY_K1, HIGH);
  digitalWrite(L_RELAY_K2, LOW);
  digitalWrite(L_RELAY_K3, LOW);
  digitalWrite(L_RELAY_K4, HIGH);
}

void setup() {
#ifdef DEBUG
  Serial.begin(BAUD_RATE);
  delay(10);
#endif
  init_motors();
  op_mode = TELEOP;
}

byte serialCMD;

/* Robot State Machine */
void loop() {
  if (Serial.available() > 0) {
    serialCMD = Serial.read();
    Serial.print("Serial Command: ");
    Serial.println(serialCMD);
  }
  if (serialCMD == 'p') {
    stopActuators();
    rightDrive.writeMicroseconds(1500);
    leftDrive.writeMicroseconds(1500);
    bucketDig.writeMicroseconds(1500);
    bucketLift.writeMicroseconds(1500);
  } else if (serialCMD = 'w') { // Forward
    rightDrive.writeMicroseconds(1650);
    leftDrive.writeMicroseconds(1350);
  } else if (serialCMD == "s") { // Reverse
    rightDrive.writeMicroseconds(1350);
    leftDrive.writeMicroseconds(1650);
  } else if (serialCMD == "a") { // Left
    rightDrive.writeMicroseconds(1650);
    leftDrive.writeMicroseconds(1500);
  } else if (serialCMD == "d") { // Right
    rightDrive.writeMicroseconds(1500);
    leftDrive.writeMicroseconds(1350);
  } else if (serialCMD == "0") {
    extendActuator();
  } else if (serialCMD == "9") {
    retractActuator();
  } else if (serialCMD == "[") {
    bucketDig.writeMicroseconds(1800);
  } else if (serialCMD == "]") {
    bucketDig.writeMicroseconds(1200);
  }
  // TODO: Send Sensor Data: Voltage & Actuator positions
}
