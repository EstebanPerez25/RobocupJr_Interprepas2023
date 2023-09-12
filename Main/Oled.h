#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "I2Cdev.h"

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

// MPU control
bool dmpReady = false;  
uint8_t mpuIntStatus;   
uint8_t devStatus;      
uint16_t packetSize;    
uint16_t fifoCount;     
uint8_t fifoBuffer[64]; 

void displayOLED() {

  display.clearDisplay();

  display.setTextSize(9);

  display.setTextColor(SSD1306_WHITE);

  display.setCursor(40, 0);
  
  display.println("hola");

  display.display();

  delay(5500);

  display.clearDisplay();

  display.display();
}







void setup() {

#ifdef __DEBUG__
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
#endif

  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
  display.clearDisplay();

  // Tamaño del texto
  display.setTextSize(1);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(10, 32);
  // Escribir texto
  display.println("EIAO BULLDOGERS !!!");

  // Enviar a pantalla
  display.display();

  Serial.println("* OLED  GOOD *"); delay(200);



void loop() {

displayOLED();

}
