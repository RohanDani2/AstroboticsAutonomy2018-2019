
#include <Servo.h>

#define L_RELAY_K1   7
#define L_RELAY_K2   8
#define L_RELAY_K3   12
#define L_RELAY_K4   13

int motor1, motor2, motor3, motor4, motor5, motor6, extendBTN, retractBTN;

Servo m1, m2, m3, m4, m5, m6;

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
  m1.attach(1);
  m2.attach(2);
  m3.attach(3);
  m4.attach(4);
  m5.attach(5);
  m6.attach(6);
  pinMode(7, INPUT); // Extend Button
  pinMode(8, INPUT); // Retract Button
  initLinearActuators();
}

void loop() {
  motor1 = map(analogRead(0), 0, 1023, 1500, 2000);
  motor2 = map(analogRead(1), 0, 1023, 1500, 2000);
  motor3 = map(analogRead(2), 0, 1023, 1500, 2000);
  motor4 = map(analogRead(3), 0, 1023, 1500, 2000);
  motor5 = map(analogRead(4), 0, 1023, 1500, 2000);
  motor6 = map(analogRead(5), 0, 1023, 1500, 2000);

  m1.writeMicroseconds(motor1);
  m2.writeMicroseconds(motor2);
  m3.writeMicroseconds(motor3);
  m4.writeMicroseconds(motor4);
  m5.writeMicroseconds(motor5);
  m6.writeMicroseconds(motor6);

  extendBTN = digitalRead(7);
  retractBTN = digitalRead(8);

  if (extendBTN == HIGH)  extendActuators();
  else stopActuators();

  if (retractBTN == HIGH)  retractActuators();
  else stopActuators();
  
  Serial.print("Motor1: ");
  Serial.print(motor1);
  Serial.print("\tMotor2: ");
  Serial.print(motor2);
  Serial.print("\tMotor3: ");
  Serial.print(motor3);
  Serial.print("\tMotor4: ");
  Serial.print(motor4);
  Serial.print("\tMotor5: ");
  Serial.print(motor5);
  Serial.print("\tMotor6: ");
  Serial.println(motor6);
}
