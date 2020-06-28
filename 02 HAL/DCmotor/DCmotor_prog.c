/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 03/04/2020                      */
/****Version     : 1.0  V                          */
/****Description : DC MOTOR FUNCTION IMPLEMENTATION*/
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
#include "DCmotor_int.h"




/************************************************/
/* THIS FUNCTION FOR INITIALIZATION DC-MOTOR    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      DCmotor_int(void)
{
	u8 DCmotor_u8LeftPin;
	for(u8 Local_u8Counter = 0 ; Local_u8Counter >  NUMBER_OF_MOTOR  ; Local_u8Counter++)
	{
		/* Motor_Local_u8Counter Right Pin = 0  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u8Counter  ]. DCmotor_u8RightPort , ArraysOfMotors [ Local_u8Counter  ]. DCmotor_u8RightPin , LOW);
		
		/* Motor_Local_u8Counter Left Pin = 0  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u8Counter  ]. DCmotor_u8LeftPort , ArraysOfMotors [ Local_u8Counter  ]. DCmotor_u8LeftPin , LOW);
		
	}
	
	
}



/************************************************/
/* THIS FUNCTION FOR INITIALIZATION KEYPAD      */
/* INPUTS : UNSIGHNED INTEGER                   */
/*          AND UNSIGHNED INTEGER               */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      DCmotor_vidMove( u8 Copy_u8MotorId , u8 Copy_u8MotorDirection )
{
	if(Copy_u8MotorId < NUMBER_OF_MOTOR)
	{
	switch(Copy_u8MotorDirection )
	{
		case STOP : 
                    		/* Motor_Local_u8Counter Right Pin = 0  */
	             	DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPin , LOW);
		
		                    /* Motor_Local_u8Counter Left Pin = 0  */
		            DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. DCmotor_u8LeftPort , ArraysOfMotors [ Copy_u8MotorId  ]. DCmotor_u8LeftPin , LOW);		
		            break;
		case RIGHT :
          		    	/* Motor_Local_u8Counter Right Pin = 1  */
	             	DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPin , HIGH);
		
		                    /* Motor_Local_u8Counter Left Pin = 0  */
		            DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPin , LOW);		
	
	                break;
		case LEFT  :
                   	/* Motor_Local_u8Counter Right Pin = 0  */
	             	DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPin , LOW);
		
		                    /* Motor_Local_u8Counter Left Pin = 1  */
		            DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPin , HIGH);		
		            break;	
        default    :
                   	         /* Motor_Local_u8Counter Right Pin = 0  */
	             	DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8RightPin , LOW);
		
		                    /* Motor_Local_u8Counter Left Pin = 0  */
		            DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPort , ArraysOfMotors [ Copy_u8MotorId   ]. DCmotor_u8LeftPin , LOW);		
		            break;	
	}
	}
	else
	{
		/* Out of Range*/
	}
}