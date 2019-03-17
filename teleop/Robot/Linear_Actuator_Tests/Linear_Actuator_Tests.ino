
#include "robot_vars.h"

int curpos;
int lin_max = 700;
int lin_min = 290;


void initLinearActuators() {
  pinMode(L_RELAY_K1, OUTPUT);
  pinMode(L_RELAY_K2, OUTPUT);
}

void extendActuator() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, HIGH);
}

void retractAcutator() {
  digitalWrite(L_RELAY_K1, HIGH);
  digitalWrite(L_RELAY_K2, LOW);
}

void stopActuator() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, LOW);
}

void setup() {
  Serial.begin(9600);
  initLinearActuators();
}

void loop() {
  curpos = analogRead(0);
  extendActuator();
  while(curpos < lin_max) {
    curpos = analogRead(0);
    Serial.println(curpos);
  }
  stopActuator(); delay(1500);

  curpos = analogRead(0);
  retractAcutator();
  while (curpos > lin_min) {
    curpos = analogRead(0);
    Serial.println(curpos);
  }
  stopActuator(); delay(1500);
}
