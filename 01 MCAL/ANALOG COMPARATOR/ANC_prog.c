/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 29/04/2020                      */
/****Version     : 1.0  V                          */
/*****Description : ANALOG COMPARATOR CONVERTER    */
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

#include "DIO_int.h"
#include "DIO_reg.h"

#include "ANC_int.h"
#include "ANC_config.h"
#include "ANC_reg.h"
#include "ANC_priv.h"


#define    NULL     ((void *)0)


volatile void (*pf_14)(void) = NULL ;

/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE ANALOG   */
/*                COMPARATOR                    */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ANC_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if  ANC_MULTIPLEXER   == ENABLE_ANC_MUX
	      Local_enuError = ES_OK;
		  SET_BIT(SFIOR  , 3);//ACME
	      CLR_BIT(ADCSRA , 7);//ADEN
	#else
	      Local_enuError = ES_OK;
		  SET_BIT(SFIOR  , 3);//ACME
	      SET_BIT(ADCSRA , 7);//ADEN
	#endif	  
	/********************************************/
	#if     ANC_INTERRUPT_MODE_SELECT    ==  ANC_TOGGLE
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 0);//ACIS0
		  CLR_BIT(ACSR , 1);//ACIS1		  
    #elif   ANC_INTERRUPT_MODE_SELECT    ==  ANC_RESERVED
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 0);//ACIS0
		  CLR_BIT(ACSR , 1);//ACIS1	
    #elif   ANC_INTERRUPT_MODE_SELECT    ==  ANC_FALLING
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 0);//ACIS0
		  SET_BIT(ACSR , 1);//ACIS1	
    #elif   ANC_INTERRUPT_MODE_SELECT    ==  ANC_RISING
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 0);//ACIS0
		  SET_BIT(ACSR , 1);//ACIS1			  
	#else
		#error "ANC_INTERRUPT_MODE  NOT SELECTED"
	#endif
	#if  ANC_INPUT_CAPTURE   == ENABLE_ANC_ICU
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 2);//ACIC		  
	#else
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 2);//ACIC		  
	#endif	
	#if  ANC_INTERRUPT   == ENABLE_ANC_INT
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 3);//ACIE		  
	#else
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 3);//ACIE		  
	#endif		
	#if  ANC_BANDGAP_SELECT   == ENABLE_ANC_BANDGAP
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 6);//ACBG	// AIN0 NOT CONNECTED AND APLLY A FIXED V_REF = 1.23 VOLT	  
	#else
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 6);//ACBG	// AIN0 CONNECTED	  
	#endif	
	#if  ANC_DISABLE   == ENABLE_ANC
	      Local_enuError = ES_OK;
		  SET_BIT(ACSR , 7);//ACD	  
	#else
	      Local_enuError = ES_OK;
		  CLR_BIT(ACSR , 7);//ACD	  
	#endif	
	/*********************************************/
		return Local_enuError;
}

/*****************************************************/
/* THIS FUNCTION FOR SELECT THE CHANNEL THE ANALOG   */
/*   TO DIGITAL CONVERTER WHEN CHOOSE ADC CHANNELS   */
/* INPUTS : UNSIGHNED CHARACTER                      */
/* RETURN : Error_enuStatus                          */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus   ANC_enuSelect(u8 Copy_u8ChannelId)
{
	Error_enuStatus  Local_enuError = ES_NOK;

	if(Copy_u8ChannelId == 0)
	{
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
	}
    else if(Copy_u8ChannelId == 1)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==2)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==3)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==4)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==5)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==6)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
    }
    else if(Copy_u8ChannelId ==7)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
    }
	else
	{
		Local_enuError = ES_NOK;
	}
	/**************************************/
	return Local_enuError;
}


/************************************************/
/* THIS FUNCTION FOR POINT TO THE ANALOG        */
/*                 COMPARATOR  FUNCTION         */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    ANC_vidComparatorCallBack( void (*Copy_ptr)(void))
{
	pf_14 = Copy_ptr ;
}

void __vector_18()__attribute__((signal,used));

void __vector_18()
{
	pf_14();
}