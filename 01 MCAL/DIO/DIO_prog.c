/************************************************/
/*****AUTHOR      : MOAAZ RASHAD SEWILAM       **/
/*****Date        : 26/03/2020                 **/
/*****Version     : 1.0   V                    **/
/*****Description : IMPLEMENTATION OF FUNCTION **/
/************************************************/


/************************************************/
/**********  STANDARD LIB DIRECTIVES ************/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

/************************************************/
/********** COMPONENTS DIRECTIVES    ************/
/************************************************/

#include "DIO_reg.h"
#include "DIO_int.h"


/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/


/************************************************/
/*    THIS FUNCTION USED TO SET PIN DIRECTION   */
/*    INPUTS : UNSIGHNED INT ,UNSIGHNED INT     */
/*    AND      UNSIGHNED INT                    */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

Error_enuStatus        DIO_enumSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinId,u8 Copy_u8Direction)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{  
                Local_enuError = ES_OK;
		if(Copy_u8Direction == OUTPUT)
		{
		     switch(Copy_u8PortId)
		    {
			     case PORTA: SET_BIT(DIO_PU8_DDRA_REG ,Copy_u8PinId); break;
			     case PORTB: SET_BIT(DIO_PU8_DDRB_REG ,Copy_u8PinId); break;
			     case PORTC: SET_BIT(DIO_PU8_DDRC_REG ,Copy_u8PinId); break;
			     case PORTD: SET_BIT(DIO_PU8_DDRD_REG ,Copy_u8PinId); break;
       		     }
		}
	
	        else if(Copy_u8Direction == INPUT)
	        {
	      		     switch(Copy_u8PortId)
		        {
			     case PORTA: CLR_BIT(DIO_PU8_DDRA_REG ,Copy_u8PinId); break;
			     case PORTB: CLR_BIT(DIO_PU8_DDRB_REG ,Copy_u8PinId); break;
			     case PORTC: CLR_BIT(DIO_PU8_DDRC_REG ,Copy_u8PinId); break;
			     case PORTD: CLR_BIT(DIO_PU8_DDRD_REG ,Copy_u8PinId); break;
       		         } 
	        }
        
	        else
	        {
                    Local_enuError = ES_NOK;
                }
	}
       else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}		
	return Local_enuError;
}

/************************************************/
/*    THIS FUNCTION USED TO SET PIN VALUE       */
/*    INPUTS : UNSIGHNED INT ,UNSIGHNED INT     */
/*    AND      UNSIGHNED INT                    */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/
 
Error_enuStatus        DIO_enumSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId,u8 Copy_u8Value)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{
               Local_enuError = ES_OK;
		if(Copy_u8Value == HIGH)
		{
		     switch(Copy_u8PortId)
		    {
			     case PORTA: SET_BIT(DIO_PU8_PORTA_REG ,Copy_u8PinId); break;
			     case PORTB: SET_BIT(DIO_PU8_PORTB_REG ,Copy_u8PinId); break;
			     case PORTC: SET_BIT(DIO_PU8_PORTC_REG ,Copy_u8PinId); break;
			     case PORTD: SET_BIT(DIO_PU8_PORTD_REG ,Copy_u8PinId); break;
       		    }
		}
	        else if(Copy_u8Value == LOW)
	        {
	             switch(Copy_u8PortId)
		        {
			     case PORTA: CLR_BIT(DIO_PU8_PORTA_REG ,Copy_u8PinId); break;
			     case PORTB: CLR_BIT(DIO_PU8_PORTB_REG ,Copy_u8PinId); break;
			     case PORTC: CLR_BIT(DIO_PU8_PORTC_REG ,Copy_u8PinId); break;
			     case PORTD: CLR_BIT(DIO_PU8_PORTD_REG ,Copy_u8PinId); break;
       		        } 
	        }
	       else
	        {
		   Local_enuError = ES_NOK;
	        }
        }
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;;
	}		
	return Local_enuError;
}


/************************************************/
/*    THIS FUNCTION USED TO GET PIN VALUE       */
/*    INPUTS : UNSIGHNED INT ,UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

u8                     DIO_enumGetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{
		u8 Local_u8Value;
	  switch(Copy_u8PortId)
	  {
		 case PORTA: Local_u8Value = GET_BIT(DIO_PU8_PINA_REG ,Copy_u8PinId); break;
		 case PORTB: Local_u8Value = GET_BIT(DIO_PU8_PINB_REG ,Copy_u8PinId); break;
	         case PORTC: Local_u8Value = GET_BIT(DIO_PU8_PINC_REG ,Copy_u8PinId); break;
	         case PORTD: Local_u8Value = GET_BIT(DIO_PU8_PIND_REG ,Copy_u8PinId); break;  
	  }	 
	  return Local_u8Value;
	}
	else
	{
	   return ES_OUT_OF_RANGE;
	}	
}

/************************************************/
/*    THIS FUNCTION USED TO SET PORT DIRECTION  */
/*    INPUTS : UNSIGHNED INT ,UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/
  
Error_enuStatus        DIO_enumSetPortDirection(u8 Copy_u8PortId ,u8 Copy_u8Direction)
{
	Error_enuStatus Local_enuError;
	if( Copy_u8PortId < 4 )
	{
		switch(Copy_u8PortId)
		{
	      case PORTA: DIO_PU8_DDRA_REG = Copy_u8Direction; break;
   	      case PORTB: DIO_PU8_DDRB_REG = Copy_u8Direction; break;
	      case PORTC: DIO_PU8_DDRC_REG = Copy_u8Direction; break;
	      case PORTD: DIO_PU8_DDRD_REG = Copy_u8Direction; break; 
		}
		Local_enuError = ES_OK;
	}
	else
	{
		Local_enuError = ES_NOK;
	}
	return Local_enuError;
} 


/************************************************/
/*    THIS FUNCTION USED TO SET PORT VALUE      */
/*    INPUTS : UNSIGHNED INT ,UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/


Error_enuStatus        DIO_enumSetPortValue(u8 Copy_u8PortId ,u8 Copy_u8Value)
{
	Error_enuStatus Local_enuError;
	if( Copy_u8PortId < 4 )
	{
		switch(Copy_u8PortId)
		{
	      case PORTA: DIO_PU8_PORTA_REG = Copy_u8Value; break;
   	      case PORTB: DIO_PU8_PORTB_REG = Copy_u8Value; break;
	      case PORTC: DIO_PU8_PORTC_REG = Copy_u8Value; break;
	      case PORTD: DIO_PU8_PORTD_REG = Copy_u8Value; break; 
		}
		Local_enuError = ES_OK;
	}
	else
	{
		Local_enuError = ES_NOK;
	}
	return Local_enuError;
}

