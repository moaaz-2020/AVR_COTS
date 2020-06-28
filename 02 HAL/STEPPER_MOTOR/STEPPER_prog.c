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

#include "STEPPER_config.h"
#include "STEPPER_priv.h"
#include "STEPPER_int.h"


/**************************************************/
/* THIS FUNCTION FOR INITIALIZATION STEPPER-MOTOR */
/* INPUTS : VOID                                  */
/* RETURN : VOID                                  */
/**************************************************/
/*    PRECONDITION :                              */
/*                                                */
/**************************************************/

void      StepperMotor_vidInit(void)
{
	for(u16 Local_u16Counter = 0 ; Local_u16Counter <  NUMBER_OF_MOTORS  ; Local_u16Counter++)
	{
		/* Motor_Local_u16Counter Blue Pin = 0  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u16Counter  ]. BlueMotorPort , ArraysOfMotors [ Local_u16Counter  ]. BlueMotorWire , LOW);
		
		/* Motor_Local_u16Counter Pink Pin = 1  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u16Counter  ]. PinkMotorPort , ArraysOfMotors [ Local_u16Counter  ]. PinkMotorWire , LOW);
		
		/* Motor_Local_u16Counter Yellow Pin = 2  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u16Counter  ]. YellowMotorPort , ArraysOfMotors [ Local_u16Counter  ]. YellowMotorWire , LOW);
		
		/* Motor_Local_u16Counter Orange Pin = 3  */
		DIO_enumSetPinValue(ArraysOfMotors [ Local_u16Counter  ]. OrangeMotorPort , ArraysOfMotors [ Local_u16Counter  ]. OrangeMotorWire , LOW);		
	}
	
	
}



/**********************************************************/
/* THIS FUNCTION FOR INITIALIZATION STEPPER-MOTOR         */
/* INPUTS : 2 UNSIGHNED CHARACTER & 2 UNSIGHNED INTEGER   */
/*          AND UNSIGHNED INTEGER                         */
/* RETURN : VOID                                          */
/**********************************************************/
/*    PRECONDITION :                                      */
/*                                                        */
/**********************************************************/

void  StepperMotor_vidMove( u8 Copy_u8MotorId , u8 Copy_u8MotorDirection , u16 Copy_u16MotorSpeed , u16 Copy_u16NumberSteps)
{
	if(Copy_u8MotorId < NUMBER_OF_MOTORS)
	{
	switch(Copy_u8MotorDirection )
	{
		case STOP :                   
                                             		/***** Turn Off All Pins of Stepper Motors ******/
                    			for(u16 Local_u16Counter = 0 ; Local_u16Counter <  Copy_u16NumberSteps ; Local_u16Counter++)
	                                 {
		                                /* Motor_Local_u16Counter Blue Pin = 0  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , LOW);
		   
		                                /* Motor_Local_u16Counter Pink Pin = 1  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , LOW);
		
		                                /* Motor_Local_u16Counter Yellow Pin = 2  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorPort , ArraysOfMotors [Copy_u8MotorId ]. YellowMotorWire , LOW);
		
                                        /* Motor_Local_u16Counter Orange Pin = 3  */
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorWire , LOW);		
										_delay_ms(MAXIMUM_SPEED_MS);
	                                 }
		            break;
		case CLOCKWISE :
                    			for(u16 Local_u16Counter = 0 ; Local_u16Counter <  Copy_u16NumberSteps ; Local_u16Counter++)
	                                 {	 
		                                /* SEQUENCE 1 COIL ON BLUE WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorWire , HIGH);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 2 COIL ON PINK WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , HIGH);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 3 COIL ON YELLOW WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId]. YellowMotorWire , HIGH);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 4 COIL ON ORANGE WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorWire , HIGH);		
										_delay_ms(Copy_u16MotorSpeed);										
	                                 }		
	                break;
		case ANTI_CLOCKWISE :
                    			for(u16 Local_u16Counter = 0 ; Local_u16Counter <  Copy_u16NumberSteps ; Local_u16Counter++)
	                                 {	 
		                                /* SEQUENCE 1 COIL ON ORANGE WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId]. OrangeMotorWire , HIGH);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 2 COIL ON YELLOW WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , HIGH);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 3 COIL ON PINK WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. BlueMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorWire , HIGH);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId   ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);
		                                /* SEQUENCE 4 COIL ON BLUE WIRE IS ACTIVE  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , HIGH);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , LOW);
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. YellowMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorWire , LOW);
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId ]. OrangeMotorWire , LOW);		
										_delay_ms(Copy_u16MotorSpeed);										
	                                 }			
		            break;	
        default    :
                                             		/***** Turn Off All Pins of Stepper Motors ******/
                    			for(u16 Local_u16Counter = 0 ; Local_u16Counter <  Copy_u16NumberSteps ; Local_u16Counter++)
	                                 {
		                                /* Motor_Local_u16Counter Blue Pin = 0  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. BlueMotorWire , LOW);
		   
		                                /* Motor_Local_u16Counter Pink Pin = 1  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. PinkMotorWire , LOW);
		
		                                /* Motor_Local_u16Counter Yellow Pin = 2  */
		                                DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. YellowMotorPort , ArraysOfMotors [Copy_u8MotorId ]. YellowMotorWire , LOW);
		
                                        /* Motor_Local_u16Counter Orange Pin = 3  */
	                                    DIO_enumSetPinValue(ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorPort , ArraysOfMotors [ Copy_u8MotorId  ]. OrangeMotorWire , LOW);		
										_delay_ms(MAXIMUM_SPEED_MS);
	                                 }		
		            break;	
	}
	}
	else
	{
		/* Out of Range*/
	}
}