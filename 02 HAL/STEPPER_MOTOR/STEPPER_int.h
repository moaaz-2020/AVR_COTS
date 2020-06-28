/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 13/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : STEPPER MOTOR FUNCTION      */
/*****                   Prototypes             */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _STEPPER_INT_H_
#define   _STEPPER_INT_H_


/************************************************/
/***** 	THE DIRECTION OF STEPPER MOTOR     ******/
/***** CLOCKWISE , ANTI-CLOCKWISE OR STOP  ******/
/************************************************/

#define        CLOCKWISE                      1
#define        ANTI_CLOCKWISE                 2
#define        STOP                           3

/************************************************/
/***** 	DELAYS FOR STEPPER MOTOR TO TRANSFERE ***/
/***** FROM POSTION TO ANOTHER POSITION       ***/
/************************************************/

#define        MAXIMUM_SPEED_MS               2
#define        MINIMUM_SPEED_MS               800

/*******************************************/
/******* THE NUMBER STEPPER MOTOR STEPS ****/ 
/******* 360 DEGREE = 512 FOR ONE FULL  ****/
/******* ROTATION FROM 0 TO 512 YOU CAN ****/  
/******* CHOOSE THE THE REQUIRED STEP   ****/
/*******************************************/ 


#define        FULL_ROTATION_360_DEGREE       512
#define        HALF_ROTATION_180_DEGREE       256
#define        QUARTER_ROTATION_90_DEGREE    128


/**************************************************/
/* THIS FUNCTION FOR INITIALIZATION STEPPER-MOTOR */
/* INPUTS : VOID                                  */
/* RETURN : VOID                                  */
/**************************************************/
/*    PRECONDITION :                              */
/*                                                */
/**************************************************/

void      StepperMotor_vidInit(void);



/**********************************************************/
/* THIS FUNCTION FOR INITIALIZATION STEPPER-MOTOR         */
/* INPUTS : 2 UNSIGHNED CHARACTER & 2 UNSIGHNED INTEGER   */
/*          AND UNSIGHNED INTEGER                         */
/* RETURN : VOID                                          */
/**********************************************************/
/*    PRECONDITION :                                      */
/*                                                        */
/**********************************************************/

void      StepperMotor_vidMove( u8 Copy_u8MotorId , u8 Copy_u8MotorDirection , u16 Copy_u16MotorSpeed , u16 Copy_u16NumberSteps);




#endif