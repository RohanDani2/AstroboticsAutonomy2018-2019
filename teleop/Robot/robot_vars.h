/* Wireless Vars */
/*
 * Configuring HooToo TripMate Titan (HT-TM05)
 *  IP: 10.0.0.1
 *  username: root
 *  password: aresbot17
 *  Arduino UNO WiFi -> static IP: 10.0.0.122
 */
#define ASTRO_SSID "Team_44"
#define ASTRO_PASS "aresbot17"
#define UDP_PORT_NUM 4210

/* Constant Variables */
#define BAUD_RATE 9600
#define LINEAR_MAX 700
#define LINEAR_MIN 290

/* Motor Pins */
#define LOCO_RIGHT   10
#define LOCO_LEFT    9
#define BUCKET_DIG   5
#define BUCKET_LIFT  6

#define L_RELAY_K1   7
#define L_RELAY_K2   8
#define L_RELAY_K3   12
#define L_RELAY_K4   13
#define LINEAR_POT1  0    // A0
#define LINEAR_POT2  1    // A1

/* Sensor Pins */
#define VOLT_SENSOR  2    // A2

/* LED Pins */
#define B_LED        2
#define G_LED        3
#define R_LED        4

/* Robot State vars */
#define AUTONOMOUS   1
#define TELEOP       43

enum dump_dir {
  EXTEND,
  RETRACT,
  STOP_DUMP
};

enum turn_dir {
  RIGHT,
  LEFT
};
enum drive_dir {
  FORWARD,
  BACKWARD,
  STOP_DRIVE
};
