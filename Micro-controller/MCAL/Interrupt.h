#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "Confg.h"
#include "../RegistersMap.h"

void EXT_INIT(void);
void EXTI_CallBackINT0( void (*ptr) (void) );
void EXTI_CallBackINT1( void (*ptr) (void) );
void EXTI_CallBackINT2( void (*ptr) (void) );

/*
 The external interrupts can be triggered by a falling or
rising edge or a low level (INT2 is only an edge triggered interrupt)

Note that recognition of falling
or rising edge interrupts on INT0 and INT1 requires the presence of an I/O clock
*/

//MCU Control Register
//Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
//Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0

#define EINT_LowLevel               (0 << 0) | (0 << 0)
#define EINT_LogicalChange          (1 << 0)
#define EINT_FalleEdge              (1 << 1)  
#define EINT_RisingEdge             (1 << 1) | (1 << 0)

#define EINT2_FallenEdge            0
#define EINT2_RisingEdge            1

#define INT0_ModeShift              0
#define INT1_ModeShift              2


//MCUCSR MCU Control and Status Register
#define ISC2                        6   //Bit 6 – ISC2: Interrupt Sense Control 2


// General Interrupt Control Register – GICR
#define INT1                        7   // Bit 7 – INT1: External Interrupt Request 1 Enable
#define INT0                        6   // Bit 6 – INT0: External Interrupt Request 0 Enable
#define INT2                        5   // Bit 5 – INT2: External Interrupt Request 2 Enable


#define ACTIVE                      1   // for confg file
#define DEACTIVE                    0   // for confg file

// General Interrupt Flag Register – GIFR
// When an edge or logic change on the INTx pin triggers an interrupt request, INTFx becomes set
// (one). If the I-bit in SREG and the INTx bit in GICR are set (one)

#define INTF1                       7   // Bit 7 – INTF1: External Interrupt Flag 1
#define INFT0                       6   // Bit 6 – INTF0: External Interrupt Flag 0
#define INFT2                       5   // Bit 5 – INTF2: External Interrupt Flag 2


#endif