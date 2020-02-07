/****************************************************************************
* File Name   : Lcd.c
* Author      : Karthick R
* Version     : 0.1
* Date        : 31-Dec-2019
* Description : This file contains various LCD display functions definition
****************************************************************************/

/*=============================== INCLUSIONS ================================*/

#include"Lcd.h"

/*============================ GLOBAL VARIABLE ==============================*/

/*   No GLOBAL VARIABLE  */


/*=============================== FUNCTION DEFINITIONS ======================*/
/************************************************************************************
*Function Name 	: Lcd_Init
*Description	: Function to Initialize the LCD Display
*Parameters	: None
*Return Type	: None
*************************************************************************************/
Lcd_Init()
{
	/*Send LCD command to Return home*/
	Lcd_data(0x02,0);

	/*Send LCD command to Set LCD Display as 2 lines and 5*7 
	matrix (4-bit mode)*/
	Lcd_data(0x28,0);
	
	/*Send LCD command to Set Display on, cursor off*/
	Lcd_data(0x0c,0);

	/*Send LCD command to Increment cursor (shift cursor to right)*/
	Lcd_data(0x06,0);

	/*Send LCD command to Clear display screen*/
	Lcd_data(0x01,0);
}/* End of function void Lcd_Init()
*************************************************************************************/

/************************************************************************************
*Function Name 	: Lcd_data
*Description	: Function to Send 4bit data or command to the LCD Display
*Parameters	: unsigned char x : Parameter Argument to pass data or command 
		  unsigned char y : Parameter Argument to select data mode or command mode
*Return Type	: None
*************************************************************************************/
Lcd_data(unsigned char x,unsigned char y)
{
	RC2=0;
	/*Local variable to convert the given 8bit data into 4bit*/
	unsigned char a,b,t;

	/*Get the upper nipple of 8bit data*/
	a=  x & 0xf0;

	/*Get the lower nipple of 8bit data*/
	b= (x<<4) & 0xf0;
	
	/*get the current value of MCU port pin(pin 0 to 4) */
	t=dat_port & 0x0f;
	
	/*Send the upper nipple data with current value of MCU port pin(pin 0 to 4) 
	to MCU display pins */
	dat_port=a|t;
	
	/*assign the mode to register select pin of LCD*/
	rs=y;

	/*Set Enable pin of LCD to high*/
	en=1;

	/*call delay to generate a pulse to Enable pin of LCD*/
	delay(200);

	/*Set Enable pin of LCD to low*/
	en=0;

	/*get the current value of MCU port pin(pin 0 to 4)*/
	t=dat_port & 0x0f;

	/*Send the lower nipple data with current value of MCU port pin(pin 0 to 4) 
	to MCU display pins */
	dat_port=b|t;

	/*assign the mode to register select pin of LCD*/
	rs=y;

	/*Set Enable pin of LCD to high*/
	en=1;

	/*call delay to generate a pulse to Enable pin of LCD*/
	delay(200);

	/*Set Enable pin of LCD to low*/
	en=0;	
}/* End of function void Lcd_data(unsigned char x,unsigned char y)
*************************************************************************************/

/************************************************************************************
*Function Name 	: Lcd_Read
*Description	: Function to read a single character from the LCD display which already
		  present in a particular position.
*Parameters	: unsigned char  x: parameter argument to select a particular LCD 
		  		       display position
*Return Type	: unsigned char : return a character data read from the particular 
			        Position in the LCD Display
*************************************************************************************/
unsigned char Lcd_read(unsigned char x)
{
	/*pass the position of LCD display to read a particular character on LCD*/
	Lcd_data(x,0);

	/*Varibles to get the lower and upper 4 bit of particular character diplayed
	on the LCD display*/
	unsigned char a,b,t;
	
	/*In Write mode LCD data pins are set a output,So in Read mode the direction
	of data pins are changed to input*/
	TRISD=0xF0;
	
	/*Select Lcd data mode to get the character present in particular position*/
	rs=1;

	/*In Write mode LCD Read/Write pin are set as Low,So in Read mode 
	the LCD Read/Write pin should changed to high*/
	RW=1;

	/*Generate a pulse on the Enable pin to get the data of LCD Display
 	To generate a pulse Enable pin should High,a small delay and low*/
	/*Note : Data will receive while the Enable pin in high*/
	en=0;
	en=1;
	delay(125);

	/*Get the upper 4bit data in a local variable*/
	t=dat_port & 0xf0;
	delay(125);
	en=0;

	/*Get the upper 4bit data*/
	a=t;

	/*Generate a small delay*/
	delay(500);
	
	/*Low the Lcd Enable pin and Generate a small delay*/
	RW=en=0;

	/*Select Lcd data mode to get the character present in particular position*/
	rs=1;

	/*In Write mode LCD Read/Write pin are set as Low,So in Read mode 
	the LCD Read/Write pin should changed to high*/
	RW=1;

	/*Generate a pulse on the Enable pin to get the data of LCD Display
 	To generate a pulse Enable pin should High,a small delay and low*/
	/*Note : Data will receive while the Enable pin in high*/
	en=0;
	en=1;
	delay(125);

	/*Get the upper 4bit data in a local variable*/
	t=dat_port & 0xf0;

	/*Generate a pulse on the Enable pin to get the data of LCD Display
	To generate a pulse Enable pin should High,a small delay and low*/
	/*Note : Data will receive while the Enable pin in high*/
	delay(125);en=0;

	/*Get the lower 4bit data in a local variable*/
	/*Concodinate the upper and lower 4 bit data into a single character data*/
	b=(t>>4)|a;

	/*Generate a small delay*/
	delay(500);

	/*change the LCD Read/Write pin to Write mode*/
	RW=en=0;

	/*change the LCD Read/Write pin to Write mode*/
	TRISD=0x00;

	/*Send LCD command to Return home*/
	Lcd_data(0x02,0);

	/*Send LCD command to Set LCD Display as 2 lines and 5*7 
	matrix (4-bit mode)*/	
	Lcd_data(0x28,0);

	/*Send LCD command to Set Display on, cursor off*/	
	Lcd_data(0x0c,0);
	/*Send LCD command to Clear display screen*/
	Lcd_data(0x06,0);
	
	/*change the LCD Read/Write pin to Write mode*/
	return b;
}/* End of function unsigned char Lcd_Read(unsigned char x)
*************************************************************************************/

