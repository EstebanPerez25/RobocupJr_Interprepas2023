// ------------------------------
// LIBRARIES
// ------------------------------
#include "Program.h"
//#include "ColorSens.h"
// ------------------------------
// PINOUT
// ------------------------------




// ------------------------------
// OBJECTS
// ------------------------------
Program Main;
//ColorSens floorColor;    



// ------------------------------
// VOID SETUP
// ------------------------------
void setup() {
   
  Serial.begin(9600);
  Serial.println("OK SETUP");
//  delay(500);
}


// ------------------------------
// VOID LOOP
// ------------------------------
void loop() {
    Main.algoritm();
    //floorColor.rgbValues();
}
