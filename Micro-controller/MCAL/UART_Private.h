#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

/*****************************************************/
/********************** SETTINGS *********************/
/*****************************************************/

// Baud Rate
#define UART_BAUD_RATE_4800         4800
#define UART_BAUD_RATE_9600         9600
#define UART_BAUD_RATE_19200        19200
#define UART_BAUD_RATE_38400        38400
#define UART_BAUD_RATE_57600        57600
#define UART_BAUD_RATE_115200       115200

// UART Parity Mode
#define UART_PARITY_MODE_NONE       0 // 0 = None
#define UART_PARITY_MODE_EVEN       1 // 1 = Even
#define UART_PARITY_MODE_ODD        2 // 2 = Odd

// UART Stop Bit
#define UART_STOP_BIT_1             1 // 1 stop bit
#define UART_STOP_BIT_2             2 // 2 stop bits

// UART Data Size
#define UART_DATA_SIZE_5            5 // 5 bits
#define UART_DATA_SIZE_6            6 // 6 bits
#define UART_DATA_SIZE_7            7 // 7 bits
#define UART_DATA_SIZE_8            8 // 8 bits

// UART Receive Interrupt Enable
#define UART_ENABLE_RX_INT          1 // 1 = Enable, 0 = Disable
#define UART_DISABLE_RX_INT         0 // 1 = Enable, 0 = Disable

// UART Transmit Interrupt Enable
#define UART_ENABLE_TX_INT           1 // 1 = Enable, 0 = Disable
#define UART_DISABLE_TX_INT          0 // 1 = Enable, 0 = Disable

#endif