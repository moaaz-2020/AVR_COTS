/*********************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam                 */
/*****Date        : 14/04/2020                           */
/*****Version     : 1.0  V                               */
/*****Description : STEPPER MOTOR FUNCTION CONFIGURATION */
/*********************************************************/


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

#include "STEPPER_config.h"
#include "STEPPER_priv.h"
#include "DIO_int.h"

/***************************************************/
/********** ARRAYS INCLUDES NUMBER OF MOTOR ********/
/**********   PINS AND PORTS IS CONSUMED  **********/
/***************************************************/


StepperMotor ArraysOfMotors [ NUMBER_OF_MOTORS ] =
{
	{PORTA,PIN0,PORTA,PIN1 ,PORTA,PIN2,PORTA,PIN3}  /* PIN id for motor number 0*/

};
