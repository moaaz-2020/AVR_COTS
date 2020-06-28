/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 05/04/2020                      */
/****Version     : 1.0  V                          */
/*****Description : EXTERNAL INTERRUPT (2)         */
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


#include "EXTI2_int.h"
#include "EXTI2_config.h"
#include "EXTI2_reg.h"

#define    NULL     ((void *)0)


volatile void (*pf_2)(void) = NULL ; 


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if  SENSE_MODE_1    ==  FALLING
           Local_enuError = ES_OK;
	        CLR_BIT(MCUCSR , 6);
	#elif  SENSE_MODE_1    ==  RISING
	       Local_enuError = ES_OK;
	        SET_BIT(MCUCSR ,6);	
	#else  
		#error "WRONG SENSE MODE"
	#endif
	
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuEnable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
	SET_BIT(GICR , 5);
	return Local_enuError;
}


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuDisable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
		CLR_BIT(GICR , 5);
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
void    EXTI2_voidSetCallBack( void (*ptr)(void))
{
	pf_2 = ptr ; 
}

void __vector_3()__attribute__((signal,size));

void __vector_3()
{
	pf_2();
}