/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 06/04/2020                      */
/****Version     : 1.0  V                          */
/*****Description : ANALOG TO DIGITAL CONVERTER    */
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

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_reg.h"
#include "ADC_priv.h"


volatile u16 ADC_u16Value;
/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE ANALOG   */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ADC_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if  VOLTAGE_SELECTION   == AREF
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 6);
	      CLR_BIT(ADMUX , 7);
	#elif  VOLTAGE_SELECTION   == AVCC
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 6);
	      CLR_BIT(ADMUX , 7); 
	#elif  VOLTAGE_SELECTION   == INTERNAL
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 6);
	      SET_BIT(ADMUX , 7);	  
	#else
		#warning "VOLTAGE SELECTION  NOT SELECTED"
	#endif
	/********************************************/
	#if  LEFT_ADJUSTMENT    ==  ACTIVE
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 5);
    #elif  LEFT_ADJUSTMENT    ==  DEACTIVE
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 5);
	#else
		#warning "LEFT_ADJUSTMENT_RESULT  NOT SELECTED"
	#endif
	/*********************************************/
		return Local_enuError;
}

/*****************************************************/
/* THIS FUNCTION FOR SELECT THE CHANNEL THE ANALOG   */
/*                TO DIGITAL CONVERTER               */
/* INPUTS : UNSIGHNED CHARACTER                      */
/* RETURN : Error_enuStatus                          */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus   ADC_enuSelect(u8 Copy_u8ChannelId)
{
	Error_enuStatus  Local_enuError = ES_NOK;

	if(Copy_u8ChannelId == 0)
	{
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
	}
    else if(Copy_u8ChannelId == 1)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==2)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==3)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      CLR_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==4)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==5)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      CLR_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==6)
    {
	      Local_enuError = ES_OK;
		  CLR_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
    else if(Copy_u8ChannelId ==7)
    {
	      Local_enuError = ES_OK;
		  SET_BIT(ADMUX , 0);
	      SET_BIT(ADMUX , 1);
	      SET_BIT(ADMUX , 2);
	      CLR_BIT(ADMUX , 3);
	      CLR_BIT(ADMUX , 4);
    }
	else
	{
		Local_enuError = ES_NOK;
	}
	/**************************************/
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR ENABLING THE ANALOG        */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ADC_enuEnable(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if    ADC_ENABLE       ==   ENABLED
	     Local_enuError = ES_OK;
		 SET_BIT(ADCSRA , 7);
	#else
         #error  "ADC DISABLED"
	#endif 
	/******************************************/
	#if    ADC_AUTO_TRIGGER   ==   DISABLED_AUTO
	     Local_enuError = ES_OK;
		 CLR_BIT(ADCSRA , 5);	 
	#else
         Local_enuError = ES_OK;
		 SET_BIT(ADCSRA , 5);
    #endif 
    /******************************************/
	#if    ADC_INTERRUPT_ENABLE   ==   DISABLED_INTERRUPT
	     Local_enuError = ES_OK;
		 CLR_BIT(ADCSRA , 3);	 
	#else
         Local_enuError = ES_OK;
		 SET_BIT(ADCSRA , 3);
    #endif
	/******************************************/
	#if    PRESCALER_SELECTED       ==   2
        	Local_enuError = ES_OK;
			CLR_BIT(ADCSRA , 0);
	        CLR_BIT(ADCSRA , 1);
	        CLR_BIT(ADCSRA , 2);
	#elif    PRESCALER_SELECTED     ==   4
        	Local_enuError = ES_OK;
			CLR_BIT(ADCSRA , 0);
	        SET_BIT(ADCSRA , 1);
	        CLR_BIT(ADCSRA , 2);
	#elif    PRESCALER_SELECTED     ==   8
        	Local_enuError = ES_OK;
			SET_BIT(ADCSRA , 0);
	        SET_BIT(ADCSRA , 1);
	        CLR_BIT(ADCSRA , 2);
	#elif    PRESCALER_SELECTED     ==   16
        	Local_enuError = ES_OK;
			CLR_BIT(ADCSRA , 0);
	        CLR_BIT(ADCSRA , 1);
	        SET_BIT(ADCSRA , 2);	
	#elif    PRESCALER_SELECTED     ==   32
        	Local_enuError = ES_OK;
			SET_BIT(ADCSRA , 0);
	        CLR_BIT(ADCSRA , 1);
	        SET_BIT(ADCSRA , 2);
	#elif    PRESCALER_SELECTED     ==   64
        	Local_enuError = ES_OK;
			CLR_BIT(ADCSRA , 0);
	        SET_BIT(ADCSRA , 1);
	        SET_BIT(ADCSRA , 2);
	#elif    PRESCALER_SELECTED     ==   128
        	Local_enuError = ES_OK;
			SET_BIT(ADCSRA , 0);
	        SET_BIT(ADCSRA , 1);
	        SET_BIT(ADCSRA , 2);
	#else 
        	CLR_BIT(ADCSRA , 0);
	        CLR_BIT(ADCSRA , 1);
	        CLR_BIT(ADCSRA , 2);
        #warning "NO PRESCALER_SELECTED"
    #endif	
   /**********************************/
   return    Local_enuError ;
}

/************************************************/
/* THIS FUNCTION FOR START CONVERSION BY ANALOG */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED SHORT INTEGER             */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u16   ADC_u16StartConversion(void)
{
	/** ADC START CONVERSION  **/
	SET_BIT(ADCSRA , 6);
	/** WAIT FOR CONVERSION **/
	/** POLLING  **/
	while(GET_BIT(ADCSRA , 4) == 0);
	/** CLEAR FLAG BY H.W  = 1**/
	SET_BIT(ADCSRA , 4);

	ADC_u16Value = ADCH ;
	return ADC_u16Value;
}

