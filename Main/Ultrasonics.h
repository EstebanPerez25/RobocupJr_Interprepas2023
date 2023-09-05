// LIBRARIES
#include <NewPing.h>

// PINOUT
#define TRIGGER_PIN1  23          // ultrasonico frontal central
#define ECHO_PIN1     22

#define TRIGGER_PIN2  25          // ultrasonico frontal izquierdo 
#define ECHO_PIN2     24

#define TRIGGER_PIN3  27          // ultrasonico frontal derecho 
#define ECHO_PIN3     26

#define TRIGGER_PIN4  29          // ultrasonico izquierdo enfrente 
#define ECHO_PIN4     28

#define TRIGGER_PIN5  31          // ultrasonico izquierdo trasero  
#define ECHO_PIN5     30

#define TRIGGER_PIN6  33          // ultrasonico trasero  
#define ECHO_PIN6     32

#define TRIGGER_PIN7  35          // ultrasonico derecho trasero 
#define ECHO_PIN7     34

#define TRIGGER_PIN8  37          // ultrasonico derecho enfrente 
#define ECHO_PIN8     36

#define MAX_DISTANCE 200        // variable de distancia maxima 

#define dwall 11
#define df 7

NewPing sonar[8] = {
  NewPing (TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE),
  NewPing (TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE),
  NewPing (TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE),
  NewPing (TRIGGER_PIN4, ECHO_PIN4, MAX_DISTANCE),
  NewPing (TRIGGER_PIN5, ECHO_PIN5, MAX_DISTANCE),
  NewPing (TRIGGER_PIN6, ECHO_PIN6, MAX_DISTANCE),
  NewPing (TRIGGER_PIN7, ECHO_PIN7, MAX_DISTANCE),
  NewPing (TRIGGER_PIN8, ECHO_PIN8, MAX_DISTANCE)
};

// se crea la clase Ultrasonics

class Ultrasonics {
    //private:


  public:
    float mesures[8];          // variable de mediciones en este caso de 8 sensores

    Ultrasonics();             // declaracion de constructor

    // METHODS
    byte scan();


};
// CONSTRUCTOR
Ultrasonics::Ultrasonics() {          // definicion de constructor

}


// METHODS
byte Ultrasonics::scan() {                    // metodo para escaneo de las mediciones de los sensores ultrasonicos
  byte n = 0;
  for (byte i = 0; i < 8; i ++) {
    /*
       0: FC
       1: FL
       2: FR
       3. LF
       4. LB
       5. B
       6. RB
       7. BF
    */
    mesures[i] = sonar[i].ping_cm();
    delay(7);
  }
}
