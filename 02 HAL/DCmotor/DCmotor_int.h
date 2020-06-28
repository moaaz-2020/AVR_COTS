/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 03/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : DC MOTOR FUNCTION Prototypes*/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _DCMOTOR_INT_H_
#define   _DCMOTOR_INT_H_

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION DC-MOTOR    */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      DCmotor_int(void);



/************************************************/
/* THIS FUNCTION FOR INITIALIZATION DC-MOTOR    */
/* INPUTS : UNSIGHNED CHARACTER                 */
/*          AND UNSIGHNED INTEGER               */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      DCmotor_vidMove( u8 Copy_u8MotorId , u8 Copy_u8MotorDirection );




#endif