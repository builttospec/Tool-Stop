/*
Proj: Tool Stop - An easy to use tool stop controller
File: board.h
Auth: Craig Berscheidt <craig.berscheidt@gmail.com>
Date: 11/27/2011
Desc: All board specific definitions go in this header file

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


#ifndef BOARD_H_
#define BOARD_H_

#define F_CPU 1000000UL
/* Included after the above define */
#include <util/delay.h>

/* MOSI data */
#define DATA PB3

#define READ PB4

/* Clock SCK */
#define CLOCK PB5

/* Keypad related definitions */
#define KEYPAD_DDR	DDRC
#define KEYPAD_PORT	PORTC
#define C0_PIN		0
#define C1_PIN		1
#define C2_PIN		2
#define KEYPAD_DEBOUNCE_PERIOD	50



/* Shift register definitions */
#define LATCH_DDR	DDRC
#define LATCH_PORT	PORTC
#define LATCH_PIN	4

// LCD definitions 
#define LCD_DDR		DDRB
#define LCD_PORT	PORTB
#define LCD_RS_PIN	0
#define LCD_RW_PIN	1
#define LCD_E_PIN	2


/* Stepper control definitions */
#define STEPPER_DDR			DDRD
#define STEPPER_PORT		PORTD
#define STEPPER_STEP_PIN	0
#define STEPPER_DIR_PIN		1

/* External trigger definitions */
#define TRIGGER_DDR			DDRD
#define TRIGGER_PORT		PORTD
#define TRIGGER_LIMIT_M_PIN	5
#define TRIGGER_LIMIT_P_PIN	6
#define TRIGGER_ESTOP_PIN	7

/* Status LED definitions */
#define STATUS_LED_DDR	DDRD
#define STATUS_LED_PORT	PORTD
#define STATUS_LED_PIN	4

/* Default config definitions */
#define DDRB_INIT	0x3F
#define DDRC_INIT	0x08
#define DDRD_INIT	0x13

#define PORTB_INIT	0x00
#define PORTC_INIT	0x07
#define PORTD_INIT	0x00


/* Board specific function definitions */
void board_init(void);

void set_debug_led(int value);

void shift_init(void);

int returnPin(int pin_number);



#endif /* BOARD_H_ */