// LIBRARIES
#include <Wire.h>
#include "Adafruit_TCS34725.h"


#define t 0

class ColorSens {

  private:
    // OBJECT
    Adafruit_TCS34725 tcs = Adafruit_TCS34725();
    uint16_t r, g, b, c, colorTemp, lux;
    int rgbMatrix [3][3];

  public:
    ColorSens();

    // METHODS
    void rgbValues();
    byte action();
};

// Constructor
ColorSens::ColorSens() {

  Serial.begin(9600);
  Serial.println("OK COLORSENSOR");

  // Define rgb matrix
  int rgbMatrix[3][3] = {  // Rgb values for each color
    {0, 0, 0},
    {1, 1, 1},
    {1, 0, 1}
  };

//  // Intialize the sensor
//  if (!tcs.begin()) {
//    Serial.println("Error al iniciar TCS34725");
//    while (1) delay(1000);
//  }




}


// Show rgb values to calibration
void ColorSens::rgbValues() {

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
//    Serial.print("Temperatura color: "); Serial.print(colorTemp, DEC); Serial.println(" K");
//    Serial.print("Lux : "); Serial.println(lux, DEC);
//    Serial.print("R: "); Serial.println(r, DEC);
//    Serial.print("G: "); Serial.println(g, DEC);
//    Serial.print("B: "); Serial.println(b, DEC);
//    Serial.print("Clear: "); Serial.println(c, DEC);
//    Serial.println(" ");
  delay(10);
}


// Return the color
byte ColorSens::action() {
  this->rgbValues();

  // negro
  if ( this->r > rgbMatrix[0][0] - t &&  this->r < rgbMatrix[0][0] + t && this->g > rgbMatrix[0][1] - t &&  this->g < rgbMatrix[0][1] + t && this->b > rgbMatrix[0][2] - t &&  this->b < rgbMatrix[0][2] + t) {
    //Serial.println("negro");
    return 5;
  }
  // azul
  else if ( this->r > rgbMatrix[1][0] - t &&  this->r < rgbMatrix[1][0] + t && this->g > rgbMatrix[1][1] - t &&  this->g < rgbMatrix[1][1] + t && this->b > rgbMatrix[1][2] - t &&  this->b < rgbMatrix[1][2] + t) {
    //Serial.println("azul");
    return 6;
  }

  // plata
  else if ( this->r > rgbMatrix[2][0] - t &&  this->r < rgbMatrix[2][0] + t && this->g > rgbMatrix[2][1] - t &&  this->g < rgbMatrix[2][1] + t && this->b > rgbMatrix[2][2] - t &&  this->b < rgbMatrix[2][2] + t) {
    //Serial.println("plata");
    return 7;
  }

  // Blanco
  else {
    return 8;
  }
}
