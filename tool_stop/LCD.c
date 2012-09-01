/*
Proj: Tool Stop - An easy to use tool stop controller
File: LCD.c
Auth: Craig Berscheidt <craig.berscheidt@gmail.com>
Date: 11/27/2011
Desc: Implementation of LCD related functions

Copyright (c) 2011 Craig Berscheidt <craig.berscheidt@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#include <avr/io.h>

#include "board.h"
#include "config.h"
#include "LCD.h"
#include "port_map.h"

void lcd_init(void)
{
	
	set_pin(2,0); // E low
	set_pin(1,0); //R/W low read
	
	// Reset LCD
	set_pin(0,0); //RS low command
	SPDR = 0b00110000;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
	// Reset LCD
	set_pin(0,0);
	SPDR = 0b00110000; 
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));       
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	//_delay_ms(50);
	
	// Reset LCD
	set_pin(0,0);
	SPDR = 0b00110000;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	//_delay_ms(50);
	
	// Set interface
	set_pin(0,0); //RS 0
	set_pin(1,0); //RW 0
	set_pin(2,0); //E 0
	SPDR = 0b00111000;                
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
	
	// Enable Display/Cursor
	set_pin(0,0); //RS 0
	set_pin(1,0); //RW 0
	set_pin(2,0); //E 0
	SPDR = 0b00001000;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
	
	// Clear and Home
	set_pin(0,0); //RS 0
	set_pin(1,0); //RW 0
	set_pin(2,0); //E 0
	SPDR = 0b00000001;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
	// Set cursor move direction
	set_pin(0,0); //RS 0
	set_pin(1,0); //RW 0
	set_pin(2,0); //E 0
	SPDR = 0b00000110;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
	// Turn on display
	set_pin(0,0); //RS 0
	set_pin(1,0); //RW 0
	set_pin(2,0); //E 0
	SPDR = 0b00001100;
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000;
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
}

void lcd_w_cmd(int cmd)
{
	set_pin(2,0);
	set_pin(0,0);
	SPDR = cmd;
	// Wait for SPI process to finish
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000; // push data to second shift register
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	_delay_ms(50);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
	
}

void lcd_w_data(char c)
{
	set_pin(2,0);  // E low
	set_pin(0,1);  // RS high write
	SPDR = c;
	// Wait for SPI process to finish
	while(!(SPSR & (1<<SPIF)));
	SPDR = 0b00000000; // push data to second shift register
	while(!(SPSR & (1<<SPIF)));
	set_pin(11,0);
	set_pin(11,1);
	_delay_ms(50);
	set_pin(2,1); //E toggle
	_delay_ms(5);
	set_pin(2,0); //E toggle
	_delay_ms(5);
}

void lcd_w_string(char *strPointer)
{
	while(*strPointer)
	{
		lcd_w_data(*strPointer);
		strPointer++;
	}	
}

void lcd_clr(void)
{
	
	lcd_w_cmd(0x01);
}

void lcd_set_cur(void)
{
	//cmd 0x80+addr
	lcd_w_cmd(0xC0); //place holder sets to the second row
					 //to be replaced with coordinate set cursor position
	
}