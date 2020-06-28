/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 15/04/2020                      */
/****Version     : 1.0  V                          */
/****Description : WATCH DOG TIMER FUNCTION        */
/****                 IMPLEMENTATION               */
/***************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/


#include "GIE_int.h"

#include "WDT_int.h"
#include "WDT_reg.h"

/************************************************/
/* THIS FUNCTION FOR ENABLING THE WDT           */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   WDT_enuEnable(u8 Copy_u8TimerPrescaling)
{
	WDTCR |= (1<<3) |  (Copy_u8TimerPrescaling) ;
}

/************************************************/
/* THIS FUNCTION FOR DISABLE THE WDT            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   WDT_enuDisable(void)
{
	WDTCR |= (1<<3) | (1<<4) ;
	WDTCR = 0;
	
}
