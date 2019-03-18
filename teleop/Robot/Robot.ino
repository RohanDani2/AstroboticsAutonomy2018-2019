#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include <Servo.h>

#define DEBUG 1

#include "robot_vars.h"

// WiFi Settings
char packetBuffer[255];
WiFiUDP Udp;
int wstatus = WL_IDLE_STATUS;

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

void dumpActuators(dump_dir dmp_dir) {
  if (dmp_dir == STOP_DUMP)
    stopActuators();
  else {
    PinStatus kx, ky;
    kx = (dmp_dir == EXTEND) ? LOW : HIGH;
    ky = (dmp_dir == EXTEND) ? HIGH : LOW;
    digitalWrite(L_RELAY_K1, kx);
    digitalWrite(L_RELAY_K2, ky);
    digitalWrite(L_RELAY_K3, kx);
    digitalWrite(L_RELAY_K4, ky);
  }
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
    #ifdef DEBUG
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
    #ifdef DEBUG
    Serial.print("UDP packet contents: ");
    Serial.println(packetBuffer);
    #endif
  }
}


void setup() {
#ifdef DEBUG
  Serial.begin(BAUD_RATE);
  delay(10);
#endif
  connectWifi();
  init_motors();
  op_mode = TELEOP;
}


/* Robot State Machine */
void loop() {
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
    } else if (strcmp((char *) packetBuffer, "UP") == 0) {
      rightDrive.writeMicroseconds(1650);
      leftDrive.writeMicroseconds(1350);
    } else if (strcmp((char *) packetBuffer, "DOWN") == 0) {
      rightDrive.writeMicroseconds(1350);
      leftDrive.writeMicroseconds(1650);
    } else if (strcmp((char *) packetBuffer, "LEFT") == 0) {
      rightDrive.writeMicroseconds(1650);
      leftDrive.writeMicroseconds(1500);
    } else if (strcmp((char *) packetBuffer, "RIGHT") == 0) {
      rightDrive.writeMicroseconds(1500);
      leftDrive.writeMicroseconds(1350);
    } else if (strcmp((char *) packetBuffer, "DUMP") == 0) {
      dumpActuators(EXTEND);
    }
  }
}
