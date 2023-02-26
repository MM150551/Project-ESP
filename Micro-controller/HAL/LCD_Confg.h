#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#include "LCD_Private.h"

#define EN                      0 
#define RW                      1
#define RS                      2

#define LCD_Data                PORTC 
#define LCD_DataDirection       DDRC

#define LCD_CTRL                PORTA 
#define LCD_CTRLDirection       DDRA

#endif