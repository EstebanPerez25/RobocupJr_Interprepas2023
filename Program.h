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

  private:

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



// parte de la navegacion del algoritmo 
Sensors.scan();

if (Sensors.mesures[3] < 11 && Sensors.mesures[0] > 9 && Sensors.mesures[1] > 9 && Sensors.mesures[2] > 9){ 
   Serial.println("enfrente");
Maze.forward();
}
else if (Sensors.mesures[3] > 11 && Sensors.mesures[0] < 6 && Sensors.mesures[1] < 6 && Sensors.mesures[2] < 6 || Sensors.mesures[3] < 11 && Sensors.mesures[0] < 7 && Sensors.mesures[1] < 7 && Sensors.mesures[2] < 7){
  Serial.println("derecha");
  Maze.turnRight();
}
 else if (Sensors.mesures[3] > 11 && Sensors.mesures[0] > 9 && Sensors.mesures[1] > 9 && Sensors.mesures[2] > 9){
   Serial.println("izquierda");
   Maze.turnLeft();
 }

color sensor 

 
}

// ********************* //
//         NOTAS         //
// ********************* //

/*







*/
