// LIBRARIES
#include <Servo.h>


class Dispenser{

private:
 uint8_t sm_DS;

  // OBJECTS
    Servo servoDS;  // dispenser 

public:
Dispenser(uint8_t _sm_DS);

byte dispense;

// METHODS
void dispenseKit(byte dispense);
  
};
Dispenser::Dispenser(uint8_t _sm_DS){
  sm_DS = _sm_DS;
}
void Dispenser::dispenseKit(byte dispense){

switch(dispense){

case 0:
   servoDS.write(0);             
    delay(15);                    
    servoDS.write(180);                  
    delay(15);   
              
break;
case 1:
   servoDS.write(0);             
    delay(15);                    
    servoDS.write(180);                  
    delay(15);             
   servoDS.write(0);             
    delay(15);                    
    servoDS.write(180);                  
    delay(15);  
               
break;
}
}