/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 05/04/2020                      */
/****Version     : 1.0  V                          */
/*****Description : EXTERNAL INTERRUPT (0)         */
/*****                 FUNCTION IMPLEMENTATION     */
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


#include "EXTI0_int.h"
#include "EXTI0_config.h"
#include "EXTI0_reg.h"

#define    NULL     ((void *)0)


volatile void (*pf)(void) = NULL ; 


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (0)                 */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/
//555
Error_enuStatus   EXTI0_enuInit(u8 Copy_u8SenseMode)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	//       LOW      ==     1
	if      (Copy_u8SenseMode   ==  1)
	{
	       Local_enuError = ES_OK;
	        CLR_BIT(MCUCR ,0);
	        CLR_BIT(MCUCR ,1);
	}
	//       IOC      ==     2
	else if (Copy_u8SenseMode  == 2)
	{
	       Local_enuError = ES_OK;
	        SET_BIT(MCUCR ,0);
	        CLR_BIT(MCUCR ,1);
	}
	//       FALLING  ==     3
	else if (Copy_u8SenseMode == 3)
	{
           Local_enuError = ES_OK;
	        CLR_BIT(MCUCR ,0);
	        SET_BIT(MCUCR ,1);
	}
	//       RISING   ==     4
	else if ( Copy_u8SenseMode == 4)
	{
	       Local_enuError = ES_OK;
	        SET_BIT(MCUCR ,0);
	        SET_BIT(MCUCR ,1);
	}
	else  
	{
		Local_enuError = ES_NOK;
	}	
	
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (0)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI0_enuEnable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
	SET_BIT(GICR , 6);
	return Local_enuError;
}


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (0)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI0_enuDisable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
		CLR_BIT(GICR , 6);
		return Local_enuError;
}


/************************************************/
/* THIS FUNCTION FOR POINT TO THE INTERRUPT     */
/*                    FUNCTION                  */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

/* THIS FUNCTION IS MADE BECAUSE THIS FILE EXIST IN MCAL LAYER
  AND NEED A FUNCTION FROM APPLICATION LAYER AND THIS OPPOSING
  DEPEND ON ARCHITECHTURE LAYERS METHODS SO WE USE THIS FUNCTION
  THAT CONTAIN A POINTER THAT POINT TO THE FUNCTION EXIST IN THE
   APPLICATION LAYER
  */
void    EXTI0_voidSetCallBack( void (*ptr)(void))
{
	pf = ptr ; 
}

void __vector_1()__attribute__((signal,used));

void __vector_1()
{
	pf();
}
