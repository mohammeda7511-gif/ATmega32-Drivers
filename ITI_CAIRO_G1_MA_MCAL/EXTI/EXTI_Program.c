/*
 * EXTI_Program.c
 *
 *  Created on: Aug 31, 2026
 *      Author: Mohammed Abdelrahman
 */


/* Include bit manipulation macros (SET_BIT, CLR_BIT, GET_BIT, TOG_BIT) */
#include "../../ITI_CAIRO_G1_MA_LIB/BIT_MATH.h"
/* Include standard type definitions (u8, etc.) */
#include "../../ITI_CAIRO_G1_MA_LIB/STD_TYPES.h"
/* Include EXTI configuration header */
#include "EXTI_Config.h"
/* Include EXTI private header for register addresses and macros */
#include "EXTI_Private.h"
/* Include EXTI interface header for function prototypes */
#include "EXTI_Interface.h"


/* Function: enable the specified external interrupt */
void EXTI_Enable(u8 exti_id)
{
	/* Validate that the interrupt ID is within valid range */
	if((exti_id >= INT2) && (exti_id <= INT1))
	{
		/* Set the corresponding enable bit in GICR */
		SET_BIT(GICR, exti_id);
	}
}

/* Function: disable the specified external interrupt */
void EXTI_Disable(u8 exti_id)
{
	/* Validate that the interrupt ID is within valid range */
	if((exti_id >= INT2) && (exti_id <= INT1))
	{
		/* Clear the corresponding enable bit in GICR */
		CLR_BIT(GICR, exti_id);
	}
}

/* Function: configure the sense (trigger) mode for the specified external interrupt */
void EXTI_SenseControl(u8 exti_id, u8 sense)
{
	/* Switch on the specified external interrupt */
	switch (exti_id)
	{
	/* Case: External Interrupt 0 selected */
	case INT0:
		/* Switch on the desired sense mode */
		switch (sense)
		{
		/* Case: trigger on low logic level */
		case EXTI_LOW_LOGIC:
			/* Clear ISC01 bit */
			CLR_BIT(MCUCR, ISC01);
			/* Clear ISC00 bit */
			CLR_BIT(MCUCR, ISC00);
			/* Exit sense switch */
			break;
		/* Case: trigger on any logic change */
		case EXTI_ANY_LOGIC:
			/* Clear ISC01 bit */
			CLR_BIT(MCUCR, ISC01);
			/* Set ISC00 bit */
			SET_BIT(MCUCR, ISC00);
			/* Exit sense switch */
			break;
		/* Case: trigger on falling edge */
		case EXTI_FALLING:
			/* Set ISC01 bit */
			SET_BIT(MCUCR, ISC01);
			/* Clear ISC00 bit */
			CLR_BIT(MCUCR, ISC00);
			/* Exit sense switch */
			break;
		/* Case: trigger on rising edge */
		case EXTI_RISING:
			/* Set ISC01 bit */
			SET_BIT(MCUCR, ISC01);
			/* Set ISC00 bit */
			SET_BIT(MCUCR, ISC00);
			/* Exit sense switch */
			break;
		/* Default: invalid sense mode */
		default:
			/* Do nothing */
			break;
		}
		/* Exit interrupt switch */
		break;
	/* Case: External Interrupt 1 selected */
	case INT1:
		/* Switch on the desired sense mode */
		switch (sense)
		{
		/* Case: trigger on low logic level */
		case EXTI_LOW_LOGIC:
			/* Clear ISC11 bit */
			CLR_BIT(MCUCR, ISC11);
			/* Clear ISC10 bit */
			CLR_BIT(MCUCR, ISC10);
			/* Exit sense switch */
			break;
		/* Case: trigger on any logic change */
		case EXTI_ANY_LOGIC:
			/* Clear ISC11 bit */
			CLR_BIT(MCUCR, ISC11);
			/* Set ISC10 bit */
			SET_BIT(MCUCR, ISC10);
			/* Exit sense switch */
			break;
		/* Case: trigger on falling edge */
		case EXTI_FALLING:
			/* Set ISC11 bit */
			SET_BIT(MCUCR, ISC11);
			/* Clear ISC10 bit */
			CLR_BIT(MCUCR, ISC10);
			/* Exit sense switch */
			break;
		/* Case: trigger on rising edge */
		case EXTI_RISING:
			/* Set ISC11 bit */
			SET_BIT(MCUCR, ISC11);
			/* Set ISC10 bit */
			SET_BIT(MCUCR, ISC10);
			/* Exit sense switch */
			break;
		/* Default: invalid sense mode */
		default:
			/* Do nothing */
			break;
		}
		/* Exit interrupt switch */
		break;
	/* Case: External Interrupt 2 selected */
	case INT2:
		/* Switch on the desired sense mode */
		switch (sense)
		{
		/* Case: trigger on falling edge */
		case EXTI_FALLING:
			/* Clear ISC2 bit to select falling edge */
			CLR_BIT(MCUCSR, ISC2);
			/* Exit sense switch */
			break;
		/* Case: trigger on rising edge */
		case EXTI_RISING:
			/* Set ISC2 bit to select rising edge */
			SET_BIT(MCUCSR, ISC2);
			/* Exit sense switch */
			break;
		/* Default: invalid sense mode */
		default:
			/* Do nothing */
			break;
		}
		/* Exit interrupt switch */
		break;
	/* Default: invalid interrupt ID */
	default:
		/* Do nothing */
		break;
	}
}
