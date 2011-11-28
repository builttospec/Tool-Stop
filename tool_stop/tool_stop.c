/*
Proj: Tool Stop - An easy to use tool stop controller
File: tool_stop.c
Auth: Craig Berscheidt <craig.berscheidt@gmail.com>
Date: 11/27/2011
Desc: This is where initialization and the main loop reside

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
#include "LCD.h"
#include "settings.h"
#include "stepper.h"

void init(void)
{
	/* Initialize all subsystems */
	board_init();
	settings_init();
	lcd_init();
	stepper_init();
}

int main(void)
{
	init();
	
    while(1)
    {
    }
}