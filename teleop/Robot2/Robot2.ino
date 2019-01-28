#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
//#include <Wire.h>
//#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#DEFINE DEBUG 1

// WiFi Settings
const char* ssid = "eduroam"; //Enter your wifi network SSID
const char* password = ""; //Enter your wifi network password
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

// Manual control procedures
void bot_forward(int speed);
void bot_reverse(int speed);
void bot_left(int speed);
void bot_right(int speed);
void bot_mine(); // rotates diging mechanism

// Automated procedures
void bot_deposit();
void bot_deploy_elevator(); // potentiometer limits
void bot_retract_elevator();

// Initialize motor and ESC control
void init_motors() {

}

// Wireless Setup
void connectWifi() {
#ifdef DEBUG
  Serial.print("Connecting to WIFI network");
  WiFi.hostname("ESP8266");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected with IP address");
  Serial.println(WiFi.localIP());
#else
  WiFi.hostname("ESP8266");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(500);
#endif
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
  // TODO: Receive UDP packet
  if () { // UDP == "FAIL"
    // TODO: kill actuator power (relay off)
  }
  else if (op_mode == AUTONOMOUS) {
    if () { // UDP == "Teleop"
      op_mode == TELEOP;
    } else {
      // TODO: Talk to Nuc for commands
    }
  }
  else if (op_mode == TELEOP){
    // TODO: receive movement commands from UDP
  }
}
