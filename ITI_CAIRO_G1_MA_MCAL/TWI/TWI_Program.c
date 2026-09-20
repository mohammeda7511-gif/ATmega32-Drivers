/*
 * TWI_Program.c
 *
 *  Created on: Sep 12, 2026
 *      Author: Mohammed Abdelrahman
 */

/* Include TWI private header for register addresses and macros */
#include "TWI_Private.h"
/* Include TWI configuration header */
#include "TWI_Config.h"
/* Include TWI interface header for function prototypes */
#include "TWI_Interface.h"
/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"

/* Initiation */
/* Function: initialize the TWI peripheral */
void TWI_Init()
{
	/* Set TWBR and TWPS */
/* Prescaler 1 selected */
#if TWI_PRESCALER == TWI_PRESCALER_1
    /* Compute and load TWBR for prescaler 1 */
    TWBR = (u8)(((F_CPU / TWI_SCL_FREQ) - 16) / (2 * 1));
    /* Clear prescaler bit 0 */
    CLR_BIT(TWSR, TWPS0);
    /* Clear prescaler bit 1 */
    CLR_BIT(TWSR, TWPS1);

/* Prescaler 4 selected */
#elif TWI_PRESCALER == TWI_PRESCALER_4
    /* Compute and load TWBR for prescaler 4 */
    TWBR = (u8)(((F_CPU / TWI_SCL_FREQ) - 16) / (2 * 4));
    /* Set prescaler bit 0 */
    SET_BIT(TWSR, TWPS0);
    /* Clear prescaler bit 1 */
    CLR_BIT(TWSR, TWPS1);

/* Prescaler 16 selected */
#elif TWI_PRESCALER == TWI_PRESCALER_16
    /* Compute and load TWBR for prescaler 16 */
    TWBR = (u8)(((F_CPU / TWI_SCL_FREQ) - 16) / (2 * 16));
    /* Clear prescaler bit 0 */
    CLR_BIT(TWSR, TWPS0);
    /* Set prescaler bit 1 */
    SET_BIT(TWSR, TWPS1);

/* Prescaler 64 selected */
#elif TWI_PRESCALER == TWI_PRESCALER_64
    /* Compute and load TWBR for prescaler 64 */
    TWBR = (u8)(((F_CPU / TWI_SCL_FREQ) - 16) / (2 * 64));
    /* Set prescaler bit 0 */
    SET_BIT(TWSR, TWPS0);
    /* Set prescaler bit 1 */
    SET_BIT(TWSR, TWPS1);

#else
    /* Invalid prescaler configuration */
    #error "Wrong initialization for \"TWI_PRESCALER\"."
#endif

    /* Interrupt */
/* TWI interrupt disabled */
#if TWI_INTERRUPT == TWI_INTERRUPT_DISABLE
    /* Clear TWIE bit to disable TWI interrupt */
    CLR_BIT(TWCR, TWIE);

/* TWI interrupt enabled */
#elif TWI_INTERRUPT == TWI_INTERRUPT_DISABLE
    /* Set TWIE bit to enable TWI interrupt */
    SET_BIT(TWCR, TWIE);
    /* Enable global interrupts */
    SET_BIT(SREG, I);

#else
    /* Invalid interrupt configuration */
	#error "Wrong intialization for \"TWI_INTERRUPT\"."
#endif

    /* Address */
    /* Load slave address into TWAR (shifted to leave bit 0 for general call) */
    TWAR = (TWI_ADDRESS << 1);

    /* General Call */
/* General call disabled */
#if TWI_GENERAL_CALL == TWI_GENERAL_CALL_DISABLE
    /* Clear TWGCE bit to disable general call */
    CLR_BIT(TWAR, TWGCE);

/* General call enabled */
#elif TWI_GENERAL_CALL == TWI_GENERAL_CALL_ENABLE
    /* Set TWGCE bit to enable general call */
    SET_BIT(TWAR, TWGCE);

#else
    /* Invalid general call configuration */
	#error "Wrong initialization for \"TWI_GENERAL_CALL\"."
#endif

    /* TWI Enable */
    /* Set TWEN bit to enable the TWI peripheral */
    SET_BIT(TWCR, TWEN);
}


