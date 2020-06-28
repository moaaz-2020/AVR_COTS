/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 05/04/2020                      */
/****Version     : 1.0  V                          */
/*****Description : EXTERNAL INTERRUPT (1)         */
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


#include "EXTI1_int.h"
#include "EXTI1_config.h"
#include "EXTI1_reg.h"

#define    NULL     ((void *)0)


volatile void (*pf_1)(void) = NULL ; 


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if    SENSE_MODE_1    ==  LOW
	       Local_enuError = ES_OK;
	        CLR_BIT(MCUCR ,2);
	        CLR_BIT(MCUCR ,3);
	#elif  SENSE_MODE_1    ==  IOC
	       Local_enuError = ES_OK;
	        SET_BIT(MCUCR ,2);
	        CLR_BIT(MCUCR ,3);
	#elif  SENSE_MODE_1    ==  FALLING
           Local_enuError = ES_OK;
	        CLR_BIT(MCUCR ,2);
	        SET_BIT(MCUCR ,3);
	#elif  SENSE_MODE_1    ==  RISING
	       Local_enuError = ES_OK;
	        SET_BIT(MCUCR ,2);
	        SET_BIT(MCUCR ,3);	
	#else  
		#error "WRONG SENSE MODE"
	#endif
	
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuEnable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
	SET_BIT(GICR , 7);
	return Local_enuError;
}


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuDisable(void)
{
	Error_enuStatus  Local_enuError = ES_OK;
		CLR_BIT(GICR , 7);
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
void    EXTI1_voidSetCallBack( void (*ptr)(void))
{
	pf_1 = ptr ; 
}

void __vector_2()__attribute__((signal,size));

void __vector_2()
{
	pf_1();
}