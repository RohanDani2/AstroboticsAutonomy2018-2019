#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
//#include <Wire.h>
//#include <Adafruit_PWMServoDriver.h>
//#include <Servo.h>


//const char* ssid = "TigerIsBack"; //Enter your wifi network SSID
//const char* password = "TigerIsBlack69"; //Enter your wifi network password

const char* ssid = "eduroam"; //Enter your wifi network SSID
const char* password = "#74Landscape"; //Enter your wifi network password


unsigned int localUDPport = 4210;
const int BAUD_RATE = 9600;

byte incomingByte = 0;

// MOTOR PINS
const int LOCO_RIGHT = 0;
const int LOCO_LEFT = 1;
const int BUCKET_DIG = 2;
const int BUCKET_LIFT = 3;
const int DUMP_LIFT = 4;

byte packetBuffer[512];

WiFiUDP Udp;


void initOutputs() {
  // MOTOR PWM
  pinMode(LOCO_RIGHT, OUTPUT);
  pinMode(LOCO_LEFT, OUTPUT);
  pinMode(BUCKET_DIG, OUTPUT);
  pinMode(BUCKET_LIFT, OUTPUT);
  pinMode(DUMP_LIFT, OUTPUT);
}

void connectWifi() {
  Serial.println();
  Serial.println();
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
}


void setup() {
  Serial.begin(BAUD_RATE);
  delay(10);
  connectWifi();
  Udp.begin(localUDPport);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(packetBuffer, 255);
    if (len > 0)
    {
      packetBuffer[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", packetBuffer);

    // send back a reply, to the IP address and port we got the packet from
//    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
//    Udp.write(replyPacket);
//    Udp.endPacket();
  }
}

/*
#include <Servo.h>  //This comes with the Arduino

int talon_pin = 3;

Servo talon;
*/

/* The 'Servo.h' library allows you to control motors and servos by passing any value between
0 and 180 into the "write" method (talon.write() in this program).
For a motor:   0 is full power in one direction,
             180 is full direction in the opposite direction,
              90 is stop.
For a servo:   0 is all the way one direction,
             180 is all the way in the opposite direction,
              90 is the middle.
*/
/*
int talon_max_forward = 180;  //this might not actually be forward
int talon_max_reverse = 00;    //this might not actually be reverse
int talon_stop = 90;          //this is definitely stop (if the Talon is calibrated right)

void setup() {
  talon.attach(talon_pin);  //This tells the arduino to control this pin like it's a servo/motor
}

void loop() {
  talon.write(talon_max_forward);   //full power one way
  delay(2000);                      //wait 2 seconds
  talon.write(talon_stop);          //full power the other way
  delay(2000);                      //wait 2 seconds
  talon.write(talon_max_reverse);   //full power one way
  delay(2000);                      //wait 2 seconds
  talon.write(talon_stop);          //full power the other way
  delay(2000);                      //wait 2 seconds
}
*/
