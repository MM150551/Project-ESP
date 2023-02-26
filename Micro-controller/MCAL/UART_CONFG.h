#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "UART_Private.h"

// UART Configuration
#define F_CPU                       8000000
#define UART_BAUD_RATE              UART_BAUD_RATE_9600
#define UART_SPEED                  UART_SPEED_NORMAL
#define UART_PARITY_MODE            UART_PARITY_MODE_NONE 
#define UART_STOP_BIT               UART_STOP_BIT_1 
#define UART_DATA_SIZE              UART_DATA_SIZE_8 
#define UART_RX_INT_ENABLE          UART_ENABLE_RX_INT
#define UART_TX_INT_ENABLE          UART_DISABLE_TX_INT

#endif /* UART_CONFIG_H_ */