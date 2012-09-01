/*
 * keypad.c
 *
 * Created: 7/9/2012 9:17:40 PM
 *  Author: Nick W
 */ 

#include <avr/io.h>

#include "keypad.h"
#include "LCD.h"
#include "port_map.h"
#include "board.h"

int cValue0 = 0;
int cValue1 = 0;
int cValue2 = 0;

void keypad_init(void)
{
	
	
	set_pin(8,1);
	set_pin(9,1);
	set_pin(10,1);
	
	// Row 1
	SPDR = 0b11111110; 
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_data('1');
	}
	
	if(cValue1 == 0)
	{
		lcd_w_data('2');
	}
	
	if(cValue2 == 0)
	{
		lcd_w_data('3');
	}
	
	//Row2
	SPDR = 0b11111101; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_data('4');
	}
	
	if(cValue1 == 0)
	{
		lcd_w_data('5');
	}
	
	if(cValue2 == 0)
	{
		lcd_w_data('6');
	}
	
	//row3
	SPDR = 0b11111011; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_data('47');
	}
	
	if(cValue1 == 0)
	{
		lcd_w_data('8');
	}
	
	if(cValue2 == 0)
	{
		lcd_w_data('9');
	}
	
	//row4
	SPDR = 0b11110111; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_data('*');
	}
	
	if(cValue1 == 0)
	{
		lcd_w_data('0');
	}
	
	if(cValue2 == 0)
	{
		lcd_w_data('#');
	}
	
	//2nd keypad
	//row5
	SPDR = 0b11101111; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_data('?');
	}
	
	if(cValue1 == 0)
	{
		lcd_w_string("Up");
	}
	
	if(cValue2 == 0)
	{
		lcd_w_string("Set Home");
	}
	
	//row6
	SPDR = 0b11011101; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_string("Left");
	}
	
	if(cValue1 == 0)
	{
		lcd_w_string("Enter");
	}
	
	if(cValue2 == 0)
	{
		lcd_w_string("Right");
	}
	//row7
	SPDR = 0b10111111; // Row 1
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	
	cValue0 = returnPin(8);
	cValue1 = returnPin(9);
	cValue2 = returnPin(10);
	
	
	if(cValue0 == 0)
	{
		lcd_w_string("Stop");
	}
	
	if(cValue1 == 0)
	{
		lcd_w_string("Down");
	}
	
	if(cValue2 == 0)
	{
		lcd_w_string("Go");
	}
} // End keypad_init

