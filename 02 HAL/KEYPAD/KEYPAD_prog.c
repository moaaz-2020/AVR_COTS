/***************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam          **/
/*****Date        : 31/03/2020                    **/
/*****Version     : 1.0  V                        **/
/*****Description : KEYPAD FUNCTION IMPLEMENTATION**/
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

#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_int.h"


/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION KEYPAD      */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      KEYPAD_vidInit(void)
{
	/*          SET PIN DIRECTION FOR ROWS                    */
	DIO_enumSetPinDirection(KEYPAD_D0_PORT , KEYPAD_D0_PIN ,INPUT);
	DIO_enumSetPinDirection(KEYPAD_D1_PORT , KEYPAD_D1_PIN ,INPUT);
	DIO_enumSetPinDirection(KEYPAD_D2_PORT , KEYPAD_D2_PIN ,INPUT);
	DIO_enumSetPinDirection(KEYPAD_D3_PORT , KEYPAD_D3_PIN ,INPUT);
	/*          SET PIN DIRECTION FOR COLUMNS                 */

	DIO_enumSetPinDirection(KEYPAD_D4_PORT , KEYPAD_D4_PIN ,OUTPUT);
	DIO_enumSetPinDirection(KEYPAD_D5_PORT , KEYPAD_D5_PIN ,OUTPUT);
	DIO_enumSetPinDirection(KEYPAD_D6_PORT , KEYPAD_D6_PIN ,OUTPUT);
	DIO_enumSetPinDirection(KEYPAD_D7_PORT , KEYPAD_D7_PIN ,OUTPUT);

	/*  SET PIN VALUE AND ACTIVATE INTERNAL PULL-UP FOR ROWS   */
	DIO_enumSetPinValue(KEYPAD_D0_PORT , KEYPAD_D0_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D1_PORT , KEYPAD_D1_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D2_PORT , KEYPAD_D2_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D3_PORT , KEYPAD_D3_PIN ,HIGH);

	/*         INITIALIZE THE VALUE FOR COLUNMS                */

	DIO_enumSetPinValue(KEYPAD_D4_PORT , KEYPAD_D4_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D5_PORT , KEYPAD_D5_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D6_PORT , KEYPAD_D6_PIN ,HIGH);
	DIO_enumSetPinValue(KEYPAD_D7_PORT , KEYPAD_D7_PIN ,HIGH);

}

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION KEYPAD      */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8       KEYPAD_u8GetPressedKeyPad(void)
{
	u8 Local_u8Row = 0x0F ;
	u8 Local_u8Column = 0 ;

	for(Local_u8Column = 4 ; Local_u8Column < 8 ; Local_u8Column++ )
	{
		/********* SET ALL PINS OF COLUMNS *************/
		DIO_enumSetPinValue(KEYPAD_D4_PORT , KEYPAD_D4_PIN ,HIGH);
		DIO_enumSetPinValue(KEYPAD_D5_PORT , KEYPAD_D5_PIN ,HIGH);
		DIO_enumSetPinValue(KEYPAD_D6_PORT , KEYPAD_D6_PIN ,HIGH);
		DIO_enumSetPinValue(KEYPAD_D7_PORT , KEYPAD_D7_PIN ,HIGH);


		switch(Local_u8Column)
		{         
		/*      COLUMN    0111       */
		case 4: DIO_enumSetPinValue(KEYPAD_D4_PORT , KEYPAD_D4_PIN ,LOW);break;
		case 5: DIO_enumSetPinValue(KEYPAD_D5_PORT , KEYPAD_D5_PIN ,LOW);break;
		case 6: DIO_enumSetPinValue(KEYPAD_D6_PORT , KEYPAD_D6_PIN ,LOW);break;
		case 7: DIO_enumSetPinValue(KEYPAD_D7_PORT , KEYPAD_D7_PIN ,LOW);break;
		}
		_delay_ms(1);

		/********** IF PRESS ON ANY KEY FOR WAITING A RESPONSE FROM " ROWS " ****************/
		if(POS_SIGNAL == DIO_enumGetPinValue(KEYPAD_D0_PORT , KEYPAD_D0_PIN )){Local_u8Row = 0;}
		if(POS_SIGNAL == DIO_enumGetPinValue(KEYPAD_D1_PORT , KEYPAD_D1_PIN )){Local_u8Row = 1;}
		if(POS_SIGNAL == DIO_enumGetPinValue(KEYPAD_D2_PORT , KEYPAD_D2_PIN )){Local_u8Row = 2;}
		if(POS_SIGNAL == DIO_enumGetPinValue(KEYPAD_D3_PORT , KEYPAD_D3_PIN )){Local_u8Row = 3;}

		/***** IF YOU DO NOT PRESS ON ANY KEY  *****/
		if(Local_u8Row != 0x0F)
		{
			/**************** IF YOU PRESS A LONG TIME ON ANY KEY .... WAIT FOR A RESPONSE "ROWS" *****************/
			while((0 == DIO_enumGetPinValue(KEYPAD_D0_PORT , KEYPAD_D0_PIN )) || (0 == DIO_enumGetPinValue(KEYPAD_D1_PORT , KEYPAD_D1_PIN )) || (0 == DIO_enumGetPinValue(KEYPAD_D2_PORT , KEYPAD_D2_PIN )) || (0 == DIO_enumGetPinValue(KEYPAD_D3_PORT , KEYPAD_D3_PIN )));
			return KEYPAD_Au8SwitchValue[Local_u8Row][Local_u8Column-4];

		}
	}
		/***** IF YOU DO NOT PRESS ON ANY KEY  *****/	
			if(Local_u8Row == 0x0F && Local_u8Column ==8)
		{
			return NO_KEY_PRESSED;
		}
}