/************************************************************************************
*Function Name 	: Lcd_Write
*Description	: Function to Write a data in the LCD Display  
*Parameters	: unsigned char x : parameter argument to select a particular LCD 
			         	       display position
		  unsigned char y : parameter argument to pass data to display
*Return Type	: None
*************************************************************************************/
Lcd_Write(unsigned char x,unsigned char y)
{
	/*Select the Lcd position which the character need to display*/
	Lcd_data(x,0);

	/*Send the particular character to display on the LCD display*/
	Lcd_data(y,1);

}/* End of function void Lcd_Write(unsigned char x,unsigned char y)
*************************************************************************************/

/************************************************************************************
*Function Name 	: Lcd_Display
*Description	: Function to write a string data in the LCD Display
*Parameters	: unsigned char x : parameter argument to select a particular LCD 
				       display position
		  char const *y : parameter argument pointer of string data					   
*Return Type	: None
*************************************************************************************/
Lcd_Display(unsigned char x,char const *y)
{

	/*Send the particular string(as pointer) and  starting LCD position of 
	string to Display*/
	Lcd_data(x,0); 

	/*Display the string as one by one character in Lcd display*/
	while(*y!='\0')Lcd_data(*y++,1); 

}/* End of function void Lcd_Display(unsigned char x,char const *y)
*************************************************************************************/


/************************************************************************************
*Function Name 	: Lcd_Decimal
*Description	: Function to display the given integer as desired decimal point
*Parameters	: unsigned char x : parameter argument to select a particular LCD 
				       display position
		  unsigned char y : parameter argument to pass data to display 
		  unsigned char n : parameter argument to select desired
				            no.of decimal point 
*Return Type	: None
*************************************************************************************/

Lcd_Decimal(unsigned char x,unsigned int y,unsigned char n)
{
	/*Send lcd starting position */
	Lcd_data(x,0);
	unsigned int m=1;
	
	/*convert the given data with desired no.of decimals*/
	while(n--)m=m*10;

	/*loop to display the data */
	while(m>1)
	{
		Lcd_data((y%m)/(m/10)+0x30 , 1);
		m=m/10;
	}

}/* End of function void Lcd_Decimal(unsigned char position,unsigned int data,unsigned char no_of_decimal)
*************************************************************************************/





void Lcd8_Decimal3c(unsigned char com,unsigned int val)
{
	unsigned int Lcd_h,Lcd_hr,Lcd_t,Lcd_o;

	Lcd_h=val/100;
	Lcd_hr=val%100;
	Lcd_t=Lcd_hr/10;
	Lcd_o=Lcd_hr%10;
	//Lcd_data(com,0);
	Lcd_Write(com,Lcd_h+0x30);
  Lcd_Write(com+1,Lcd_t+0x30);
	Lcd_Write(com+2,'.');
  Lcd_Write(com+3,Lcd_o+0x30);
}

/************************************************************************************
*Function Name 	: Lcd_Clear
*Description	: Function to Clear the all previously displayed character in LCD display
*Parameters	: None
*Return Type	: None
*************************************************************************************/
clear()
{
	/*Send LCD command to clear the LCD display*/
	Lcd_data(0x01,0);
}/* End of function void Lcd_Clear()
*************************************************************************************/



/************************************************************************************
*Function Name 	: Delay
*Description	: Function to generate a delay(Note : Delay time may vary according to 
		  the MCU Oscillator Frequency) 
*Parameters	: unsigned int del : parameter argument to pass a particular delay time
*Return Type	: None
*************************************************************************************/
delay(unsigned int del)
{
	/* create a delay until del become zero according to the MCU Oscillator Frequency */
  	while(del--);
}/* End of function void Delay(unsigned int del)
*************************************************************************************/

/*========================= END OF FILE Lcd.c ===============================*/
