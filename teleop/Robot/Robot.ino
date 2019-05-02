#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include <Servo.h>

#define DEBUG 1

#include "robot_vars.h"
#include "VescUart.h"
#include "datatypes.h"

// WiFi Settings
char packetBuffer[255];
WiFiUDP Udp;
int wstatus = WL_IDLE_STATUS;

// Robot operation state
int op_mode;
bool digEnabled = false;
bool locoEnabled = false;

/* VESC Motors */
Servo leftDrive;
Servo rightDrive;
Servo bucketDig;
Servo bucketLift;

struct bldcMeasure measuredValues;

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

void stopActuators() {
  digitalWrite(L_RELAY_K1, LOW);
  digitalWrite(L_RELAY_K2, LOW);
  digitalWrite(L_RELAY_K3, LOW);
  digitalWrite(L_RELAY_K4, LOW);
}

void initLinearActuators() {
  pinMode(L_RELAY_K1, OUTPUT);
  pinMode(L_RELAY_K2, OUTPUT);
  pinMode(L_RELAY_K3, OUTPUT);
  pinMode(L_RELAY_K4, OUTPUT);
  stopActuators();
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

void dumpActuators(dump_dir dmp_dir) {
  if (dmp_dir == STOP_DUMP)   stopActuators();
  else if (dmp_dir == EXTEND) extendActuator();
  else if(dmp_dir == RETRACT) retractActuator();
}

/* Wireless Setup */
void connectWifi() {
  if (WiFi.status() == WL_NO_MODULE) {
    #ifdef DEBUG
    Serial.println("Communication with WiFi module failed!");
    #endif
    while (true); // don't continue
  }
  String fv = WiFi.firmwareVersion();
  if (fv < "1.0.0") {
    #ifdef DEBUG
    Serial.println("Please upgrade the firmware");
    #endif
  }
  while (wstatus != WL_CONNECTED) {
    #ifdef DEBUG
    Serial.print("Connecting to SSID: ");
    Serial.println(ASTRO_SSID);
    #endif
    wstatus = WiFi.begin(ASTRO_SSID, ASTRO_PASS);

    delay(5000);
  }
  
  #ifdef DEBUG
  Serial.print("CONNECTED: "); Serial.println(WiFi.localIP());
  #endif
  Udp.begin(UDP_PORT_NUM);
}

void readWifi() {
  // Read UDP Packet
  int packetSize = Udp.parsePacket();
  if (packetSize) { // receive incoming UDP packets
    #ifdef DEBUGWIFI
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());
    #endif
    int len = Udp.read(packetBuffer, 255);
    if (len > 0)
      packetBuffer[len] = 0;
    #ifdef DEBUGWIFI
    Serial.print("UDP packet contents: ");
    Serial.println(packetBuffer);
    #endif
  }
}

void blinkSuccessWifi() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    delay(300);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial1.begin(115200);
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  digitalWrite(R_LED, LOW);
  digitalWrite(G_LED, HIGH);
  digitalWrite(B_LED, LOW);
#ifdef DEBUG
  Serial.begin(BAUD_RATE);
  delay(10);
#endif
  connectWifi();
  blinkSuccessWifi();
  init_motors();
  op_mode = TELEOP;
}


