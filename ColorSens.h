// LIBRARIES
#include "Adafruit_TCS34725.h"

class ColorSens {                // creacion de clase ColorSens

  private:

    // OBJECT
    Adafruit_TCS34725 tcs = Adafruit_TCS34725();


  public:
    ColorSens();            // declaracion de constructor 


    // METHODS              // declaracion de metodos para el sensor de color 
    void initial();
    void color();

};
ColorSens::ColorSens() {       // definicion de constructor 

}
void ColorSens::initial() {                // metodo para iniciar el sensor de color 
  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }

}

void ColorSens::color() {                   // metodo para la visualizacion r,g y b para las losas de colores en el laberinto, se incorporaran los valores de r,g,b a clase Program 
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);

  Serial.print("Temperatura color: "); Serial.print(colorTemp, DEC); Serial.println(" K");
  Serial.print("Lux : "); Serial.println(lux, DEC);
  Serial.print("Rojo: "); Serial.println(r, DEC);
  Serial.print("Verde: "); Serial.println(g, DEC);
  Serial.print("Azul: "); Serial.println(b, DEC);
  Serial.print("Clear: "); Serial.println(c, DEC);
  Serial.println(" ");
  delay(1000);
}
