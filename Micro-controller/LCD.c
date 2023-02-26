#include "HAL/LCD.h"
/********************************************************************/
/*
This code implements functions for controlling an LCD display.
The functions include:
                      initializing the LCD.
                      writing commands.
                       writing data to the LCD.
                      setting the cursor position.
                      writing a string of characters.
                      converting an integer to a string.
                      and writing an integer to the LCD.

The code assumes the existence of certain macros and ports that control the LCD, such as:
***************************** THESE MACROS ARE LOCATED AT LCD_CONFG.H ************************
                      LCD_Data.           [ DATA PORT REGISTER ]
                      LCD_DataDirection.  [ DATA PORT DIRECTION REGISTER ]
                      LCD_CTRL.           [ CONTROL PORT REGISTER ]
                      LCD_CTRLDirection.  [ CONTROL PORT REGISTER ]
                      RS.                 [ RS PIN NUMBER (IN CTRL PORT REGISTER)]
                      RW.                 [ RW PIN NUMBER (IN CTRL PORT REGISTER)]
                      EN.                 [ EN PIN NUMBER (IN CTRL PORT REGISTER)]
                      
The _delay_ms function is used for waiting for a specified number of milliseconds.
*/

void LCDInit()
{
    LCD_DataDirection = 0x0FF;              //Setting LCD data port direction
    LCD_CTRLDirection = 0x0FF;              //Setting LCD control port direction
    _delay_ms(10);
    LCDWriteCommand(LCD_INIT);              //initialization
    _delay_ms(1);
    LCDWriteCommand(LCD_CLEAR);             //Clear LCD
    _delay_ms(1);
    LCDWriteCommand(LCD_RETURN);            //Return home
    _delay_ms(1);
    LCDWriteCommand(LCD_INCREASMENT);       //increasment cursor
    _delay_ms(1);
    LCDWriteCommand(LCD_GOTOFIRSTLINE);     //go to first line
    _delay_ms(10);
    LCDWriteCommand(LCD_DISPLAYCURSOR);
    _delay_ms(10);
}

void LCDWriteCommand(unsigned char cmd)
{
    LCD_Data = cmd;        // PORTB == cmd command
    LCD_CTRL &= ~(1 << RS);
    LCD_CTRL &= ~(1 << RW);
    LCD_CTRL |=  (1 << EN);
    _delay_ms(10);
    LCD_CTRL &= ~(1 << EN);
}

void LCDWriteData(unsigned char data)
{
    LCD_Data = data;        // PORTB == cmd command
    LCD_CTRL |=  (1 << RS);
    LCD_CTRL &= ~(1 << RW);
    LCD_CTRL |=  (1 << EN);
    _delay_ms(2);
    LCD_CTRL &= ~(1 << EN);
}

void LCD_CursorPos(unsigned char x, unsigned char y)
{
    unsigned char Address; //address: 0x80 for the 1st position
    switch (x)
    {
        case 0: Address = 0x80; break;
        case 1: Address = 0xc0; break;
    }
    if (y < 16)
    {
        Address += y;
    }
    LCDWriteCommand(Address);
}

void LCD_WriteString(unsigned char *string)
{   
    int i = 0;
    while(string[i] != '\0' && (i) < 16)
    {
        LCDWriteData(string[i]);
        i+=1;
    }
}

void getString(int num, char *str) {
  char *p = str;
  int sign = 1;

  if (num < 0) {
    sign = -1;
    num = -num;
  }

  do {
    *p++ = (num % 10) + '0';
    num /= 10;
  } while (num > 0);

  if (sign == -1) {
    *p++ = '-';
  }

  *p = '\0';

  // Reverse the string
  char *start = str;
  char *end = p - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

void LCD_WriteInt(int number)
{
    char string[16];
    getString(number, string);
    LCD_WriteString(string);
}

/*
void LCD_WriteFloat(float number)
{
    LCD_WriteString(float_to_char(number, 1000));
}
*/