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

#define TRIGGER_PIN8  41          // ultrasonico derecho enfrente 
#define ECHO_PIN8     40

#define MAX_DISTANCE 200        // variable de distancia maxima 

// Limit switches
# define lm_L 48
# define lm_R 49

#define dwall 11  // distance to lateral walls 
#define df 12      // distance to frontal wall 

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
  private:

    float mesures[8];          // variable de mediciones en este caso de 8 sensores
  public:

    Ultrasonics();             // declaracion de constructor

    // METHODS
    void scan();      // Read all sensors
    byte action();    // Return the best action suggested by the ultrasonics lectures

};



// CONSTRUCTOR
Ultrasonics::Ultrasonics() {          // definicion de constructor
  //Serial.begin(9600);
  Serial.println("OK ULTRASONICS");
}


// METHODS
void Ultrasonics::scan() {                    // metodo para escaneo de las mediciones de los sensores ultrasonicos

  for (byte i = 0; i < 8; i ++) {
    /*
       0: FC
       1: FL
       2: FR
       3. LF
       4. LB
       5. B
       6. RB
       7. RF
    */
    mesures[i] = sonar[i].ping_cm();
    //Serial.println( mesures[7]);
   
    delay(7);
  }
}

byte Ultrasonics::action() {
  // Scan

  this->scan();


  // Take a decision: {0: Right, 1: Left; 2: Little left; 3: Little right; 4:Fwd}
  if (this->mesures[4] < dwall && this->mesures[0] < df ) {
    //Serial.println("Right");
    return 0;
  }
  else if (this->mesures[6] < dwall && this->mesures[0] < df) {
    //Serial.println("Left");
    return 1;
  }
//
//  else if (digitalRead(lm_L) == HIGH) {
//    //Serial.println("Little left");
//    return 2;
//  }
//  else if (digitalRead(lm_R) == HIGH) {
//    //Serial.println("Little right");
//    return 3;
//  }
  else if (this->mesures[0] > df) {
    //Serial.println("Enfrente");
    return 4;
  }

}
