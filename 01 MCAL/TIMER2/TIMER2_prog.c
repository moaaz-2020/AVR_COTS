/****************************************************/
/****AUTHOR       : Moaaz Rashad Sewilam            */
/****Date         : 24/04/2020                      */
/****Version      : 1.0  V                          */
/*****Description : TIMER(2)FUNCTION IMPLEMENTATION */
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


#include "TIMER2_int.h"
#include "TIMER2_priv.h"
#include "TIMER2_config.h"
#include "TIMER2_reg.h"


#define    NULL     ((void *)0)


volatile void (*pf_16)(void) = NULL ; 
volatile void (*pf_17)(void) = NULL ;

/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(2)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   TIMER2_enuInit(void)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	#if        FORCE_OUTPUT_COMPARE    ==   ENABLE_FOC2
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 7);
	#else
         	Local_enuError = ES_OK;
		    CLR_BIT(TCCR2 , 7);
	#endif
	/****************************************/
	#if        WAVE_GENERATION_MODE    ==   NORMAL
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 6); //WGM20
			CLR_BIT(TCCR2 , 3); //WGM21
			/* Normal port operation, OC0 disconnected */
            CLR_BIT(TCCR2 , 4); //COM20
			CLR_BIT(TCCR2 , 5); //COM21			
	#elif      WAVE_GENERATION_MODE    ==   PWM_PHASE_CORRECT 
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 6); //WGM20
			CLR_BIT(TCCR2 , 3); //WGM21	
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21
            #elif   COMPARE_OUTPUT_MODE   ==  RSERVED 
              	  SET_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21
            /* Clear OC2 on compare match, set OC2 at BOTTOM,
                        (nin-inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC2 
              	  CLR_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21
            /* Set OC2 on compare match, clear OC2 at BOTTOM,
                         (inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC2 
              	  SET_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif			 
	#elif      WAVE_GENERATION_MODE    ==   CTC 
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 6); //WGM20
			SET_BIT(TCCR2 , 3); //WGM21
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21
            #elif   COMPARE_OUTPUT_MODE   ==  TOGGLE_OC2 
              	  SET_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21	
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC2 
              	  CLR_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21			
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC2 
              	  SET_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif			
	#elif      WAVE_GENERATION_MODE    ==   FAST_PWM  
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 6); //WGM20
			SET_BIT(TCCR2 , 3); //WGM21
			/* SET THE REQUIRED OUTPUT COMPARE MODE */
            #if     COMPARE_OUTPUT_MODE   ==  NORMAL_PORT_OPERATION
                  CLR_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21
            #elif   COMPARE_OUTPUT_MODE   ==  RSERVED 
              	  SET_BIT(TCCR2 , 4); //COM20
			      CLR_BIT(TCCR2 , 5); //COM21
            /* Clear OC2 on compare match, set OC2 at BOTTOM,
                        (nin-inverting mode) */				  
            #elif   COMPARE_OUTPUT_MODE   ==  CLEAR_OC2 
              	  CLR_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21
            /* Set OC2 on compare match, clear OC2 at BOTTOM,
                         (inverting mode) */					  
            #elif   COMPARE_OUTPUT_MODE   ==  SET_OC2 
              	  SET_BIT(TCCR2 , 4); //COM20
			      SET_BIT(TCCR2 , 5); //COM21			
			#else
                 #error "COMPARE_OUTPUT_MODE NOT SELECTED"
            #endif				
    #else
           #error "WAVE_GENERATION_MODE  NOT SELECTED"
    #endif
    /*****************************************/
    #if             CLOCK_SELECT            ==   NO_CLOCK_SOURCE
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 0); //CS20
			CLR_BIT(TCCR2 , 1); //CS21
			CLR_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   NO_PRESCALING
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 0); //CS20
			CLR_BIT(TCCR2 , 1); //CS21
			CLR_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   PRESCALER_8
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 0); //CS20
			SET_BIT(TCCR2 , 1); //CS21
			CLR_BIT(TCCR2 , 2); //CS21
    #elif             CLOCK_SELECT          ==   PRESCALER_64
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 0); //CS20
			SET_BIT(TCCR2 , 1); //CS21
			CLR_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   PRESCALER_256
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 0); //CS20
			CLR_BIT(TCCR2 , 1); //CS21
			SET_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   PRESCALER_1024
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 0); //CS20
			CLR_BIT(TCCR2 , 1); //CS21
			SET_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   EXT_CLK_T2_FALLING_EDGE
	        Local_enuError = ES_OK;
			CLR_BIT(TCCR2 , 0); //CS20
			SET_BIT(TCCR2 , 1); //CS21
			SET_BIT(TCCR2 , 2); //CS22
    #elif             CLOCK_SELECT          ==   EXT_CLK_T2_RISING_EDGE
	        Local_enuError = ES_OK;
			SET_BIT(TCCR2 , 0); //CS20
			SET_BIT(TCCR2 , 1); //CS21
			SET_BIT(TCCR2 , 2); //CS22
    #else 
          #error "CLOCK_SELECT NOT SELECTED"
    #endif	  
	
    return Local_enuError; 	
}

/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(2) REGISTERS */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuSetTimerReg(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value;
}

/************************************************/
/* THIS FUNCTION FOR GETTING TIMER(2) REGISTERS */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   TIMER2_enuGetTimerReg(void)
{
	return TCNT2;
}

/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER (2)                     */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuSetCompareValue(u8 Copy_u8Value)
{
	 OCR2  = Copy_u8Value;
}


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (2)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuEnableOVInt(void)
{
	SET_BIT(TIMSK , 6);
}



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (2)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuDisableOVInt(void)
{
	CLR_BIT(TIMSK , 6);
}


/************************************************/
/* THIS FUNCTION FOR ENABLING CTC MODE          */
/*            INTERRUPT FOR TIMER (2)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuEnableCTCInt(void)
{
	SET_BIT(TIMSK , 7);
}



/************************************************/
/* THIS FUNCTION FOR DISABLING CTC MODE         */
/*            INTERRUPT FOR TIMER (2)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuDisableCTCInt(void)
{
	CLR_BIT(TIMSK , 7);
}


/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(2)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER2_vidSetOVCallBack( void (*Copy_ptr)(void))
{
	pf_16 = Copy_ptr ;
}

void __vector_5()__attribute__((signal,used));

void __vector_5()
{
	pf_16();
}
/************************************************/
/* THIS FUNCTION FOR POINT TO THE CTC MODE      */
/*                 TIMER(2)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER2_vidSetCTCCallBack( void (*Copy_ptr)(void))
{
	pf_17 = Copy_ptr ;
}

void __vector_4()__attribute__((signal,used));

void __vector_4()
{
	pf_17();
}
