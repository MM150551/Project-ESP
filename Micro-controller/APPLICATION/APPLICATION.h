#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "APP_CONFG.h"
#include "..\MCAL\UART.h"
#include "..\MCAL\ADC.h"
#include "..\MCAL\Interrupt.h"
#include "..\HAL\MOTOR.h"
#include "..\HAL\LCD.h"
#include "..\Utils.h"

#define APP_LDR_READ            ADC_getRead(APP_LDR_PIN_NUM)
#define APP_LDR_STATE           (APP_LDR_READ < APP_LDR_THRESHOLD)

void APP_Init();
void APP_ReceiveData(unsigned char*, unsigned char);
unsigned char APP_DOOR_Checker();
void APP_TAKE_DECISION(unsigned char*);
void APP_TroubleShoot();


#endif