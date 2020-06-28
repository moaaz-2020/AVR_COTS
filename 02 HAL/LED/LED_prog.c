/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 30/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : LED FUNCTION IMPLEMENTATION**/
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
#include "DIO_int.h"
#include "DIO_reg.h"

#include "LED_int.h"



/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/

/************************************************/
/*    THIS FUNCTION USED TO SET LED PIN         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/


void                    LED_enumSetLedPin(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	DIO_enumSetPinDirection( Copy_u8PortId , Copy_u8PinId , OUTPUT);
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED ON          */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOn(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{
               Local_enuError = ES_OK;
		     switch(Copy_u8PortId)
		        {
			     case PORTA: SET_BIT(DIO_PU8_PORTA_REG ,Copy_u8PinId); break;
			     case PORTB: SET_BIT(DIO_PU8_PORTB_REG ,Copy_u8PinId); break;
			     case PORTC: SET_BIT(DIO_PU8_PORTC_REG ,Copy_u8PinId); break;
			     case PORTD: SET_BIT(DIO_PU8_PORTD_REG ,Copy_u8PinId); break;
       		    }
	}			
	else
	{
		Local_enuError = ES_NOK;
	}		
	return Local_enuError ;
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED OFF         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOff(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{
               Local_enuError = ES_OK;
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
	return Local_enuError ;
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED TOGGLE      */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedTog(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 4 && Copy_u8PinId < 8 )
	{
               Local_enuError = ES_OK;
		     switch(Copy_u8PortId)
		        {
			     case PORTA: TOG_BIT(DIO_PU8_PORTA_REG ,Copy_u8PinId); break;
			     case PORTB: TOG_BIT(DIO_PU8_PORTB_REG ,Copy_u8PinId); break;
			     case PORTC: TOG_BIT(DIO_PU8_PORTC_REG ,Copy_u8PinId); break;
			     case PORTD: TOG_BIT(DIO_PU8_PORTD_REG ,Copy_u8PinId); break;
       		    }
	}			
	else
	{
		Local_enuError = ES_NOK;
	}		
	return Local_enuError ;
}