// LIBRARIES
#include <Servo.h>

// Parameters
// #define d 300           // Delay after detach
#define step_size 200   // Time of forward movement
#define tl_size 940     // Turn left size
#define tr_size 950     // Turn right size
#define ll_size (940/4)     // Little turn left size
#define lr_size (950/4)     // Little turn left size



// OBJECTS
class Movements {      // se crea la clase Movements.h

  private:
    uint8_t sm_FL;
    uint8_t sm_BL;
    uint8_t sm_FR;
    uint8_t sm_BR;


    // OBJECTS
    Servo servoFL;  // front-left
    Servo servoBL;  // back-left
    Servo servoFR;  // front-right
    Servo servoBR;  // back-right

  public:
    Movements(uint8_t _sm_FL, uint8_t _sm_BL, uint8_t _sm_FR, uint8_t _sm_BR);    // se declara el constructor

    byte action;


    // METHODS                         // declaracion de metodos de movimiento
    void forward();
    void back();
    void turnLeft();
    void lilLeft();
    void turnRight();
    void lilRight();
    void stp();
    void limitS();
    void moves(byte action);

};

Movements::Movements(uint8_t _sm_FL, uint8_t _sm_BL, uint8_t _sm_FR, uint8_t _sm_BR) {    // se define el constructor
  sm_FL = _sm_FL;
  sm_BL = _sm_BL;
  sm_FR = _sm_FR;
  sm_BR = _sm_BR;

  Serial.begin(9600);
  Serial.println("Servos OK");


}

void Movements::forward() {       // metodo de movimiento hacia delante
  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);


  servoFL.write(140);  // 180
  servoBL.write(180);  // 180
  servoFR.write(30);   // 0
  servoBR.write(30);

  //  delay(step_size);
  //  servoFL.detach();
  //  servoBL.detach();
  //  servoFR.detach();
  //  servoBR.detach();
  //  delay(d);
}

void Movements::back() {               // metodo de movimiento hacia atras
  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);


  servoFL.write(0);
  servoBL.write(0);
  servoFR.write(180);
  servoBR.write(180);
  //  delay(step_size);
  //
  //  servoFL.detach();
  //  servoBL.detach();
  //  servoFR.detach();
  //  servoBR.detach();
  //  delay(d);
}

void Movements::turnLeft() {                // metodo de giro a la izquierda

  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);


  servoFL.write(0);
  servoBL.write(0);
  servoFR.write(0);
  servoBR.write(0);


  delay(tl_size);
  servoFL.detach();
  servoBL.detach();
  servoFR.detach();
  servoBR.detach();
  delay(300);
}

void Movements::turnRight() {                // metodo de giro hacia la derecha
  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);


  servoFL.write(180);
  servoBL.write(180);
  servoFR.write(180);
  servoBR.write(180);
  delay(tr_size);

  servoFL.detach();
  servoBL.detach();
  servoFR.detach();
  servoBR.detach();
  delay(300);
}

void Movements::stp() {                  // metodo para detenerse
  servoFL.detach();
  servoBL.detach();
  servoFR.detach();
  servoBR.detach();
  delay(300);
}

void Movements::lilLeft() {                   // metodo para pequeños pasos a la izquierda

  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);

  servoFL.write(0);
  servoBL.write(0);
  servoFR.write(0);
  servoBR.write(0);


  delay(ll_size);

  servoFL.detach();
  servoBL.detach();
  servoFR.detach();
  servoBR.detach();
  delay(300);

}

void Movements::lilRight() {                       // metodo para pequeños pasos a la derecha

  servoFL.attach(sm_FL);
  servoBL.attach(sm_BL);
  servoFR.attach(sm_FR);
  servoBR.attach(sm_BR);

  servoFL.write(180);
  servoBL.write(180);
  servoFR.write(180);
  servoBR.write(180);


  delay(lr_size);

  servoFL.detach();
  servoBL.detach();
  servoFR.detach();
  servoBR.detach();
  delay(300);

}


// Take a decision: {0: Right, 1: Left; 2: Little left; 3: Little right; 4:Fwd}
void Movements::moves(byte action) {

  //Movements mov = Movements(sm_FL, sm_BL, sm_FR, sm_BR);

  switch (action) {
    case 0:
      this->turnRight();
      break;
    case 1:
      this->turnLeft();
      break;
    case 2:
      this->lilLeft();
      break;
    case 3:
      this->lilRight();
      break;
    case 4:
      this->forward();
      break;
    case 5:
      this->back();
      this->turnRight();
      break;
    case 6:
      this->stp();
      break;
    case 7:
      this->stp();
      break;
  }

}
