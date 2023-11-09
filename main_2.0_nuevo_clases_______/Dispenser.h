// LIBRARIES
#include <Servo.h>

class Dispenser {

private:
  uint8_t sm_Dis;

  // OBJECTS
   Servo servoDis;  // front-left

public:
Dispenser(uint8_t sm_Dis);

byte action;

// METHODS
byte Disp(byte action);

};
Dispenser::Dispenser(){
  Serial.begin(9600);
  Serial.println("OK COLORSENSOR");
}
byte Dispenser::Disp(byte action){

switch(action){
case 0:

break;
case 1:

break;
  
}

  
}
