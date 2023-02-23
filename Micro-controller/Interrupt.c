#include "MCAL\Interrupt.h"

/*
void EXT_INIT(void)
{
    GICR = 0x00;
    MCUCR = 0x00;
    MCUCSR = 0x00;

    #if   INT0_ModeSelect == EINT_LowLevel
        MCUCR |= EINT_LowLevel;
    #elif INT0_ModeSelect == EINT_LogicalChange
        MCUCR |= EINT_LogicalChange;
    #elif INT0_ModeSelect == EINT_FalleEdge
        MCUCR |= EINT_FalleEdge;
    #elif INT0_ModeSelect == EINT_RisingEdge
        MCUCR |= EINT_RisingEdge;
    #endif

    #if   INT1_ModeSelect == EINT_LowLevel
        MCUCR |= EINT_LowLevel << INT1_ModeShift;
    #elif INT1_ModeSelect == EINT_LogicalChange
        MCUCR |= EINT_LogicalChange << INT1_ModeShift;
    #elif INT1_ModeSelect == EINT_FalleEdge
        MCUCR |= EINT_FalleEdge << INT1_ModeShift;
    #elif INT1_ModeSelect == EINT_RisingEdge
        MCUCR |= EINT_RisingEdge << INT1_ModeShift;
    #endif

    #if   INT2_ModeSelect == EINT2_FallenEdge
        MCUCSR &= EINT2_FallenEdge << ISC2;
    #elif INT2_ModeSelect == EINT2_RisingEdge
        MCUCSR |= EINT2_RisingEdge << ISC2;
    #endif



    #if   EXTI_PIN0 == ACTIVE
        GICR   |= (1 << INT0);

    #elif EXTI_PIN0 == DEACTIVE
        GICR   &= ~(1 << INT0);
    #endif

    #if   EXTI_PIN1 == ACTIVE
        GICR   |= (1 << INT1);

    #elif EXTI_PIN1 == DEACTIVE
        GICR   &= ~(1 << INT1);
    #endif

    #if   EXTI_PIN2 == ACTIVE
        GICR   |= (1 << INT2);

    #elif EXTI_PIN2 == DEACTIVE
        GICR   &= ~(1 << INT2);
    #endif

// GLOBAL INTERRUPT ENABLE
    SREG |= (1 << 7);
}
*/
void EXT_INIT(void)
{
    GICR |= (1 << INT0);
    MCUCR |= (EINT_RisingEdge);
    __asm__ __volatile__("sei");
}

void (*callBackPtr1) (void) = 0;
void (*callBackPtr2) (void) = 0;
void (*callBackPtr3) (void) = 0;

void EXTI_CallBackINT0( void (*ptr) (void) )
{
    callBackPtr1 = ptr;
}

void EXTI_CallBackINT1( void (*ptr) (void) )
{
    callBackPtr2 = ptr;
}

void EXTI_CallBackINT2( void (*ptr) (void) )
{
    callBackPtr3 = ptr;
}

void __vector_1(void) __attribute__((signal, used));
void __vector_2(void) __attribute__((signal, used));
void __vector_3(void) __attribute__((signal, used));

void __vector_1(void)
{   
    if (callBackPtr1 != 0)
    callBackPtr1();
}

void __vector_2(void)
{
    if (callBackPtr2 != 0)
    callBackPtr2();
}

void __vector_3(void)
{
    if (callBackPtr3 != 0)
    callBackPtr3();
}