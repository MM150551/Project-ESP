#include "MCAL/ADC.h"
#include <avr/delay.h>

void ADC_Init(void)
{
    // SELECTING VOLTAGE REFRENCE
    ADMUX  &= ~ADC_VoltageRefMask;
    ADMUX  |=  ADC_VoltageRefMode;

    // SELECTRING BETWEEN TRIGGER AND SINGLE CONVERSION MODE
    #if ADC_ModeSelect == ADC_AutoTrigger
        ADCSRA |= (1 << ADATA);
        SFIOR &= ~ADC_AutoTrigSRCMask;
        SFIOR |= (ADC_AutoTrigerMode);
    #else
        ADCSRA &= (0 << ADATA);
    #endif

    // SELLECTRING ADJUSTMENT 

    /*
    YOUR SELECTOR CODE GOES HERE
    RIGHT ADJUSTMENT BY DEFAULT
    */

    // SETTING PRESCALLER   ;   BITs 0,1,2
    ADCSRA &= ~ADC_PrescalerMask; // CLearing prescaller bits
    ADCSRA |= (ADC_PrescalerMode); // Setting prescaller bits
    
    // CLEARING INTERRUPT REGISTER
    ADCSRA |= (1 << ADIF);

    // ADC ENABLEMENT   ;   BIT-7: ADEN
    ADCSRA |= (1 << ADEN);

}

unsigned int ADC_getRead(unsigned char channel)
{
    // CLEARING OLD READS FROM BITs 0,1,2,3,4
    ADMUX &= 0b11110000;
   
    // CHANNEL SELCTION USING ONLY BITs 0,1,2,3
    ADMUX |= channel;
   
    // ADC START COVERSION  ;   BIT-6: ADSC
    ADCSRA |= (1 << ADSC);
    //STOP UNTILL THE CONVERSION PROCESS IS DONE
    while (( ADCSRA & (1 << ADIF) ) == 0 );
    return ADCL | ( ADCH << 8 ) ; 
}