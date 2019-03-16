#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>
#include <Filters.h>

////////////////////////////////////////////////
////////////////// PARAMETERS //////////////////
////////////////////////////////////////////////

const int num_tags = 2;                                     // max 2 with 1 local and 1 remote  
uint16_t tags[num_tags] = {NULL, 0x670c};                   // NULL for local, ID for remote
boolean use_processing = false;                             // set this to true to output data for the processing sketch

const uint8_t num_anchors = 3;                              // the number of anchors
uint16_t anchors[num_anchors] = {0x6e40, 0x676f, 0x6753};   // the network id of the anchors: change these to the network ids of your anchors.
int32_t anchors_x[num_anchors] = {0, 0, -508};              // anchor x-coorindates in mm
int32_t anchors_y[num_anchors] = {0, 1372, 689};            // anchor y-coordinates in mm
int32_t heights[num_anchors] = {737, 737, 737};             // anchor z-coordinates in mm

uint8_t algorithm = POZYX_POS_ALG_UWB_ONLY;                 // positioning algorithm to use
uint8_t dimension = POZYX_2_5D;                             // positioning dimension
int32_t height = 1067;                                      // height of device, required in 2.5D positioning
int32_t midpoint = 185;                                     // fixed measurement to midpoint of 2 tags in mm 

float filterFrequency = 0.5;                                // filter position changes faster than this frequency in Hz  

////////////////////////////////////////////////

// create one pole (RC) lp (lowpass) filters
FilterOnePole lpFilterXLocal(LOWPASS, filterFrequency);  
FilterOnePole lpFilterXRemote(LOWPASS, filterFrequency);  
FilterOnePole lpFilterYLocal(LOWPASS, filterFrequency);  
FilterOnePole lpFilterYRemote(LOWPASS, filterFrequency);

void setup(){
  Serial.begin(115200);

  if(Pozyx.begin() == POZYX_FAILURE){
    Serial.println(F("ERROR: Unable to connect to POZYX shield"));
    Serial.println(F("Reset required"));
    delay(100);
    abort();
  }

  // configures all remote tags and prints the success of their configuration.
  setAnchorsManual();
  setTagsAlgorithm();
  delay(1000);

  Serial.println(F("Starting positioning: "));
}

void loop(){
  coordinates_t position;
  int status;
  float xdif, ydif;

  float theta; 
  float pos[2];  
  
  for(int i = 0; i < num_tags; i++){
    if (tags[i] == NULL){
      status = Pozyx.doPositioning(&position, dimension, height, algorithm);
    }else{
      status = Pozyx.doRemotePositioning(tags[i], &position, dimension, height, algorithm);
    }
    if (status == POZYX_SUCCESS){
      // update moving average filters 
      if (tags[i] == NULL){
        lpFilterXLocal.input(position.x);
        lpFilterYLocal.input(position.y); 
      }else{
        lpFilterXRemote.input(position.x);
        lpFilterYRemote.input(position.y);
      }
      if (sizeof(tags)/sizeof(tags[0]) == 2){
        // calculate orientation of line from local to remote
        xdif = lpFilterXRemote.output() - lpFilterXLocal.output();
        ydif = lpFilterYRemote.output() - lpFilterYLocal.output();
        theta = atan2(ydif, xdif);

        // calculate coordinate of midpoint between 2 tags 
        pos[0] = lpFilterXLocal.output() + midpoint*cos(theta);
        pos[1] = lpFilterYLocal.output() + midpoint*sin(theta);

        // print position of midpoint and orientation for bound dual tags 
        printDualTag(pos, theta);
      }else{
        // print raw and filtered coordinate of single tag 
        printSingleTag(position, tags[i]);
      }
    }else if (!use_processing){
      printErrorCode("positioning", tags[i]);
    }
  }
}

// print results for dual tag use 
void printDualTag(float pos[], float theta){
  if (!use_processing){
    Serial.print("X (mm): ");
    Serial.print(pos[0]);
    Serial.print(", Y (mm): ");
    Serial.print(pos[1]);
    Serial.print(", theta (deg): ");
    Serial.println(theta * 180.0/M_PI);
  }else{
    Serial.print(pos[0]);
    Serial.print(",");
    Serial.print(pos[1]);
    Serial.print(",");
    Serial.println(theta);
  }
}

// print results for single tag use 
void printSingleTag(coordinates_t coor, uint16_t network_id){
  float filteredX, filteredY;
  Serial.print("ID 0x");
  if (network_id == NULL){
    Serial.print("NULL");
    filteredX = lpFilterXLocal.output();
    filteredY = lpFilterYLocal.output();
  }else{
    Serial.print(network_id, HEX);
    filteredX = lpFilterXRemote.output();
    filteredY = lpFilterYRemote.output();
  }
  Serial.print(", rawX (mm): ");
  Serial.print(coor.x);
  Serial.print(", filteredX (mm): ");
  Serial.print(filteredX);
  Serial.print(", rawY (mm): ");
  Serial.print(coor.y);
  Serial.print(", filteredY (mm): ");
  Serial.println(filteredY);
}

// error printing function for debugging
void printErrorCode(String operation, uint16_t network_id){
  uint8_t error_code;
  if (network_id == NULL){
    Pozyx.getErrorCode(&error_code);
    Serial.print("ERROR ");
    Serial.print(operation);
    Serial.print(", local error code: 0x");
    Serial.println(error_code, HEX);
    return;
  }
  int status = Pozyx.getErrorCode(&error_code, network_id);
  if (status == POZYX_SUCCESS){
    Serial.print("ERROR ");
    Serial.print(operation);
    Serial.print(" on ID 0x");
    Serial.print(network_id, HEX);
    Serial.print(", error code: 0x");
    Serial.println(error_code, HEX);
  }else{
    Pozyx.getErrorCode(&error_code);
    Serial.print("ERROR ");
    Serial.print(operation);
    Serial.print(", couldn't retrieve remote error code, local error: 0x");
    Serial.println(error_code, HEX);
  }
}

void setTagsAlgorithm(){
  for (int i = 0; i < num_tags; i++){
    Pozyx.setPositionAlgorithm(algorithm, dimension, tags[i]);
  }
}

// function to manually set the anchor coordinates
void setAnchorsManual(){
  for (int i = 0; i < num_tags; i++){
    int status = Pozyx.clearDevices(tags[i]);
    for(int j = 0; j < num_anchors; j++){
      device_coordinates_t anchor;
      anchor.network_id = anchors[j];
      anchor.flag = 0x1;
      anchor.pos.x = anchors_x[j];
      anchor.pos.y = anchors_y[j];
      anchor.pos.z = heights[j];
      status &= Pozyx.addDevice(anchor, tags[i]);
    }
    if (num_anchors > 4){
      Pozyx.setSelectionOfAnchors(POZYX_ANCHOR_SEL_AUTO, num_anchors, tags[i]);
    }
    if (status == POZYX_SUCCESS){
      Serial.print("Configuring ID 0x");
      if (tags[i] == NULL){
        Serial.print("NULL");
      }else{
        Serial.print(tags[i], HEX);
      }
      Serial.println(" success!");
    }else{
      printErrorCode("configuration", tags[i]);
    }
  }
}
