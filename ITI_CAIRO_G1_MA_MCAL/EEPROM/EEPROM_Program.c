/*
 * EEPROM_Program.c
 *
 *  Created on: Sep 9, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Include EEPROM interface header for function prototypes */
#include "EEPROM_Interface.h"
/* Include EEPROM private header for register addresses and macros */
#include "EEPROM_Private.h"
/* Include EEPROM configuration header for interrupt options */
#include "EEPROM_Config.h"
/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
/* Include GIE interface header for global interrupt control */
#include "../GIE/GIE_Interface.h"


/* Function: write a single byte to EEPROM at the given address */
void EEPROM_write(u16 uiAddress, u8 ucData)
{
	/* Disable global interrupts during the write sequence */
	GIE_Disable();
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1 << EEMWE);
	/* Start the EEPROM write by setting EEWE */
	EECR |= (1 << EEWE);

	/* Re-enable global interrupts */
	GIE_Enable();
}


/* Function: read a single byte from EEPROM at the given address */
u8 EEPROM_read(u16 uiAddress)
{
	/* Disable global interrupts during the read sequence */
	GIE_Disable();
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);

	/* Re-enable global interrupts */
	GIE_Enable();

	/* Return data from data register */
	return EEDR;
}


/* Function: write a null-terminated string into EEPROM starting at the given address */
void EEPROM_WriteString(u8 address, u8 *data)
{
	/* Disable global interrupts during the write sequence */
	GIE_Disable();

	/* Iterator for indexing through the source string */
	u8 iterator = 0;

    /* Check for null pointer before dereferencing */
    if (data == NULL)
        /* Abort if the source pointer is invalid */
        return;

    /* Loop through each character until the null terminator is found */
    while (data[iterator] != '\0')
    {
        /* Write the current character to its EEPROM location */
        EEPROM_write(address + iterator, data[iterator]);
        /* Advance to the next character */
        iterator++;
    }

    /* Write the null terminator to mark end of string in EEPROM */
    EEPROM_write(address + iterator, '\0');

    /* Re-enable global interrupts */
    GIE_Enable();
}


/* Function: read a null-terminated string from EEPROM into a buffer */
void EEPROM_ReadString(u8 address, u8 *ptr)
{
	/* Disable global interrupts during the read sequence */
	GIE_Disable();
	/* Iterator for indexing into the destination buffer */
	u8 iterator = 0;
    /* Temporary storage for the byte read from EEPROM */
    u8 data;

    /* Check for null pointer before dereferencing */
    if (ptr == NULL)
        /* Abort if the destination pointer is invalid */
        return;

    /* Read at least one byte, then continue until terminator or bound */
    do
    {
        /* Safety bound: never read more than 100 bytes */
        if (iterator >= 100)
        {
            /* Force null termination at the safety bound */
            ptr[iterator] = '\0';
            /* Stop reading */
            break;
        }

        /* Wait for any previous write operation to finish */
        while (EECR & (1 << EEWE));

        /* Set the address to read from */
        EEARH = 0x00;
        /* Set the low byte of the address (base + offset) */
        EEARL = address + iterator;

        /* Start the read operation */
        EECR |= (1 << EERE);

        /* Read the data */
        data = EEDR;

        /* Store it in the destination buffer */
        ptr[iterator] = data;

        /* Advance to the next buffer position */
        iterator++;

        /* If a null terminator was read, we are done */
        if(data == '\0')
        {
        	/* Return early since terminator was already copied */
        	return;
        }

    } while (data != '\0');   /* Stop AFTER copying the NULL terminator */

    /* Re-enable global interrupts */
    GIE_Enable();
}


/* Function: write a numeric byte value to EEPROM at the given address */
void EEPROM_WriteNumber(u8 address, u8 data)
{
	/* Disable global interrupts during the write sequence */
	GIE_Disable();
	/* Wait for any previous write operation to finish */
    while (GET_BIT(EECR, EEWE) == 1);

    /* Set address and data registers */
    EEARL = address;
    /* High address byte is always zero (8-bit addressing) */
    EEARH = 0;
    /* Load the data byte to be written */
    EEDR  = data;

    /* Set EEMWE and EEWE in one write to satisfy the 4-cycle timing */
    EECR |= (1 << EEMWE);
    /* Start the actual write */
    EECR |= (1 << EEWE);

    /* Wait for the write to finish before returning */
    while (GET_BIT(EECR, EEWE) == 1);

    /* Re-enable global interrupts */
    GIE_Enable();
}


/* Function: read a numeric byte value from EEPROM at the given address */
u8 EEPROM_ReadNumber(u8 address)
{
	/* Disable global interrupts during the read sequence */
	GIE_Disable();
	/* Wait for any previous write operation to finish */
    while (GET_BIT(EECR, EEWE) == 1);

    /* Set the address to read from */
    EEARL = address;
    /* High address byte is always zero (8-bit addressing) */
    EEARH = 0;

    /* Start the read operation */
    SET_BIT(EECR, EERE);

    /* Re-enable global interrupts */
    GIE_Enable();

    /* Return the byte read from the data register */
    return EEDR;
}
