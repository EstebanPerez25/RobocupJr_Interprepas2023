// ------------------------------
// LIBRARIES
// ------------------------------
#include "Program.h"

// ------------------------------
// PINOUT
// ------------------------------




// ------------------------------
// OBJECTS
// ------------------------------
Program Main;




// ------------------------------
// VOID SETUP
// ------------------------------
void setup() {

  Serial.begin(9600);
  Serial.println("OK SETUP");
  delay(500);
}


// ------------------------------
// VOID LOOP
// ------------------------------
void loop() {
  Main.algoritm();
}