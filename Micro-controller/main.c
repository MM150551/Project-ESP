/*This code is for an AVR microcontroller application that involves receiving data from a USART (universal synchronous/asynchronous receiver/transmitter)
and processing the data based on certain conditions. The code includes an interrupt service routine for handling USART receive interrupts
and an interrupt service routine for handling external interrupts (INT0).

The code initializes some variables and macros, including MAX_BUFFER_SIZE, which is set to 16. It also defines some global variables:
                    bufferIndex, buffer_flag, bufferIsTakenSucessfully, and recByte.

In the main function, the application is initialized by calling the APP_Init function, and a buffer is declared with a size of 16.
The function sei() is called to enable interrupts.
The code sets the data direction register (DDRB) and the port register (PORTB) for a specific pin (pin 0) of the AVR microcontroller.

The main loop consists of a switch statement that checks the value of buffer_flag.
If buffer_flag is 1, the switch statement checks the value of recByte. If recByte is '#', buffer_flag is set to 0, bufferIndex is set to 0,
and bufferIsTakenSucessfully is set to 1. Otherwise, the value of recByte is stored in the Buffer array, buffer_flag is set to 0,
and bufferIndex is incremented.

If buffer_flag is not 1, the switch statement checks if a specific condition is true, and if it is, the APP_TAKE_DECISION function is called
with the Buffer array as an argument, and the clrBuffer function is called to clear the contents of the Buffer array. If the condition is not true,
the APP_DOOR_ERROR function is called.

The code also includes two interrupt service routines. The USART_RXC_vect interrupt service routine handles USART receive interrupts.
When an interrupt occurs, the received byte is stored in the recByte variable, the received byte is echoed back by writing it to the USART data
register (UDR), the state of a specific pin of PORTB is toggled, buffer_flag is set to 1, and bufferIsTakenSucessfully is set to 0.

The INT0_vect interrupt service routine handles external interrupts. When an interrupt occurs, the APP_TroubleShoot function is called.

Finally, the code includes a clrBuffer function that takes a pointer to an unsigned char array as an argument and sets all the elements of the
array to 0.
*/




#include "APPLICATION\APPLICATION.h"



#define MAX_BUFFER_SIZE         16

volatile unsigned char bufferIndex = 0;
volatile unsigned char buffer_flag = 0;
volatile unsigned char bufferIsTakenSucessfully = 0;
volatile unsigned char recByte;


void clrBuffer(unsigned char*);
void formateTheBuffer(unsigned char*);

int main(int argc, char **argv)
{
    APP_Init();
    unsigned char Buffer[16];
    DDRB |= (1 << 0);
    PORTB |= ( 1 << 0);

    while (1)
    {
        switch (buffer_flag)
        {
        case 1:
            switch (recByte)
            {
                case '#':
                    buffer_flag = 0;
                    bufferIndex = 0;
                    bufferIsTakenSucessfully = 1;
                    break;
                default:
                    Buffer[bufferIndex] = recByte;
                    buffer_flag = 0;
                    (bufferIndex < MAX_BUFFER_SIZE)? bufferIndex ++: bufferIndex; //To avoid buffer overflow
                    break;
            }
            break;
        
        default:
            if (APP_DOOR_Checker() && bufferIsTakenSucessfully)
            {
                APP_TAKE_DECISION(Buffer);
                clrBuffer(Buffer);
            }
            else
            {
                APP_DOOR_ERROR();   
            }
           break;
        }

        if(CHECK_BIT(APP_TROUBLESHOOT_PIN, APP_TROUBLESHOOT_PIN_NUM))
        {
            APP_TroubleShoot();
        }
    }
    return 0;
}

ISR ( USART_RXC_vect )
{
    recByte = UDR;
    UDR = recByte;
    buffer_flag = 1;
    bufferIsTakenSucessfully = 0; //to indicate that baffer loading is in process
    PORTB ^= (1 << 0);
}
/*
ISR(INT0_vect)
{
    APP_TroubleShoot();
        PORTB ^= (1 << 0);
}
*/

void clrBuffer(unsigned char* Buffer)
{
    unsigned char i = 0;
    while (Buffer[i] != '\0')
    {
        Buffer[i] = 0;
        i++;
    }
}

