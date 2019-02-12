#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "eduroam"; //Enter your wifi network SSID
const char* password = ""; //Enter your wifi network password


unsigned int localUDPport = 4210;
const int BAUD_RATE = 9600;

byte incomingByte = 0;

byte packetBuffer[512];

WiFiUDP Udp;

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

//    send back a reply, to the IP address and port we got the packet from
//    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
//    Udp.write(replyPacket);
//    Udp.endPacket();
  }
}
