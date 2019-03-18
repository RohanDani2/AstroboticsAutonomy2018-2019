
#define VOLT_SENSOR 0 // A0

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;


void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Voltage Sensor Readings: ");
}

void loop() {
  value = analogRead(VOLT_SENSOR);
  vIN = (value * 5.0) / 204.8;
  Serial.println(vIN);
  delay(500);
}
