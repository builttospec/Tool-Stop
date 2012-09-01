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

Programming Command:
avrdude -c usbtiny -p m168 -U flash:w:"tool_stop.hex"

 */ 



#include <avr/io.h>

#include "board.h"
#include "settings.h"
#include "stepper.h"
#include "LCD.h"
#include "port_map.h"
#include "keypad.h"



void init(void)
{
	/* Initialize all subsystems */
	board_init();
	settings_init();
	
	stepper_init();
	shift_init();
}

int main(void)
{
	init();
	
	_delay_ms(1000);
	lcd_init();
	
	
	
	
	
	/*	
	// Write 'H'
	set_pin(2,0);  // E low
	set_pin(0,1);  // RS high write
	//SPDR = 0b01001101; // write 'M'
	SPDR = 'H';
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
	*/	
	char startMessage[] = "Saw Stop";
	char message[] = "Key 1 pressed";
	char message2[] = "Tesseract Tools";	
	
	
	
	int pin_number;
	
	
	
	
	lcd_w_string(startMessage);
	
	
	
	while(1)
	{
		
		keypad_init();
		
		/*
		SPDR = 0b11101111; // Row 1
		while(!(SPSR & (1<<SPIF)));
		set_pin(11,0);
		set_pin(11,1);
		
		cValue0 = returnPin(8);
		
		_delay_ms(50);
		
		if(cValue0 == 0)
		{
			lcd_w_string(message);
		}		
		*/
		/*
		if(cValue1 == 1)
		{
			lcd_w_string(message2);
		}			
		*/

		/*
		// to be removed when testing is complete
		
		//Set C0 high
		set_pin(8,1);
		// Read kepad demo, reading from SPDR
		SPDR = 0xFF;
		while(!(SPSR & (1<<SPIF)));
		set_pin(11,0);
		set_pin(11,1);
		spiData =	SPDR;
		
		
		
		if(spiData == 0b10000000)
		{
			lcd_w_string(message);
		}
	
		   
		if(spiData == 0b01000000)
		{
			lcd_w_string(message2);
		}		
		*/
		
		/*
		//Block below used for shift register test. To be removed when the LCD and keypads are programmed
		// Shift in data for the first shift register
		SPDR = 0b01010101;
		// Wait for SPI process to finish
		while(!(SPSR & (1<<SPIF)));
		// Shift in data for the second shift register
		SPDR = 0b01010101;
		// Wait for SPI process to finish
		while(!(SPSR & (1<<SPIF)));	
		// Toggle latch to copy data to storage register
		LATCH_PORT |= LATCH_PIN;
		LATCH_PORT &= ~LATCH_PIN;
		*/
		
		/*
		_delay_ms(500);
		set_debug_led(1);
		_delay_ms(500);
		set_debug_led(0);
		*/
		
    } // End of infinite while
}

	