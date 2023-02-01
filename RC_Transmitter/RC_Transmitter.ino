/*
RC_Transmitter
Author: YB
Date: 26/01
Version: 0.0.1
*/

// HEADERS
#include "nrf24.h"
#include "oled.h"
#include "control.h"
#include "config.h"


void setup() {
  
  Serial.begin(9600);
  oledInit();   // Inicio de OLED
  nrf24Init();  // inicio de NRF24

  
  }

void loop() {

  // Definicion de variables - DIR: Direccion | ACEL: Aceleracion
  ACEL = analogRead(pin_ACEL);
  DIR = analogRead(pin_DIR);

  controlVelocidad();
  controlDireccion();

  oledRC();
  delay(200);
  
}
