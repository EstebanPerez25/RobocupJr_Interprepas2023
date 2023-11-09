class CameraESP {

  private:
    // PINOUT
    byte p1;
    byte p2;
    byte p3;
    bool crash[3];  // entradas de la camara ESP32
    byte victim;

  public:
    CameraESP(byte p1, byte p2, byte p3);

    // METHODS
    byte action();


};
CameraESP::CameraESP(byte _p1, byte _p2, byte _p3) {
  p1 = _p1;
  p2 = _p2;
  p3 = _p3;


  Serial.begin(9600);
  Serial.println("OK CAMERAESP32");
}


byte CameraESP::action() {
  // phase 1
  crash[0] = digitalRead(p1);
  crash[1] = digitalRead(p2);
  crash[2] = digitalRead(p3);

  // phase 2
  victim = crash[2] + crash[1] * 2 + crash[0] * 4

           // phase 3
  switch (victim) {
    case 0:
      return 4;    // NADA 
      break;
    case 1:
      return 1;    // ROJO
      break;
    case 2:      // AMARILLO
      return 0;
      break;
    case 3:      // H
      return 1;
      break;
    case 4:      // S
      return 0;
      break;
  }


}