/* Master */
/* Function: send a start condition as master */
u8 TWI_MasterStartSending()
{
	/* Set TWEN, TWSTA and TWINT */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait until the start condition transmission ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Verify status */
	if((TWCR & TWI_STATUS_MASK) == TWI_MAS_START_SUCCESS)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send a repeated start condition as master */
u8 TWI_MasterRepeatStart()
{
	/* Set TWEN, TWSTA and TWINT */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait until the start condition transmission ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Verify status */
	if((TWCR & TWI_STATUS_MASK) == TWI_MAS_REP_START_SUCCESS)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send a stop condition as master */
u8 TWI_MasterStopSending()
{
	/* Set TWEN, TWSTO and TWINT */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

	/* Wait until the hardware resets the stop bit */
	while(GET_BIT(TWCR, TWSTO) == 1);

	/* Return success */
	return TWI_SUCCESS;
}


/* Function: send slave address with write bit as master */
u8 TWI_MasterSendAddressWrite(u8 address)
{
	/* Set the address and write operation */
	TWDR = (address << 1) | TWI_WRITE;

	/* Clear TWINT to start address transmission */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* Wait until the address is sent */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check status */
	if((TWSR & TWI_STATUS_MASK) == TWI_MAS_SEND_ADD_W_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send slave address with read bit as master */
u8 TWI_MasterSendAddressRead(u8 address)
{
	/* Set the address and write operation */
	TWDR = (address << 1) | TWI_WRITE;

	/* Clear TWINT to start address transmission */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* Wait until the address is sent */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check status */
	if((TWSR & TWI_STATUS_MASK) == TWI_MAS_SEND_ADD_R_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send a data byte as master */
u8 TWI_MasterSendData(u8 data)
{
	/* Put the data in the data register */
	TWDR = data;

	/* Clear TWINT to start data transmission */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* Wait until the data is sent */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check status */
	if((TWSR & TWI_STATUS_MASK) == TWI_MAS_SEND_DATA_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: receive a data byte as master and respond with ACK */
u8 TWI_MasterReceiveDataACK(u8 *data)
{
	/* Check that the pointer doesn't point to NULL */
	if(data == NULL)
	{
		/* Return fail */
		return TWI_FAIL;
	}

	/* Set TWINT, TWEN and TWEA */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	/* Wait until receiving ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check state */
	if((TWSR & TWI_STATUS_MASK) == TWI_MAS_READ_DATA_ACK)
	{
		/* Store received byte into the caller's buffer */
		*data = TWDR;
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: receive a data byte as master and respond with NACK */
u8 TWI_MasterReceiveDataNACK(u8 *data)
{
	/* Check that the pointer doesn't point to NULL */
	if(data == NULL)
	{
		/* Return fail */
		return TWI_FAIL;
	}

	/* Set TWINT and TWEN*/
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* Wait until receiving ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check state */
	if((TWSR & TWI_STATUS_MASK) == TWI_MAS_READ_DATA_NACK)
	{
		/* Store received byte into the caller's buffer */
		*data = TWDR;
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Slave */
/* Function: wait to be addressed by master with write bit */
u8 TWI_SlaveReceiveAddressWrite()
{
	/* Set TWEN, TWSTA and TWINT */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait until addressed by master */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Verify status */
	if((TWCR & TWI_STATUS_MASK) == TWI_SLA_ADD_W_MATCH_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: wait to be addressed by master with read bit */
u8 TWI_SlaveReceiveAddressRead()
{
	/* Set TWEN, TWSTA and TWINT */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait until addressed by master */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Verify status */
	if((TWCR & TWI_STATUS_MASK) == TWI_SLA_READ_ADD_MATCH_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send a data byte as slave and receive ACK */
u8 TWI_SlaveSendDataACK(u8 data)
{
	/* Put data in TWDR */
	TWDR = data;

	/* Clear TWINT to start data transmission */
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);

	/* Wait until the data is sent */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check status */
	if((TWSR & TWI_STATUS_MASK) == TWI_SLA_SEND_DATA_ACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: send a data byte as slave and receive NACK */
u8 TWI_SlaveSendDataNACK(u8 data)
{
	/* Put data in TWDR */
	TWDR = data;

	/* Clear TWINT to start data transmission */
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);

	/* Wait until the data is sent */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check status */
	if((TWSR & TWI_STATUS_MASK) == TWI_SLA_SEND_DATA_NACK)
	{
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: receive a data byte as slave and respond with ACK */
u8 TWI_SlaveReceiveDataACK(u8 *data)
{
	/* Check that the pointer doesn't point to NULL */
	if(data == NULL)
	{
		/* Return fail */
		return TWI_FAIL;
	}

	/* Set TWINT, TWEN and TWEA */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	/* Wait until receiving ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check state */
	if((TWSR & TWI_STATUS_MASK) == TWI_SLA_READ_DATA_ACK)
	{
		/* Store received byte into the caller's buffer */
		*data = TWDR;
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}


/* Function: receive a data byte as slave and respond with NACK */
u8 TWI_SlaveReceiveDataNACK(u8 *data)
{
	/* Check that the pointer doesn't point to NULL */
	if(data == NULL)
	{
		/* Return fail */
		return TWI_FAIL;
	}

	/* Set TWINT and TWEN */
	TWCR = (1 << TWINT) | (1 << TWEN);

	/* Wait until receiving ends */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Check state */
	if((TWSR & TWI_STATUS_MASK) == TWI_SLA_READ_DATA_NACK)
	{
		/* Store received byte into the caller's buffer */
		*data = TWDR;
		/* Return success */
		return TWI_SUCCESS;
	}

	/* Return fail */
	return TWI_FAIL;
}
