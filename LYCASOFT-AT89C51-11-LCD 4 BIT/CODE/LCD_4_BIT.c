#include<reg51.h>
#include "8051_delay.h"

sbit RS = P1^2;
sbit EN = P1^3;

#define ON 1
#define OFF 0

void Lcd_Command(char cmd)
{
	P1 = (cmd & 0XF0);
	RS = OFF;
	EN = ON;
	delay(5);
	EN = OFF;
	
	P1 = ((cmd<<4) & 0XF0);
	RS = OFF;
	EN = ON;
	delay(5);
	EN = OFF;
}

void Lcd_Data(char Data)
{
	P1 = (Data & 0XF0);
	RS = ON;
	EN = ON;
	delay(5);
	EN = OFF;
	
	P1 = ((Data<<4) & 0XF0);
	RS = ON;
	EN = ON;
	delay(5);
	EN = OFF;
}

void Lcd_String(const unsigned char *Str)
{
	while(*Str != 0)
	{
		Lcd_Data(*Str++);
	}	
}

void Lcd_Intialization()
{
	Lcd_Command(0x02);
	Lcd_Command(0x28);
	Lcd_Command(0x06);
	Lcd_Command(0x0c);
}

void main()
{
	P1=0X00;

	Lcd_Intialization();
	
	while(1)
	{
		Lcd_Command(0x80);
		Lcd_String("LYCO SOFT");
	}
}