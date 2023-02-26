#include "MCAL/UART.h"
#include "MCAL/uart_confg.h"

void UART_Init()
{ 
	UCSRB |= (1 << RXEN) | (1 << TXEN);	                        
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);        
	UBRRL = (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)	;			                            
	UBRRH = ( (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)	 >> 8);	
	UCSRB |= (1 << RXCIE);	                        
}


void UART_Send(unsigned char data)
{
    while(!CHECK_BIT(UCSRA, UDRE));
    UDR = data;    
}

unsigned char UART_ReceiveByte()
{
    while (!(CHECK_BIT(UCSRA, RXC)));
    return UDR;
}

void UART_Receive(unsigned char* buff, unsigned char term)
{
    unsigned char i = 0;
	buff[i] = UART_ReceiveByte();
	while(buff[i] != term && buff[i] != '\0')
	{
		i++;
		buff[i] = UART_ReceiveByte();
	}
	buff[i] = '\0';
}
