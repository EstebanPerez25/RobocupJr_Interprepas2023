// LIBRARIES
#include < .h>

class Compass {           // creacion de clase Compass 

  private:

    // OBJECT            
    MechaQMC5883 qmc;

  public:
    Compass();           // declaracion de constructor 

    int x, y, z;         // declaracion de variables de los ejes x,y,z
    int azimuth;         // declaracion de varable a

    
    // METHODS           // declaracion de metodos con compass
    void alineation();

};
// CONSTRUCTOR            // definicion de constructor
Compass::Compass() {

}
void Compass::alineation() {                // metodo de visualizacion de los ejes para implementarse en Movements.h para las vueltas tanto izquierda como derecha                   

  qmc.init();
  //qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_256);

  qmc.read(&x, &y, &z, &azimuth);

  Serial.print("x: ");            // visualizacion de los ejes 
  Serial.print(x);
  Serial.print(" y: ");
  Serial.print(y);
  Serial.print(" z: ");
  Serial.print(z);
  Serial.print(" a: ");
  Serial.print(azimuth);
  Serial.println();
  delay(100);
}
