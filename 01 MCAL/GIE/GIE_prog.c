/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 05/04/2020                      */
/****Version     : 1.0  V                          */
/****Description : GLOBAL INTERRUPT ENABLE         */
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
#include "GIE_reg.h"



/************************************************/
/* THIS FUNCTION FOR ENABLING THE GIE           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   GIE_enuEnable(void)
{
	SET_BIT(SREG , 7);
}

/************************************************/
/* THIS FUNCTION FOR DISABLE THE GIE            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    GIE_enuDisable(void)
{
	CLR_BIT(SREG , 7);
}