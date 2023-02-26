#ifndef _UART_H_
#define _UART_H_

#include "../RegistersMap.h"
#include "../Utils.h"
#include "UART_CONFG.h"

void UART_Init();
void UART_Send(unsigned char); //uint8
void UART_Receive(unsigned char*, unsigned char);
#endif