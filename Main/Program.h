// LIBRARIES
#include <Wire.h>
#include "Movements.h"
#include "Ultrasonics.h"
#include "ColorSens.h"
#include "Oled.h"


// PINOUT
//Servomotors
#define sm_FL 2
#define sm_BL 3
#define sm_FR 4
#define sm_BR 5


// mesures of the ultrasonics .
#define dwall 11
#define df 7

// OBJECTS
Movements Maze(sm_FL, sm_BL, sm_FR, sm_BR);    // objeto de clase Movements.h
Ultrasonics Sensors;                           // objeto de clase Ultrasonics.h
ColorSens floorColor;                          // objeto de clase ColorSens.h
//Oled oled;                                     // objeto de clase Oled.h



class Program {    // se crea clase Program

  private:
    // Atributes
    byte action_us;   // Move suggested by ultrasonic sensors
    byte action_cs;   // Move suggested by color sensor
    byte action_cam;  // Move suggested by the camera
    byte action;      // The next action

  public:
    Program();     // Constructor


    // Methods
    byte navigation(byte action_us, byte action_cs, byte action_cam);  // Takes the actions ssuggested by the sensors and takes a decision
    void algoritm();

};

// CONSTRUCTOR
Program::Program() {
  Wire.begin();
  Serial.begin(9600);  
  Serial.println("OK PROGRAM");
}


byte Program::navigation(byte action_us, byte action_cs, byte action_cam) {
  // return action_cs;
  // oled.showDisp(action_cs);
  // return action_cam;
  return action_us;
}


// NAVIGATION METHODS
void Program::algoritm() {

  // 1. Read sensors (ultrasonic, color and camera)
  action_us = Sensors.action();
  action_cs = 0;//floorColor.action();
  action_cam = 0;//Cam.action();

  // 2. Decide the next movement
  action = navigation(action_us, action_cs, action_cam);

  //3. Movement
  Maze.moves(action);

}

// ********************* //
//         NOTAS         //
// ********************* //

/*
*/
