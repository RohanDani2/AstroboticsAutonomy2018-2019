#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

//#define DEBUG 1

// ssid: Team_44
// pwrd: aresbot17

// WiFi Settings
const char* ssid = "Team_44";
const char* password = "aresbot17";
unsigned int localUDPport = 4210;
byte packetBuffer[512];
WiFiUDP Udp;
byte incomingByte = 0;

const int BAUD_RATE = 9600;

// Robot operation state
const int AUTONOMOUS = 1;
const int TELEOP = 43;
int op_mode;

// MOTOR PINS
const int LOCO_RIGHT = 0;
const int LOCO_LEFT = 1;
const int BUCKET_DIG = 2;
const int BUCKET_LIFT = 3;
const int DUMP_LIFT = 4; // TODO: Same signal for both linear acutators???

Servo testservo;

// Initialize motor and ESC control
void init_motors() {
  testservo.attach(2);
}

// Wireless Setup
void connectWifi() {
  WiFi.hostname("ESP8266");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef DEBUG
    Serial.print(".");
  }
  Serial.println("WiFi connected with IP address");
  Serial.println(WiFi.localIP());
#else
  }
#endif
}

void readWifi() {
  // Read UDP Packet
  int packetSize = Udp.parsePacket();
  if (packetSize) { // receive incoming UDP packets
    #ifdef DEBUG
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    #endif
    int len = Udp.read(packetBuffer, 255);
    if (len > 0)
      packetBuffer[len] = 0;
    #ifdef DEBUG
    Serial.printf("UDP packet contents: %s\n", packetBuffer);
    #endif
  }
}


void setup() {
#ifdef DEBUG
  Serial.begin(BAUD_RATE);
  delay(10);
#endif
  connectWifi();
  Udp.begin(localUDPport);
  init_motors();
  op_mode = TELEOP;
}


// Robot State Machine
void loop() {
  /* FAILURE: kill actuator power (relay off) */
  if (strcmp((char *) packetBuffer, "FAILURE") == 0) {
    Serial.println("FAILURE");
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
