
#include"Lcd.h"
#include"VARIABLE.H"
#include"eprom.h"
int a;
void main()
{

	PORTA=PORTB=PORTC=PORTD=0X00;
	TRISA=TRISB=TRISC=TRISD=0X00;
	Lcd_Init();
	Lcd_Display(0x80,"STYROTECH");
	
    read();
	a=eprom_read(0);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(2);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(4);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(6);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);
	a=eprom_read(8);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(10);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(12);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(14);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(0);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(16);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(18);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(24);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(26);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(28);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(30);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	a=eprom_read(36);
	Lcd_Decimal(0xc0,a,3);
	delay(65000);
	delay(65000);	
	
				
	while(1);

	
	
}