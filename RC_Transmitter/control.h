#ifndef CONTROL_H
#define CONTROL_H

#include <Arduino.h>
#include "config.h"

int DIR = 0;
int ACEL = 0;
int LEFT = 0;
int RIGHT = 0;

int VEL = 0;
int ROT = 0;
String MOVE;
String GIRO;

void controlVelocidad()
{
  // función --> "controlVelociddad" --> hay que ajustar los valores según Vr de Joystick
  if(ACEL > 512)
  {
    VEL = map(analogRead(pin_ACEL),512,1023,0,100);
    MOVE = "FW: ";
  }
  else if( ACEL < 512)
  {
    VEL = map(analogRead(pin_ACEL),512,0,0,100);   
    MOVE = "BW: ";
  }
  else 
  {
    VEL = 0;   
    MOVE = "STBY: ";        
  }
}

void controlDireccion()
{
  // Función --> "controlDeDireccion" --> hay que ajustar los valores según Vr de Joystick
  if(DIR > 512)
  {
    ROT = map(analogRead(pin_DIR),512,1023,0,90);  // hay que verificar y corregir angulo de giro
    GIRO = "LEFT: ";
  }
  else if( DIR < 512)
  {
    ROT = map(analogRead(pin_DIR),512,0,0,90);  // hay que verificar y corregir angulo de giro
    GIRO = "RIGHT: ";
  }
  else 
  {
    ROT = 0;   
    GIRO = "HOLD: ";        
  }
}

#endif