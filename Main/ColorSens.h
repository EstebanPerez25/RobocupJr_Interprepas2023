// LIBRARIES
#include "Adafruit_TCS34725.h"
class ColorSens {                
  private:
    // OBJECT
    Adafruit_TCS34725 tcs = Adafruit_TCS34725();
  public:
    ColorSens();           
    // METHODS             
    void initial();
    void color();

};
ColorSens::ColorSens() {     
}
void ColorSens::initial() {                
  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}
void ColorSens::color() {                   
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  Serial.print("Temperatura color: "); Serial.print(colorTemp, DEC); Serial.println(" K");
  Serial.print("Lux : "); Serial.println(lux, DEC);
  Serial.print("R: "); Serial.println(r, DEC);
  Serial.print("G: "); Serial.println(g, DEC);
  Serial.print("B: "); Serial.println(b, DEC);
  Serial.print("Clear: "); Serial.println(c, DEC);
  Serial.println(" ");
  delay(1000);
}
