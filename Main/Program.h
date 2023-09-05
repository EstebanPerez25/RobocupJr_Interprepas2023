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


 if (Sensors.mesures[4] < 11 && Sensors.mesures[0] < 9 ){
  Serial.println("derecha");
  Maze.turnRight();
}
 else if (Sensors.mesures[6] < 11 && Sensors.mesures[0] < 9){
   Serial.println("izquierda");
   Maze.turnLeft();
 }
// else if (Sensors.mesures[2] <= 2){
//   Serial.println("pequeña izquierda ");
//   Maze.lilLeft();
// }
// else if (Sensors.mesures[1] < 4){
//   Serial.println("pequeña derecha");
//   Maze.lilLeft();
// }
else if (Sensors.mesures[4] < 11 || Sensors.mesures[4] > 11 && Sensors.mesures[0] > 9){ 
   Serial.println("enfrente");
Maze.forward();
}


}

// ********************* //
//         NOTAS         //
// ********************* //

/*
*/
