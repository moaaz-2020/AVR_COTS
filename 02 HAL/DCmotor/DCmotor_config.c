/***************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam           */
/*****Date        : 03/04/2020                     */
/*****Version     : 1.0  V                         */
/*****Description : DC MOTOR FUNCTION CONFIGURATION*/
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

#include "DCmotor_config.h"
#include "DCmotor_priv.h"

/***************************************************/
/********** ARRAYS INCLUDES NUMBER OF MOTOR ********/
/**********   PINS AND PORTS IS CONSUMED  **********/
/***************************************************/


DCmotor ArraysOfMotors [ NUMBER_OF_MOTOR ] =
{
	{PORTA,PIN0,PORTA,PIN1},  /* PIN id for motor number 0*/
	{PORTA,PIN2,PORTA,PIN3},  /* PIN id for motor number 1*/
	{PORTA,PIN4,PORTA,PIN5},  /* PIN id for motor number 2*/
	{PORTA,PIN6,PORTA,PIN7},  /* PIN id for motor number 3*/
	{PORTB,PIN0,PORTB,PIN1}   /* PIN id for motor number 4*/
};
