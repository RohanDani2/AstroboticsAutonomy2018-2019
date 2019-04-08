
#include <Servo.h>

/* Linear Actuator Pins */
#define L_RELAY_K1   7
#define L_RELAY_K2   8
#define L_RELAY_K3   12
#define L_RELAY_K4   13
#define EXTEND_BTN   5
#define RETRACT_BTN  4
#define LIN_EXT_LED  2
#define LIN_RET_LED  3

/* Motor Pins */
#define MOTOR1       3
#define MOTOR2       5
#define MOTOR3       6

/* Potentiometer Pins */ 
#define POT1         0
#define POT2         1
#define POT3         2

int motor1, motor2, motor3, extendBTN, retractBTN;

Servo m1, m2, m3;

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

void retractActuators() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, HIGH);
  digitalWrite(L_RELAY_K3, HIGH);
  digitalWrite(L_RELAY_K4, LOW);
}

void extendActuators() {
  digitalWrite(L_RELAY_K1, HIGH);
  digitalWrite(L_RELAY_K2, LOW);
  digitalWrite(L_RELAY_K3, LOW);
  digitalWrite(L_RELAY_K4, HIGH);
} 

void setup() {
  Serial.begin(9600);
  m1.attach(MOTOR1);
  m2.attach(MOTOR2);
  m3.attach(MOTOR3);
  pinMode(EXTEND_BTN, INPUT);
  pinMode(RETRACT_BTN, INPUT);
  pinMode(LIN_EXT_LED, OUTPUT);
  pinMode(LIN_RET_LED, OUTPUT);
  initLinearActuators();
}

void loop() {
  /* Map to PPM Value */
  motor1 = map(analogRead(POT1), 0, 1023, 1500, 2000);
  motor2 = map(analogRead(POT2), 0, 1023, 1500, 2000);
  motor3 = map(analogRead(POT3), 0, 1023, 1500, 2000);

  m1.writeMicroseconds(motor1);
  m2.writeMicroseconds(motor2);
  m3.writeMicroseconds(motor3);

  extendBTN = digitalRead(EXTEND_BTN);
  retractBTN = digitalRead(RETRACT_BTN);
  digitalWrite(LIN_EXT_LED, extendBTN);
  digitalWrite(LIN_RET_LED, retractBTN);

  if (extendBTN)
    extendActuators();
  else if (retractBTN)
    retractActuators();
  else
    stopActuators();

  Serial.print("Motor1: ");
  Serial.print(motor1);
  Serial.print("\tMotor2: ");
  Serial.print(motor2);
  Serial.print("\tMotor3: ");
  Serial.print("\tRetracting: ");
  Serial.print(retractBTN);
  Serial.print("\tExtending: ");
  Serial.println(extendBTN);
}
