/*
 * DIO_Program.c
 *
 *  Created on: Aug 25, 2026
 *      Author: Mohammed Abdelrahman
 */
/* Include DIO interface header for function prototypes */
#include "DIO_Interface.h"
/* Include DIO private header for register addresses and macros */
#include "DIO_Private.h"
/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"


/* Function: set direction of a single pin on a given port */
void DIO_SetPinDirection(u8 u8_port, u8 pin, u8 direction)
{
	/* Switch on the requested direction mode */
	switch (direction)
	{
	/* Case: configure pin as input */
	case DIO_INPUT:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Clear the DDR bit to make the pin an input */
			CLR_BIT(DDRA, pin);
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Clear the DDR bit to make the pin an input */
			CLR_BIT(DDRB, pin);
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Clear the DDR bit to make the pin an input */
			CLR_BIT(DDRC, pin);
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Clear the DDR bit to make the pin an input */
			CLR_BIT(DDRD, pin);
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;

	/* Case: configure pin as output */
	case DIO_OUTPUT:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Set the DDR bit to make the pin an output */
			SET_BIT(DDRA, pin);
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Set the DDR bit to make the pin an output */
			SET_BIT(DDRB, pin);
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Set the DDR bit to make the pin an output */
			SET_BIT(DDRC, pin);
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Set the DDR bit to make the pin an output */
			SET_BIT(DDRD, pin);
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;

	/* Case: configure pin as input with internal pull-up */
	case DIO_PULLUP:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Clear DDR bit to make the pin an input */
			CLR_BIT(DDRA, pin);
			/* Set PORT bit to enable the internal pull-up resistor */
			SET_BIT(PORTA, pin);
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Clear DDR bit to make the pin an input */
			CLR_BIT(DDRB, pin);
			/* Set PORT bit to enable the internal pull-up resistor */
			SET_BIT(PORTB, pin);
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Clear DDR bit to make the pin an input */
			CLR_BIT(DDRC, pin);
			/* Set PORT bit to enable the internal pull-up resistor */
			SET_BIT(PORTC, pin);
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Clear DDR bit to make the pin an input */
			CLR_BIT(DDRD, pin);
			/* Set PORT bit to enable the internal pull-up resistor */
			SET_BIT(PORTD, pin);
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;

		/* Default: invalid direction */
		default:
			/* Do nothing */
			break;
	}
}

/* Function: set direction of an entire port */
void DIO_SetPortDirection(u8 u8_port,u8 direction)
{
	/* Switch on the requested direction mode */
	switch (direction)
	{
	/* Case: configure whole port as input */
	case DIO_INPUT:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Write 0x00 to DDRA (all pins input) */
			DDRA = DIO_INPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Write 0x00 to DDRB (all pins input) */
			DDRB = DIO_INPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Write 0x00 to DDRC (all pins input) */
			DDRC = DIO_INPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Write 0x00 to DDRD (all pins input) */
			DDRD = DIO_INPUT_PORT;
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;

	/* Case: configure whole port as output */
	case DIO_OUTPUT:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Write 0xFF to DDRA (all pins output) */
			DDRA = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Write 0xFF to DDRB (all pins output) */
			DDRB = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Write 0xFF to DDRC (all pins output) */
			DDRC = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Write 0xFF to DDRD (all pins output) */
			DDRD = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;

	/* Case: configure whole port as input with pull-up */
	case DIO_PULLUP:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Clear DDR bits to make pins inputs */
			DDRA = DIO_INPUT_PORT;
			/* Set PORT bits to enable pull-ups on all pins */
			PORTA = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Clear DDR bits to make pins inputs */
			DDRB = DIO_INPUT_PORT;
			/* Set PORT bits to enable pull-ups on all pins */
			PORTB = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Clear DDR bits to make pins inputs */
			DDRC = DIO_INPUT_PORT;
			/* Set PORT bits to enable pull-ups on all pins */
			PORTC = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Clear DDR bits to make pins inputs */
			DDRD = DIO_INPUT_PORT;
			/* Set PORT bits to enable pull-ups on all pins */
			PORTD = DIO_OUTPUT_PORT;
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit direction switch */
		break;
	/* Default: invalid direction */
	default:
		/* Do nothing */
		break;
	}
}

/* Function: read the 8-bit value of all pins on a port */
u8 DIO_GetPortValue(u8 u8_port)
{
	/* Switch on the target port */
	switch (u8_port)
	{
	/* Case: Port A selected */
	case DIO_PORTA:
		/* Return the value of PINA register */
		return PINA;
		/* Unreachable break (after return) */
		break;
	/* Case: Port B selected */
	case DIO_PORTB:
		/* Return the value of PINB register */
		return PINB;
		/* Unreachable break (after return) */
		break;
	/* Case: Port C selected */
	case DIO_PORTC:
		/* Return the value of PINC register */
		return PINC;
		/* Unreachable break (after return) */
		break;
	/* Case: Port D selected */
	case DIO_PORTD:
		/* Return the value of PIND register */
		return PIND;
		/* Unreachable break (after return) */
		break;
	/* Default: invalid port */
	default:
		/* Return 0 as a safe default */
		return 0;
		/* Unreachable break (after return) */
		break;
	}
}

