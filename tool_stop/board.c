/*
Proj: Tool Stop - An easy to use tool stop controller
File: board.c
Auth: Craig Berscheidt <craig.berscheidt@gmail.com>
Date: 11/27/2011
Desc: All board specific function implementations go here

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

#include "board.h"
#include <avr/io.h>

#include "LCD.h"
#include "port_map.h"



void board_init(void)
{
	DDRB = DDRB_INIT;
	DDRC = DDRC_INIT;
	DDRD = DDRD_INIT;

	PORTB = PORTB_INIT;
	PORTC = PORTC_INIT;
	PORTD = PORTD_INIT;
}

void set_debug_led(int value)
{
	if (value == 0)
		STATUS_LED_PORT &= ~(1 << STATUS_LED_PIN);
    else
		STATUS_LED_PORT |= (1 << STATUS_LED_PIN);
}

void shift_init(void)
{
	// Set control pins as outputs
	//LATCH_DDR |= (DATA | LATCH_PIN | CLOCK);
	// Set control pins low
	//LATCH_PORT &= ~(DATA | LATCH_PIN | CLOCK);
	// Set up SPI
	SPCR = (1<<SPE) | (1<<MSTR | 0<<DORD);
	// Pulls latch low, part of starting SPI transfer
	//LATCH_PORT  &= ~LATCH_PIN;
  	
}	

int returnPin(int pin_number)
{
	int port = pin_number >> 3;
	int pin = pin_number & 0x07;
	
	switch (port)
	{
		case 0:
		
		if (PINB & _BV(pin))
		return 1;
		else
		return 0;
		break;

		case 1:
		
		if (PINC & _BV(pin))
		return 1;
		else
		return 0;
		break;

		case 2:
		
		if (PIND & _BV(pin))
		return 1;
		else
		return 0;
		break;
		
		default:
		break;
	}
	
	
}
