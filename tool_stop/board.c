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