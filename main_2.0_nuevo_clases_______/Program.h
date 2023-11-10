// LIBRARIES
#include "Movements.h"
#include "Ultrasonics.h"
#include "ColorSens.h"
#include "Oled.h"
#include "Dispenser.h"
#include "CameraESP.h"


// PINOUT
//Servomotors
#define sm_FL 2
#define sm_BL 3
#define sm_FR 5
#define sm_BR 6
#define sm_Dis 9
#define p1 10
#define p2 11


// mesures of the ultrasonics .
#define dwall 11
#define df 7

// OBJECTS
Movements Maze(sm_FL, sm_BL, sm_FR, sm_BR);    // objeto de clase Movements.h
Ultrasonics Sensors;                           // objeto de clase Ultrasonics.h
ColorSens floorColor;                          // objeto de clase ColorSens.h
Oled oled;                                    // objeto de clase Oled.h
Dispenser disp(sm_Dis);                       // objeto de clase Dispenser.h
CameraESP Cam(p1, p2);                       // objeto de clase Dispenser.h



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
  Serial.begin(9600);
  Serial.println("OK PROGRAM");
}


byte Program::navigation(byte action_us, byte action_cs, byte action_cam) {

  switch (action_cs) {
    case 5:
      // Black floor
      oled.showDisp(5);
      return 5;
      break;

    case 6:
      // Blue
      oled.showDisp(6);
      return 6;
      break;

    case 7:
      // Plate
      return 6;
      break;

    case 8:
      // White
      if (action_cam != 4) {
        Maze.moves(7);  // se para el robot
        disp.drop(action_cam);
      }
      return action_us;
  }
}


// NAVIGATION METHODS
void Program::algoritm() {

  // 1. Read sensors (ultrasonic, color and camera)
  action_us = Sensors.action();
  action_cs = floorColor.action();

  action_cam = Cam.action();

  // 2. Decide the next movement
  action = navigation(action_us, action_cs, action_cam);
  Serial.println(action);

  //3. Movement
  Maze.moves(action);

}

// ********************* //
//         NOTAS         //
// ********************* //

/*
*/
