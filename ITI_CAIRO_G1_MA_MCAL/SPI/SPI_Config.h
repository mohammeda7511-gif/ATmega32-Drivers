/*
 * SPI_Config.h
 *
 *  Created on: Sep 7, 2026
 *      Author: Mohammed Abdelrahman
 */

#ifndef ITI_CAIRO_G1_MA_MCAL_SPI_SPI_CONFIG_H_
#define ITI_CAIRO_G1_MA_MCAL_SPI_SPI_CONFIG_H_


/*
 * SPI mode options:
 * 1-
 * 2-
 * */
#define SPI_MODE					SPI_MASTER

/*
 * SPI clock options:
 * 1-
 * 2-
 * 3-
 * 4-
 * 5-
 * 6-
 * 7-
 * */
#define SPI_CLOCK					SPI_CLOCK_F_8

/*
 * SPI clock phase options
 * 1-
 * 2-
 * */
#define SPI_CLOCK_PHASE				SPI_SAMPLE_FIRST

/*
 * SPI clock parity options
 * 1-
 * 2-
 * */
#define SPI_CLOCK_PARITY			SPI_IDLE_LOW

/*
 * SPI interrupt options
 * 1-
 * 2-
 * */
#define SPI_INTERRUPT_STATUS		SPI_INTERRUPT_ENABLE

/*
 * SPI data order options
 * 1-
 * 2-
 * */
#define SPI_DATA_ORDER				SPI_LSB_BIT_FIRST


#endif /* ITI_CAIRO_G1_MA_MCAL_SPI_SPI_CONFIG_H_ */
