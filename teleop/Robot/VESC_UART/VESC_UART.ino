/*
 Name:		VescUartSample.ino
 Created:	9/26/2015 10:12:38 PM
 Author:	AC
*/

// the setup function runs once when you press reset or power the board
// To use VescUartControl stand alone you need to define a config.h file, that should contain the Serial or you have to comment the line
// #include Config.h out in VescUart.h

//Include libraries copied from VESC
 #include "VescUart.h"
 #include "datatypes.h"
 #include <Servo.h>

#define DEBUG
unsigned long count;
int speed;
  int pin;
  Servo myServo;
  char input;

  

void setup() {
	
	//Setup UART port
	Serial1.begin(115200);
#ifdef DEBUG
	//SEtup debug port
	Serial.begin(115200);
	#endif

  pin = 8;
  myServo.attach(pin);
  Serial.setTimeout(10000);
  Serial.println("s --> Set motor speed");
}

struct bldcMeasure measuredValues;
	
// the loop function runs over and over again until power down or reset
void loop() {
	//int len=0;
	//len = ReceiveUartMessage(message);
	//if (len > 0)
	//{
	//	len = PackSendPayload(message, len);
	//	len = 0;
	//}
 while(Serial.available() > 0){
        input = Serial.read();
        if(input == 's'){
          Serial.println("Set speed:"); //1000 is fully counter-clockwise, 2000 is fully clockwise, and 1500 is in the middle.
          speed = Serial.parseInt();
          speed = map(speed, -100,100,1000,2000);
        }
      myServo.writeMicroseconds(speed);
      Serial.println();
      Serial.println();
      Serial.println();
      Serial.print("Current speed: ");
      Serial.println(speed);
      Serial.println("s --> Set motor speed");
  }
	if (VescUartGetValue(measuredValues,1)) {
		Serial.print("-----------Loop: "); 
		Serial.print(count++);
    Serial.println(" -----------");
		SerialPrint(measuredValues);
	}
	else
	{
		Serial.println("Failed to get data!");
	}
	delay(1000);
}
