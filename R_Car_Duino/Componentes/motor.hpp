#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

class MotorComponent
{
public:
    uint8_t Motor_Pin;

    MotorComponent(uint8_t motor_Pin)
    {
        Motor_Pin = motor_Pin;
    }

    void Init()
    {
        pinMode(Motor_Pin, OUTPUT);
        TurnOff();
    }

    void TurnOn()
    {
        digitalWrite(Motor_Pin, HIGH);
    }

    void TurnOff()
    {
        digitalWrite(Motor_Pin, LOW);
    }
};

#endif // MOTOR_HPP
