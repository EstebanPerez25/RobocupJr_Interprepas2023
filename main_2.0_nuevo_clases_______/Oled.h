// LIBRARIES
#define __DEBUG__
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64


#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>




class Oled {

  private:
    // OBJECT
    Adafruit_SSD1306 display;

  public:
    Oled();


    byte action;

    // METHODS
    byte showDisp(byte action);

};



Oled::Oled(): display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1) {
//#ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
//#endif

  // Iniciar pantalla OLED en la dirección 0x3C
//  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//#ifdef __DEBUG__
//    Serial.println("No se encuentra la pantalla OLED");
//#endif
//    while (true);
//  }

}


byte Oled::showDisp(byte action) {

  // Limpiar buffer
  display.clearDisplay();

  switch (action) {
    // --------------------------
    // H
    // --------------------------
    case 0:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("H");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;

    // --------------------------
    // S
    // --------------------------
    case 1:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("S");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;

    // --------------------------
    // ROJO
    // --------------------------
    case 2:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("R");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;

    // --------------------------
    // AMARILLO
    // --------------------------
    case 3:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("A");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;

    // --------------------------
    // NEGRO
    // --------------------------
    case 4:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("N");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;

    // --------------------------
    // AZUL
    // --------------------------
    case 5:
      // Tamaño del texto
      display.setTextSize(9);
      // Color del texto
      display.setTextColor(SSD1306_WHITE);
      // Posición del texto
      display.setCursor(40, 0);
      // Escribir texto
      display.println("B");
      // Enviar a pantalla
      display.display();
      delay(3500);
      break;
  }
}
