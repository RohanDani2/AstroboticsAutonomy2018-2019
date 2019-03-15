#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>
#include <Filters.h>

////////////////////////////////////////////////
////////////////// PARAMETERS //////////////////
////////////////////////////////////////////////

const int num_tags = 2; 
uint16_t tags[num_tags] = {NULL, 0x670c};             // NULL for local 
boolean use_processing = false;                         // set this to true to output data for the processing sketch

const uint8_t num_anchors = 3;                                    // the number of anchors
uint16_t anchors[num_anchors] = {0x6e40, 0x676f, 0x6753};     // the network id of the anchors: change these to the network ids of your anchors.
int32_t anchors_x[num_anchors] = {0, 0, -508};               // anchor x-coorindates in mm
int32_t anchors_y[num_anchors] = {0, 1372, 689};                  // anchor y-coordinates in mm
int32_t heights[num_anchors] = {762, 762, 762};              // anchor z-coordinates in mm

uint8_t algorithm = POZYX_POS_ALG_UWB_ONLY;             // positioning algorithm to use
uint8_t dimension = POZYX_3D;                           // positioning dimension
int32_t height = 1000;                                  // height of device, required in 2.5D positioning

float filterFrequency = 0.5;                                 // filters out changes faster than this frequency in Hz
FilterOnePole lowpassFilterXLocal(LOWPASS, filterFrequency);   // create one pole (RC) lowpass filters
FilterOnePole lowpassFilterXRemote(LOWPASS, filterFrequency);  
FilterOnePole lowpassFilterYLocal(LOWPASS, filterFrequency);  
FilterOnePole lowpassFilterYRemote(LOWPASS, filterFrequency);  

////////////////////////////////////////////////

void setup(){
  Serial.begin(115200);

  if(Pozyx.begin() == POZYX_FAILURE){
    Serial.println(F("ERROR: Unable to connect to POZYX shield"));
    Serial.println(F("Reset required"));
    delay(100);
    abort();
  }

  Serial.println(F("----------POZYX POSITIONING V1.1----------"));
  Serial.println(F("NOTES:"));
  Serial.println(F("- No parameters required."));
  Serial.println();
  Serial.println(F("- System will auto start anchor configuration"));
  Serial.println();
  Serial.println(F("- System will auto start positioning"));
  Serial.println(F("----------POZYX POSITIONING V1.1----------"));
  Serial.println();
  Serial.println(F("Performing manual anchor configuration:"));


   // configures all remote tags and prints the success of their configuration.
  setAnchorsManual();
  setTagsAlgorithm();
  delay(1000);

  Serial.println(F("Starting positioning: "));
}

void loop(){
  coordinates_t position;
  int status;
  for(int i = 0; i < num_tags; i++) {
    if(tags[i] == NULL){
      status = Pozyx.doPositioning(&position, dimension, height, algorithm);
    }else{
      status = Pozyx.doRemotePositioning(tags[i], &position, dimension, height, algorithm);
    }
     
    if (status == POZYX_SUCCESS){
      // update moving average filters 
      if (tags[i] == NULL){
        lowpassFilterXLocal.input(position.x);
        lowpassFilterYLocal.input(position.y);
      }else{
        lowpassFilterXRemote.input(position.x);
        lowpassFilterYRemote.input(position.y);
      }
      // print out the result
      printCoordinates(position, tags[i]);
    }else{
      printErrorCode("positioning", tags[i]);
    }
  }
}

// prints the coordinates for either humans or for processing
void printCoordinates(coordinates_t coor, uint16_t network_id){
  float smoothX, smoothY;
  if(!use_processing){
    Serial.print("ID 0x");
    if (network_id == NULL){
      Serial.print("NULL");
      smoothX = lowpassFilterXLocal.output();
      smoothY = lowpassFilterYLocal.output();
    }else{
      Serial.print(network_id, HEX);
      smoothX = lowpassFilterXRemote.output();
      smoothY = lowpassFilterYRemote.output();
    }
    Serial.print(", x(mm): ");
    Serial.print(coor.x);
    Serial.print(", smoothX (mm): ");
    Serial.print(smoothX);
    Serial.print(", y(mm): ");
    Serial.print(coor.y);
    Serial.print(", smoothY (mm): ");
    Serial.println(smoothY);
  }else{
    Serial.print("ID 0x");
    if (network_id == NULL){
      Serial.print("NULL");
      smoothX = lowpassFilterXLocal.output();
      smoothY = lowpassFilterYLocal.output();
    }else{
      Serial.print(network_id, HEX);
      smoothX = lowpassFilterXRemote.output();
      smoothY = lowpassFilterYRemote.output();
    }
    Serial.print(",");
    Serial.print(coor.x);
    Serial.print(",");
    Serial.print(smoothX);
    Serial.print(",");
    Serial.print(coor.y);
    Serial.print(",");
    Serial.println(smoothY);
  }
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
  if(status == POZYX_SUCCESS){
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
