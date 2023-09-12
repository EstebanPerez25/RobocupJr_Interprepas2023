// LIBRARIES
#include <Wire.h>
#include "Movements.h"
#include "Ultrasonics.h"
#include "ColorSens.h"

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

ColorSens colSen;                              // objeto de clase ColorSens.h



class Program {    // se crea clase Program

  public:
    Program();     // declaracion de constructor


    // NAVIGATION
    void algoritm();

};

// CONSTRUCTOR
Program::Program() {           // definicion de constructor
}



// NAVIGATION METHODS
void Program::algoritm() {

  byte action = Sensors.action();
  Maze.moves(action);
       
}

// ********************* //
//         NOTAS         //
// ********************* //

/*
*/
