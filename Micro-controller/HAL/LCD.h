#include "../RegistersMap.h"
#include "LCD_Confg.h"
#include <avr/delay.h>

void LCDInit(void);
void LCDWriteCommand(unsigned char);
void LCDWriteData(unsigned char);
void LCD_CursorPos(unsigned char, unsigned char);
void LCD_WriteString(unsigned char*);
void LCD_WriteInt(int);
void LCD_WriteFloat(float);