
#ifndef RegistersMap_H_
#define RegistersMap_H_

//DIO REGISTERS
#define PORTA	            	(*(volatile unsigned char*) 0x3B) 
#define DDRA		            (*(volatile unsigned char*) 0x3A) 
#define PINA		            (*(volatile unsigned char*) 0x39) 

#define PORTB		            (*(volatile unsigned char*) 0x38) 
#define DDRB		            (*(volatile unsigned char*) 0x37) 
#define PINB		            (*(volatile unsigned char*) 0x36) 

#define PORTC		            (*(volatile unsigned char*) 0x35) 
#define DDRC		            (*(volatile unsigned char*) 0x34) 
#define PINC		            (*(volatile unsigned char*) 0x33) 

#define PORTD		            (*(volatile unsigned char*) 0x32) 
#define DDRD		            (*(volatile unsigned char*) 0x31) 
#define PIND		            (*(volatile unsigned char*) 0x30) 

//ADC REGISTERS
#define ADMUX                   (*(volatile unsigned char*) 0x27)
#define ADCSRA                  (*(volatile unsigned char*) 0x26)
#define SFIOR                   (*(volatile unsigned char*) 0x50)
#define ADCL                    (*(volatile unsigned char*) 0x24)
#define ADCH                    (*(volatile unsigned char*) 0x25)
#define ADCLH                   (*(volatile unsigned long*) 0x24)
//ADC BITS

//ADCSRA BITs
#define ADEN                    7       // Enablement
#define ADSC                    6       // ADC Start Conversion
#define ADATA                   5       // Trigger mode enable (ADATA = 1);
#define ADIF                    4       // INTERRUPT FLAG (SET TO 1 TO CLEAR)

/*  EXI REGISTERS  */ 
#define SREG                    (*(volatile unsigned char*) 0x5f)
#define MCUCR                   (*(volatile unsigned char*) 0x55)
#define MCUCSR                  (*(volatile unsigned char*) 0x54)
#define GICR                    (*(volatile unsigned char*) 0x58)
#define GIFR                    (*(volatile unsigned char*) 0x5A)

//Timer Registers
#define TCNT0                   (*(volatile unsigned char*) 0x52)
#define TCNT1H                  (*(volatile unsigned char*) 0x4D)
#define TCNT1L                  (*(volatile unsigned char*) 0x4C)
#define TCCR0                   (*(volatile unsigned char*) 0x53)
#define TCCR2                   (*(volatile unsigned char*) 0x45)
#define TCCR1A                  (*(volatile unsigned char*) 0x4F)
#define TIMSK                   (*(volatile unsigned char*) 0x59)
#define OCR0                    (*(volatile unsigned char*) 0x5C)

//TCCR0 BITS
#define FOC0                    7
#define WGM00                   6
#define COM01                   5
#define COM00                   4
#define WGM01                   3
#define CS02                    2
#define CS01                    1
#define CS00                    0

//TIMSK BITS
#define TOIE0                   0
#define OCIE0                   1

//TCCR2
#define FOC2                    7
#define WGM20                   6
#define COM21                   5
#define COM20                   4
#define WGM21                   3
#define CS22                    2
#define CS21                    1
#define CS20                    0

//UART Registers
#define UDR   (*(volatile unsigned char *) 0x2C)
#define UCSRA (*(volatile unsigned char *) 0x2B)
#define UCSRB (*(volatile unsigned char *) 0x2A)
#define UCSRC (*(volatile unsigned char *) 0x40)
#define UBRRL (*(volatile unsigned char *) 0x29)
#define UBRRH (*(volatile unsigned char *) 0x40)

// UDR Register Bits
#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0

// UCSRA Register Bits
#define RXC7 7
#define TXC7 6
#define UDRE7 5
#define FE7 4
#define DOR7 3
#define UPE7 2
#define U2X7 1
#define MPCM7 0

// UCSRB Register Bits
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB8 0

// UCSRC Register Bits
#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0



#endif /* RegistersMap_H_ */