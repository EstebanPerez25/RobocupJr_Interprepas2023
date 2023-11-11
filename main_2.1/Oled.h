// LIBRARIES
#include <Wire.h>     // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306

#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64

#define OLED_RESET 4      // necesario por la libreria pero no usado


Adafruit_SSD1306 oledX(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto


class Oled {

  private:
    byte action;


  public:
    Oled();


    // METHODS
    byte showDisp(byte action);

};



Oled::Oled() {
Wire.begin();
oledX.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C

//
//  oledX.clearDisplay();      // limpia pantalla
//  oledX.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
//  oledX.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
//  oledX.setTextSize(1);      // establece tamano de texto en 1
//  oledX.print("READY");  // escribe en pantalla el texto
//  oledX.display();     // muestra en pantalla todo lo establecido anteriormente


  Serial.println("OK OLED");
}


byte Oled::showDisp(byte action) {

  // Limpiar buffer
  oledX.clearDisplay();

  switch (action) {
    // --------------------------
    // H
    // --------------------------
    case 0:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("H");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;

    // --------------------------
    // S
    // --------------------------
    case 1:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("S");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;

    // --------------------------
    // ROJO
    // --------------------------
    case 2:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("R");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;

    // --------------------------
    // AMARILLO
    // --------------------------
    case 3:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("A");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;

    // --------------------------
    // NEGRO
    // --------------------------
    case 4:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("N");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;

    // --------------------------
    // AZUL
    // --------------------------
    case 5:
      // Tamaño del texto
      oledX.setTextSize(9);
      // Color del texto
      oledX.setTextColor(SSD1306_WHITE);
      // Posición del texto
      oledX.setCursor(40, 0);
      // Escribir texto
      oledX.println("B");
      // Enviar a pantalla
      oledX.display();
      delay(3500);
      break;
  }
}
