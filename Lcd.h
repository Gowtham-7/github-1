/****************************************************************************
* File Name   : Lcd.h
* Author      : Karthick R
* Version     : 0.1
* Date        : 31-Dec-2019
* Description : This file contains the Macro definition and various LCD display 
				functions declarations
****************************************************************************/

#ifndef Lcd_H
#define Lcd_H

/*=============================== INCLUSIONS ================================*/

#include<pic18.h>

/*============================ MACRO DEFINITIONS ============================*/

#define rs RD1  
#define en RD0  
#define RW RC2
#define dat_port PORTD


/*============================ GLOBAL VARIABLE ==============================*/
/*   No GLOBAL VARIABLE  */

/*==============================FUNCTION DECLARATIONS ======================*/

Lcd_Init();
Lcd_write(unsigned char,unsigned char);
Lcd_data(unsigned char,unsigned char );
Lcd_Display(unsigned char ,char const *);
Lcd_Decimal(unsigned char ,unsigned int ,unsigned char );
lcd_bk();
delay(unsigned int del);
clear();
void Lcd8_Decimal3c(unsigned char ,unsigned int);
unsigned char Lcd_read(unsigned char x);

#endif

/*========================= END OF FILE Lcd.h ===============================*/


 
