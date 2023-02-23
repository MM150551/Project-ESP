#include "HAL/MOTOR.h"

void MOTOR_Init()
{
    MOTOR_DDR  |= ( (1 << MOTOR_IN1) | (1 << MOTOR_IN2) | (1 << MOTOR_EN) ); 
    MOTOR_STOP();
}


void MOTOR_STOP()
{
    MOTOR_PORT &= ~( (1 << MOTOR_IN1) | (1 << MOTOR_IN2) | (1 << MOTOR_EN));
}


void MOTOR_Direction(unsigned char status)
{
    MOTOR_STOP();
    switch (status)
    {
    case 0:
        MOTOR_PORT |=  ((1 << MOTOR_IN1) | (1 << MOTOR_EN));
        break;
    default:
        MOTOR_PORT |=  ((1 << MOTOR_IN2) | (1 << MOTOR_EN));
        break;
    }
}
