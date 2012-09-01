/*
 * port_map.c
 *
 * Created: 7/4/2012 12:03:48 PM
 *  Author: Nick W
 */ 

#include <avr/io.h>



// Function Defs
void set_pin(int pin_number, int state)
{
	int port = pin_number >> 3;
	int pin = pin_number & 0x07;

	switch (port)
	{
		case 0:
		if (state == 0)
		PORTB &= ~(1 << pin);
		else
		PORTB |= (1 << pin);
		break;

		case 1:
		if (state == 0)
		PORTC &= ~(1 << pin);
		else
		PORTC |= (1 << pin);
		break;

		case 2:
		if (state == 0)
		PORTD &= ~(1 << pin);
		else
		PORTD |= (1 << pin);
		break;
		default:
		break;
	}
}