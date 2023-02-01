/*
Programa para Control de RC mediante comunicación BT
Autor: YB
Fecha: 10/01/2023
*/

#include <SoftwareSerial.h>
#include <Servo.h>
#include "Config/config.h"
#include "Componentes/motor.hpp"

SoftwareSerial miSerial(RX_PIN, TX_PIN); // RX, TX
Servo servo;
MotorComponent motor(MOTOR_PIN);

float res = 0;


void setup() {
  
  Serial.begin(9600);
  miSerial.begin(38400);
  servo.attach(SERVO_PIN, PULSO_MIN, PULSO_MAX);

}

void loop() {
  
  // servo.write(0);  // el servo de posiciona en el angulo que le ingresamos como parámetro
  // delay(5000);
  // servo.write(180);  // el servo de posiciona en el angulo que le ingresamos como parámetro
  // delay(5000);


  res += (PULSO_MAX - PULSO_MIN)*0.35;
  if(res>10000) res = 340;
  delay(1000);
  Serial.println((String) "Reaultado: " + res);

}
