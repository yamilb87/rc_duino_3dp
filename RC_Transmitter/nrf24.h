#ifndef NRF_24_H
#define NRF_24_H

#include <Arduino.h>
#include <SPI.h>
#include <RH_NRF24.h>

#include "oled.h"

RH_NRF24 nrf24;   

void nrf24Init()
{
  if(!nrf24.init())
  {
    Serial.print("Fallo de Inicialización");
    // En oled
    oled.clearDisplay();
    oled.setCursor(10,20);
    oled.setTextColor(WHITE);	
    oled.print("FALLO COMUNICACION");
    oled.display();
    delay(2000);
  }

  if(!nrf24.setChannel(2))
  {
    Serial.print("Fallo en establecer canal");
    // En oled
    oled.clearDisplay();
    oled.setCursor(20,20);
    oled.setTextColor(WHITE);	
    oled.print("FALLO EN CANAL");
    oled.display();
    delay(1000);
  }

  if(!nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm))
  {
    Serial.print("Fallo en opciones de RF");
    // En oled
    oled.clearDisplay();
    oled.setCursor(30,20);
    oled.setTextColor(WHITE);	
    oled.print("FALLO EN RF");
    oled.display();
    delay(1000);
  }

  Serial.print("Base Iniciada");
  // en oled
  oled.clearDisplay();
  oled.setCursor(47,40);
  oled.setTextColor(WHITE);	
  oled.print("READY!");
  oled.display();
  delay(1000);

}



#endif // NRF_24_HPP