/* Robot State Machine */
void loop() {
  packetBuffer[0] = '$';
  readWifi();
  /* FAILURE: kill actuator power (relay off) */
  if (strcmp((char *) packetBuffer, "FAILURE") == 0) {
    #ifdef DEBUG
    Serial.println("FAILURE");
    #endif
  }
  /* AUTONOMOUS Mode */
  else if (op_mode == AUTONOMOUS) {
    if (strcmp((char *) packetBuffer, "TELEOP") == 0) {
      op_mode = TELEOP;
      #ifdef DEBUG
      Serial.println("TELEOP Mode");
      #endif
    } else {
      // TODO: Talk to Nuc for commands
    }
  }
  /* TELEOP Mode */
  else if (op_mode == TELEOP) {
    if (strcmp((char *) packetBuffer, "AUTONOMOUS") == 0) {
      op_mode = AUTONOMOUS;
      #ifdef DEBUG
      Serial.println("AUTONOMOUS Mode");
      #endif
    } /* ENABLE BUTTONS */
    else if (strcmp((char *) packetBuffer, "DIG_EN") == 0) {
      digEnabled = true;
    } else if (strcmp((char *) packetBuffer, "DIG_DIS") == 0) {
      digEnabled = false;
      bucketDig.writeMicroseconds(1500);
      bucketLift.writeMicroseconds(1500);
    } else if (strcmp((char *) packetBuffer, "LOCO_EN") == 0) {
      locoEnabled = true;
    } else if (strcmp((char *) packetBuffer, "LOCO_DIS") == 0) {
      locoEnabled = false;
      rightDrive.writeMicroseconds(1500);
      leftDrive.writeMicroseconds(1500);
    } /* LOCOMOTION CONTROL */
    else if (locoEnabled) { // "l1230" OR "r1450"
      if (strcmp((char *) packetBuffer, "ZERO_LEFT") == 0) {
        leftDrive.writeMicroseconds(1500);
      } else if (strcmp((char *) packetBuffer, "ZERO_RIGHT") == 0) {
        rightDrive.writeMicroseconds(1500);
      } else if (packetBuffer[0] == 'l') {
        int i;
        for (i = 0; i < 4; i++) {
          packetBuffer[i] = packetBuffer[i+1];
        } packetBuffer[4] = '\0';
        // extract speed from buffer and write it to leftDrive
        Serial.println(atoi(packetBuffer));
        leftDrive.writeMicroseconds(atoi(packetBuffer));
      } else if (packetBuffer[0] == 'r') {
        int i;
        for (i = 0; i < 4; i++) {
          packetBuffer[i] = packetBuffer[i+1];
        } packetBuffer[4] = '\0';
        // extract speed from buffer and write it to rightDrive
        Serial.println(atoi(packetBuffer));
        rightDrive.writeMicroseconds(atoi(packetBuffer));
      }
    } /* MINING CONTROL */
    else if (digEnabled) {
      if (packetBuffer[0] == 'l') {
        int i;
        for (i = 0; i < 4; i++) {
          packetBuffer[i] = packetBuffer[i+1];
        } packetBuffer[4] = '\0';
        // extract speed from buffer and write it to bucketDig
        Serial.println(atoi(packetBuffer));
        bucketDig.writeMicroseconds(atoi(packetBuffer));
      } else if (packetBuffer[0] == 'r') {
        int i;
        for (i = 0; i < 4; i++) {
          packetBuffer[i] = packetBuffer[i+1];
        } packetBuffer[4] = '\0';
        // extract speed from buffer and write it to bucketLift
        Serial.println(atoi(packetBuffer));
        bucketLift.writeMicroseconds(atoi(packetBuffer));
      }
    } /* DUMP BODY CONTROL */
    else if (strcmp((char *) packetBuffer, "EXTEND") == 0) {
      extendActuator();
    } else if (strcmp((char *) packetBuffer, "RETRACT") == 0) {
      retractActuator();
    } else if (strcmp((char *) packetBuffer, "STOP_DUMP") == 0) {
      stopActuators();
    } /* FAIL STOP ALL */
    else if (strcmp((char *) packetBuffer, "STOP") == 0) {
      stopActuators();
      rightDrive.writeMicroseconds(1500);
      leftDrive.writeMicroseconds(1500);
      bucketDig.writeMicroseconds(1500);
      bucketLift.writeMicroseconds(1500);
    } 
  }
  // TODO: Send Sensor Data: Voltage & Actuator positions
//  if (VescUartGetValue(measuredValues,1)) {
//    SerialPrint(measuredValues);
//  } 
//  else { Serial.println("Failed to read VESC!"); }
//  delay(1000);
}
