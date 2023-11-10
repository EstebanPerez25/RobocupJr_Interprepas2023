// LIBRARIES
#include <Servo.h>

class Dispenser {

  private:
    uint8_t sm_Dis;

    // OBJECTS
    Servo servoDis;  // front-left

  public:
    Dispenser(uint8_t sm_Dis);

    byte action;

    // METHODS
    byte drop(byte action);

};


Dispenser::Dispenser(uint8_t _sm_Dis) {
  sm_Dis = _sm_Dis;


  servoDis.attach(sm_Dis);
  servoDis.write(90);
  servoDis.detach();


  Serial.begin(9600);
  Serial.println("OK COLORSENSOR");
}


byte Dispenser::drop(byte action) {
  servoDis.attach(sm_Dis);

  switch (action) {
    case 0:
      servoDis.write(120);
      delay(500);
      servoDis.write(170);
      delay(500);
      break;


    case 1:
      servoDis.write(120);
      delay(500);
      servoDis.write(170);
      delay(500);
      servoDis.write(120);
      delay(500);
      servoDis.write(170);
      delay(500);
      break;
  }

  servoDis.detach();
}
