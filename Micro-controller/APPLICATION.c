#include "APPLICATION/APPLICATION.h"

#define openDoor             1
#define closeDoor            0

#define DOOR_IS_COMPLETELY_OPENED         CHECK_BIT(OPEN_DOOR_INDICATION_SWITCH_PIN, OPEN_DOOR_INDICATION_SWITCH_PIN_NUM)
#define DOOR_IS_COMPLETELT_CLOSED         CHECK_BIT(CLOSE_DOOR_INDICATION_SWITCH_PIN, CLOSE_DOOR_INDICATION_SWITCH_PIN_NUM)     

//the 2 sympols must be char type
#define ACCEPTANCE_SYMPOL                   (unsigned char)'1'
#define DENIAL_SYMPOL                       (unsigned char)'0'   

unsigned char compare(unsigned char *, unsigned char *);

void APP_Init()
{
    UART_Init();

    LCDInit();

    MOTOR_Init();

    ADC_Init();

    EXT_INIT();

    //Setting opened door switch as an input
    OPEN_DOOR_INDICATION_SWITCH_DDR &=  ~(1 << OPEN_DOOR_INDICATION_SWITCH_PIN);
    //Setting closed door switch as an input
    CLOSE_DOOR_INDICATION_SWITCH_DDR &= ~(1 << CLOSE_DOOR_INDICATION_SWITCH_PIN);

    //troupleshoot switch
    APP_TROUBLESHOOT_DDR &= ~(1 << APP_TROUBLESHOOT_PIN_NUM);

    //LDR PIN
    APP_LDR_DDR &= ~(1 << APP_LDR_PIN_NUM);


    LCD_WriteString("ATTENDANCE SYSTEM");
    _delay_ms(500);
    LCDWriteCommand(LCD_CLEAR);
    LCD_CursorPos(0, 0);
    LCD_WriteString("WAITING FOR UART");
}

void APP_ReceiveData(unsigned char* Buffer, unsigned char termination)
{
    UART_Receive(Buffer, termination);
}

void APP_DOOR_ClOSE()
{
    //closing the door
    MOTOR_Direction(closeDoor);
    //while the closed sensor reads 1, it mean that the door hasen't been closed yet
    //if it detects 0, stop the motor
    while ( !DOOR_IS_COMPLETELT_CLOSED );
    MOTOR_STOP();
}

void APP_DOOR_OPEN()
{
    //opening the door
    MOTOR_Direction(openDoor);
    //waiting for the sensor to detect reading
    //while the door is not completetly opened, continue openening the door. else, stop
    while ( !DOOR_IS_COMPLETELY_OPENED ); //CPU will be stucked in the while loop until the door is opened
    MOTOR_STOP();
}


/*
========> unsigned char APP_DOOR_Checker() <========


This function is checking whether the door is completely closed and completely opened by calling two macros
DOOR_IS_COMPLETELY_CLOSED and DOOR_IS_COMPLETELY_OPENED.
If both conditions are true, the function will clear the LCD screen,
write a message "CHECK DOOR's" on the first line and "SWITCHS" on the second line,
and return 0 indicating that the check failed.
Otherwise, the function will return 1 indicating that the check passed.
*/


void APP_DOOR_ERROR()
{
    MOTOR_STOP();
    LCDWriteCommand(LCD_CLEAR);
    while (!APP_DOOR_Checker())
    {
        LCD_CursorPos(0, 0);
        LCD_WriteString("CHECK DOOR's");
        LCD_CursorPos(1, 0);
        LCD_WriteString("SWITCHS");
    }
}

unsigned char APP_DOOR_Checker()
{
    if ((DOOR_IS_COMPLETELY_OPENED &&  !DOOR_IS_COMPLETELT_CLOSED) || (!DOOR_IS_COMPLETELY_OPENED && !DOOR_IS_COMPLETELT_CLOSED))
    {
        APP_DOOR_ClOSE();
        return 1;
    }
    else 
    if ((!DOOR_IS_COMPLETELY_OPENED &&  DOOR_IS_COMPLETELT_CLOSED))
    {
        return 1;
    }
    else
    if (DOOR_IS_COMPLETELY_OPENED && DOOR_IS_COMPLETELT_CLOSED) // 1 && 1
    {
        return 0;
    }
}

//
//THIS FUNCTION OPENS AND CLOSES THE DOOR
//

void APP_DOOR_TakeAction()
{
    APP_DOOR_OPEN();

    _delay_ms(500);

    APP_DOOR_ClOSE();
}


void APP_TAKE_DECISION(unsigned char* Buffer)
{
    unsigned char door_check_result = APP_DOOR_Checker();

    if (door_check_result && Buffer[0] == DENIAL_SYMPOL)
    {
        LCDWriteCommand(LCD_CLEAR);
        LCD_CursorPos(0, 0);
        LCD_WriteString("UNKNOWN");
    }
    else if (door_check_result && Buffer[0] == ACCEPTANCE_SYMPOL && DENIAL_SYMPOL)
    {
        LCDWriteCommand(LCD_CLEAR);
        LCD_WriteString("WELCOME");
        LCD_CursorPos(1, 0);
        LCD_WriteString(Buffer);
        APP_DOOR_TakeAction();
    }
    else if (!door_check_result)
    {
        APP_DOOR_ERROR();
    }
    else if (door_check_result)
    {
        LCDWriteCommand(LCD_CLEAR);
        LCD_CursorPos(0, 0);
        LCD_WriteString("WAITING FOR UART");
    }
}

void APP_TroubleShoot()
{
    //check for 2 switches
    LCDWriteCommand(LCD_CLEAR);
    LCD_WriteString("TroubleShooting MODE");
    _delay_ms(2500);
    LCDWriteCommand(LCD_CLEAR);
    LCD_WriteString("Press SW1");

    while (!CHECK_BIT(CLOSE_DOOR_INDICATION_SWITCH_PIN, CLOSE_DOOR_INDICATION_SWITCH_PIN_NUM));
    LCD_CursorPos(1, 0);
    LCD_WriteString("SW1 is CLOSED");
    _delay_ms(1500);
    LCDWriteCommand(LCD_CLEAR);
    LCD_WriteString("Press SW2");

    while (!CHECK_BIT(OPEN_DOOR_INDICATION_SWITCH_PIN, OPEN_DOOR_INDICATION_SWITCH_PIN_NUM));
    LCD_CursorPos(1, 0);
    LCD_WriteString("SW2 is CLOSED");
    _delay_ms(1500);
    LCDWriteCommand(LCD_CLEAR);
    LCD_WriteString("ALL IS DONE");
}

unsigned char compare(unsigned char *a, unsigned char *b)
{
    unsigned char flag = 0;
    while (*a != '\0' && *b != '\0') // while loop
    {
        if (*a != *b)
        {
            flag = 1;
        }
        a++;
        b++;
    }
 if(*a!='\0'||*b!='\0')
       return 0;
    if (flag == 0)
        return 1;
    else
        return 0;
}