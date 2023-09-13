// LIBRARIES
#include "Adafruit_TCS34725.h"


#define t 10

class ColorSens {

  private:
    // OBJECT
    Adafruit_TCS34725 tcs = Adafruit_TCS34725();
    int rgbMatrix [3][3];
    int initialRgbMatrix[3][3];
  public:
    ColorSens();
    uint16_t r, g, b, c, colorTemp, lux;


    // METHODS
    void initial();
    void rgbValues();
    byte action();
};



// Constructor
ColorSens::ColorSens() {
  // Define rgb matrix
  int rgbMatrix[3][3] = {  // Rgb values for each color
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

}



// Intialize the sensor
void ColorSens::initial() {
  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}


// Show rgb values to calibration
void ColorSens::rgbValues() {
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
  delay(10);
}


// Return the color
byte ColorSens::action() {
  this->rgbValues();

  // negro
  if ( this->r > rgbMatrix[0][0] - t &&  this->r < rgbMatrix[0][0] + t && this->g > rgbMatrix[0][1] - t &&  this->g < rgbMatrix[0][1] + t && this->b > rgbMatrix[0][2] - t &&  this->b < rgbMatrix[0][2] + t) {
    
   return 5;
  }
  // azul
  else if ( this->r > rgbMatrix[1][0] - t &&  this->r < rgbMatrix[1][0] + t && this->g > rgbMatrix[1][1] - t &&  this->g < rgbMatrix[1][1] + t && this->b > rgbMatrix[1][2] - t &&  this->b < rgbMatrix[1][2] + t) {
   
  return 6;
  }
  // plata
  else if ( this->r > rgbMatrix[2][0] - t &&  this->r < rgbMatrix[2][0] + t && this->g > rgbMatrix[2][1] - t &&  this->g < rgbMatrix[2][1] + t && this->b > rgbMatrix[2][2] - t &&  this->b < rgbMatrix[2][2] + t) {
   
  return 7;
  }
}
