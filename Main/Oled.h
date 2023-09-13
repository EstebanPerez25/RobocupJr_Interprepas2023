#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED


// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

class Oled {

  private:


  public:
    Oled();

    byte dispColor;

    void initialOled();
    void showDisp(byte dispColor);

};
// constructor
Oled::Oled() {

}
void Oled::initialOled() {
  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
}
void Oled::showDisp(byte dispColor) {

  switch (dispColor) {
    case 5:
 // Limpiar buffer
  display.clearDisplay();

  // Tamaño del texto
  display.setTextSize(9);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(40, 0);
  // Escribir texto
  display.println("black");

  // Enviar a pantalla
  display.display();

  delay(5500);

  // Limpiar buffer
  display.clearDisplay();
  // Enviar a pantalla
  display.display();
      break;
      
    case 6:
 // Limpiar buffer
  display.clearDisplay();

  // Tamaño del texto
  display.setTextSize(9);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(40, 0);
  // Escribir texto
  display.println("blue");

  // Enviar a pantalla
  display.display();

  delay(5500);

  // Limpiar buffer
  display.clearDisplay();
  // Enviar a pantalla
  display.display();
      break;
      
    case 7:
 // Limpiar buffer
  display.clearDisplay();

  // Tamaño del texto
  display.setTextSize(9);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(40, 0);
  // Escribir texto
  display.println("plate");

  // Enviar a pantalla
  display.display();

  delay(5500);

  // Limpiar buffer
  display.clearDisplay();
  // Enviar a pantalla
  display.display();
      break;
}