/* Function: read the logic level of a single pin */
u8 DIO_GetPinValue(u8 u8_port,u8 pin)
{
	/* Switch on the target port */
	switch (u8_port)
	{
	/* Case: Port A selected */
	case DIO_PORTA:
		/* Return the requested bit from PINA */
		return GET_BIT(PINA, pin);
		/* Unreachable break (after return) */
		break;
	/* Case: Port B selected */
	case DIO_PORTB:
		/* Return the requested bit from PINB */
		return GET_BIT(PINB, pin);
		/* Unreachable break (after return) */
		break;
	/* Case: Port C selected */
	case DIO_PORTC:
		/* Return the requested bit from PINC */
		return GET_BIT(PINC, pin);
		/* Unreachable break (after return) */
		break;
	/* Case: Port D selected */
	case DIO_PORTD:
		/* Return the requested bit from PIND */
		return GET_BIT(PIND, pin);
		/* Unreachable break (after return) */
		break;
	/* Default: invalid port */
	default:
		/* Return 0 as a safe default */
		return 0;
		/* Unreachable break (after return) */
		break;
	}
}

/* Function: write an 8-bit value to all pins of a port */
void DIO_SetPortValue(u8 u8_port,u8 value)
{
	/* Switch on the target port */
	switch (u8_port)
	{
	/* Case: Port A selected */
	case DIO_PORTA:
		/* Write value to PORTA register */
		PORTA = value;
		/* Exit port switch */
		break;
	/* Case: Port B selected */
	case DIO_PORTB:
		/* Write value to PORTB register */
		PORTB = value;
		/* Exit port switch */
		break;
	/* Case: Port C selected */
	case DIO_PORTC:
		/* Write value to PORTC register */
		PORTC = value;
		/* Exit port switch */
		break;
	/* Case: Port D selected */
	case DIO_PORTD:
		/* Write value to PORTD register */
		PORTD = value;
		/* Exit port switch */
		break;
	/* Default: invalid port */
	default:
		/* Do nothing */
		break;
	}
}

/* Function: write a logic level to a single pin */
void DIO_SetPinValue(u8 u8_port,u8 pin,u8 value)
{
	/* Switch on the desired value */
	switch (value)
	{
	/* Case: set pin high */
	case DIO_HIGH:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Set the pin's bit in PORTA */
			SET_BIT(PORTA, pin);
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Set the pin's bit in PORTB */
			SET_BIT(PORTB, pin);
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Set the pin's bit in PORTC */
			SET_BIT(PORTC, pin);
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Set the pin's bit in PORTD */
			SET_BIT(PORTD, pin);
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit value switch */
		break;
	/* Case: set pin low */
	case DIO_LOW:
		/* Switch on the target port */
		switch (u8_port)
		{
		/* Case: Port A selected */
		case DIO_PORTA:
			/* Clear the pin's bit in PORTA */
			CLR_BIT(PORTA, pin);
			/* Exit port switch */
			break;
		/* Case: Port B selected */
		case DIO_PORTB:
			/* Clear the pin's bit in PORTB */
			CLR_BIT(PORTB, pin);
			/* Exit port switch */
			break;
		/* Case: Port C selected */
		case DIO_PORTC:
			/* Clear the pin's bit in PORTC */
			CLR_BIT(PORTC, pin);
			/* Exit port switch */
			break;
		/* Case: Port D selected */
		case DIO_PORTD:
			/* Clear the pin's bit in PORTD */
			CLR_BIT(PORTD, pin);
			/* Exit port switch */
			break;
		/* Default: invalid port */
		default:
			/* Do nothing */
			break;
		}
		/* Exit value switch */
		break;
	/* Default: invalid value */
	default:
		/* Do nothing */
		break;
	}
}

/* Function: toggle the logic level of a single pin */
void DIO_TogglePinValue(u8 port,u8 pin)
{
	/* Switch on the target port */
	switch (port)
	{
	/* Case: Port A selected */
	case DIO_PORTA:
		/* Toggle the pin's bit in PORTA */
		TOG_BIT(PORTA, pin);
		/* Exit port switch */
		break;
	/* Case: Port B selected */
	case DIO_PORTB:
		/* Toggle the pin's bit in PORTB */
		TOG_BIT(PORTB, pin);
		/* Exit port switch */
		break;
	/* Case: Port C selected */
	case DIO_PORTC:
		/* Toggle the pin's bit in PORTC */
		TOG_BIT(PORTC, pin);
		/* Exit port switch */
		break;
	/* Case: Port D selected */
	case DIO_PORTD:
		/* Toggle the pin's bit in PORTD */
		TOG_BIT(PORTD, pin);
		/* Exit port switch */
		break;
	/* Default: invalid port */
	default:
		/* Do nothing */
		break;
	}
}


/* Function: toggle the logic level of all pins on a port */
void DIO_TogglePortValue(u8 port)
{
	/* Switch on the target port */
	switch (port)
	{
	/* Case: Port A selected */
	case DIO_PORTA:
		/* XOR PORTA with 0xFF to invert all bits */
		PORTA ^= 0xFF;
		/* Exit port switch */
		break;
	/* Case: Port B selected */
	case DIO_PORTB:
		/* XOR PORTB with 0xFF to invert all bits */
		PORTB ^= 0xFF;
		/* Exit port switch */
		break;
	/* Case: Port C selected */
	case DIO_PORTC:
		/* XOR PORTC with 0xFF to invert all bits */
		PORTC ^= 0xFF;
		/* Exit port switch */
		break;
	/* Case: Port D selected */
	case DIO_PORTD:
		/* XOR PORTD with 0xFF to invert all bits */
		PORTD ^= 0xFF;
		/* Exit port switch */
		break;
	/* Default: invalid port */
	default:
		/* Do nothing */
		break;
	}
}
