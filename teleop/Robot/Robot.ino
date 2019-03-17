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

const int BAUD_RATE = 9600;

// Robot operation state
int op_mode;

Servo testservo;

// Initialize motor and ESC control
void init_motors() {
  testservo.attach(2);
}

// Wireless Setup
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


// Robot State Machine
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
    } else if (strcmp((char *) packetBuffer, "UP") == 0)
      testservo.write(0);
    else if (strcmp((char *) packetBuffer, "DOWN") == 0)
      testservo.write(180);
    else if (strcmp((char *) packetBuffer, "LEFT") == 0)
      testservo.write(0);
    else if (strcmp((char *) packetBuffer, "RIGHT") == 0)
      testservo.write(180);
  }
}
