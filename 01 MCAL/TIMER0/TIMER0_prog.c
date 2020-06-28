/****************************************************/
/****AUTHOR       : Moaaz Rashad Sewilam            */
/****Date         : 10/04/2020                      */
/****Version      : 1.0  V                          */
/*****Description : TIMER(0)FUNCTION IMPLEMENTATION */
/****************************************************/


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


#include "TIMER0_int.h"
#include "TIMER0_priv.h"
#include "TIMER0_config.h"
#include "TIMER0_reg.h"


#define    NULL     ((void *)0)


volatile void (*pf)(void) = NULL ; 
volatile void (*pf_1)(void) = NULL ;

/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(0)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   TIMER0_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if        FORCE_OUTPUT_COMPARE    ==   ENABLE_FOC0
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 7);
	#else
         	Local_enuError = ES_OK;
		    CLR_BIT(TCCR0 , 7);
	#endif
	/****************************************/
	#if        WAVE_GENERATION_MODE    ==   NORMAL
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 6); //WGM00
			CLR_BIT(TCCR0 , 3); //WGM01
			/* Normal port operation, OC0 disconnected */
            CLR_BIT(TCCR0 , 4); //COM00
			CLR_BIT(TCCR0 , 5); //COM01			
	#elif      WAVE_GENERATION_MODE    ==   PWM_PHASE_CORRECT 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 6); //WGM00
			CLR_BIT(TCCR0 , 3); //WGM01	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01
            #elif   COMPARE_OUTPUT_MODE   ==  RSERVED 
              	  SET_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01
            /* Clear OC0 on compare match, set OC0 at BOTTOM,
                        (nin-inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC0 
              	  CLR_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01
            /* Set OC0 on compare match, clear OC0 at BOTTOM,
                         (inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC0 
              	  SET_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif			 
	#elif      WAVE_GENERATION_MODE    ==   CTC 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 6); //WGM00
			SET_BIT(TCCR0 , 3); //WGM01
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01
            #elif   COMPARE_OUTPUT_MODE   ==  TOGGLE_OC0 
              	  SET_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01	
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC0 
              	  CLR_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01			
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC0 
              	  SET_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif			
	#elif      WAVE_GENERATION_MODE    ==   FAST_PWM  
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 6); //WGM00
			SET_BIT(TCCR0 , 3); //WGM01
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01
            #elif   COMPARE_OUTPUT_MODE   ==  RSERVED 
              	  SET_BIT(TCCR0 , 4); //COM00
			      CLR_BIT(TCCR0 , 5); //COM01
            /* Clear OC0 on compare match, set OC0 at BOTTOM,
                        (nin-inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC0 
              	  CLR_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01
            /* Set OC0 on compare match, clear OC0 at BOTTOM,
                         (inverting mode) */					  
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC0 
              	  SET_BIT(TCCR0 , 4); //COM00
			      SET_BIT(TCCR0 , 5); //COM01			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif				
    #else
           #error "WAVE_GENERATION_MODE  NOT SELECTED"
    #endif
    /*****************************************/
    #if             CLOCK_SELECT            ==   NO_CLOCK_SOURCE
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 0); //CS00
			CLR_BIT(TCCR0 , 1); //CS01
			CLR_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   NO_PRESCALING
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 0); //CS00
			CLR_BIT(TCCR0 , 1); //CS01
			CLR_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   PRESCALER_8
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 0); //CS00
			SET_BIT(TCCR0 , 1); //CS01
			CLR_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   PRESCALER_64
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 0); //CS00
			SET_BIT(TCCR0 , 1); //CS01
			CLR_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   PRESCALER_256
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 0); //CS00
			CLR_BIT(TCCR0 , 1); //CS01
			SET_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   PRESCALER_1024
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 0); //CS00
			CLR_BIT(TCCR0 , 1); //CS01
			SET_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   EXT_CLK_T0_FALLING_EDGE
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR0 , 0); //CS00
			SET_BIT(TCCR0 , 1); //CS01
			SET_BIT(TCCR0 , 2); //CS01
    #elif             CLOCK_SELECT          ==   EXT_CLK_T0_RISING_EDGE
	        Local_enuError = ES_OK;
			SET_BIT(TCCR0 , 0); //CS00
			SET_BIT(TCCR0 , 1); //CS01
			SET_BIT(TCCR0 , 2); //CS01
    #else 
          #error "CLOCK_SELECT NOT SELECTED"
    #endif	  
	
    return Local_enuError; 	
}

/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(0) REGISTERS */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuSetTimerReg(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

/************************************************/
/* THIS FUNCTION FOR GETTING TIMER(0) REGISTERS */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   TIMER0_enuGetTimerReg(void)
{
	return TCNT0;
}

/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER (0)                     */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuSetCompareValue(u8 Copy_u8Value)
{
	 OCR0  = Copy_u8Value;
}


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (0)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuEnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (0)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuDisableOVInt(void)
{
	CLR_BIT(TIMSK , 0);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING CTC MODE          */
/*            INTERRUPT FOR TIMER (0)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuEnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}



/************************************************/
/* THIS FUNCTION FOR DISABLING CTC MODE         */
/*            INTERRUPT FOR TIMER (0)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuDisableCTCInt(void)
{
	CLR_BIT(TIMSK , 1);
}


/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(0)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER0_vidSetOVCallBack( void (*Copy_ptr)(void))
{
	pf = Copy_ptr ;
}

void __vector_11()__attribute__((signal,used));

void __vector_11()
{
	pf();
}
/************************************************/
/* THIS FUNCTION FOR POINT TO THE CTC MODE      */
/*                 TIMER(0)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER0_vidSetCTCCallBack( void (*Copy_ptr)(void))
{
	pf_1 = Copy_ptr ;
}

void __vector_10()__attribute__((signal,used));

void __vector_10()
{
	pf_1();
}
