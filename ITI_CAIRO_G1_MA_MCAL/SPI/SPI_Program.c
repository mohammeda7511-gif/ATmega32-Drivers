/*
 * SPI_Program.c
 *
 *  Created on: Sep 7, 2026
 *      Author: Mohammed Abdelrahman
 */

#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

void SPI_Init()
{
#if SPI_MODE == SPI_MASTER
	SET_BIT(SPCR, MSTR);

	SET_BIT(DDRB, MOSI_PIN);
	SET_BIT(DDRB, SCK_PIN);
	SET_BIT(DDRB, SS_PIN);
	CLR_BIT(DDRB, MISO_PIN);


#if SPI_CLOC >= SPI_CLOCK_F_4 && SPI_CLOC <= SPI_CLOCK_F_32
#if SPI_CLOCK > SPI_CLOCK_F_128
	SET_BIT(SPSR, SPI2X);
#else
	CLR_BIT(SPSR, SPI2X);
#endif

	SPCR &= SPI_CLOCK_MSK;

	SPCR |= (SPI_CLOCK & SPI_CLOCK_CHOICE_MSK);

#else
#error "Wrong initialization for \"SPI_CLOCK\"."
#endif

#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR, MSTR);

	CLR_BIT(DDRB, MOSI_PIN);
	CLR_BIT(DDRB, SCK_PIN);
	CLR_BIT(DDRB, SS_PIN);
	SET_BIT(DDRB, MISO_PIN);
#else
#error "Wrong initialization for \"SPI_MODE\"."
#endif

#if SPI_CLOCK_PHASE == SPI_SAMPLE_FIRST
	CLR_BIT(SPCR, CPHA);
#elif SPI_CLOCK_PHASE == SPI_SETUP_FIRST
	SET_BIT_BIT(SPCR, CPHA);
#else
#error "Wrong initialization for \"SPI_CLOCK_PHASE\"."
#endif

#if SPI_CLOCK_PARITY == SPI_IDLE_LOW
	CLR_BIT(SPCR, CPHA);
#elif SPI_CLOCK_PHASE == SPI_IDLE_HIGH
	SET_BIT_BIT(SPCR, CPHA);
#else
#error "Wrong initialization for \"SPI_CLOCK_PHASE\"."
#endif

#if SPI_DATA_ORDER == SPI_IDLE_LOW
	CLR_BIT(SPCR, CPHA);
#elif SPI_CLOCK_PHASE == SPI_IDLE_HIGH
	SET_BIT_BIT(SPCR, CPHA);
#else
//#error "Wrong initialization for \"SPI_CLOCK_PHASE\"."
#endif





}
