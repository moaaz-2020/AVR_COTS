/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 03/04/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : AVR DC-MOTOR PRIVATE       **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef  _DCMOTOR_PRIV_H
#define  _DCMOTOR_PRIV_H

#define   STOP    0

#define   RIGHT    1

#define   LEFT    2

// STRUCTURE FOR DESCRIPTION THE DC-MOTOR

typedef struct
{
	u8 DCmotor_u8RightPort;
	u8 DCmotor_u8RightPin;
	
	u8 DCmotor_u8LeftPort;
	u8 DCmotor_u8LeftPin;

}DCmotor;

extern DCmotor ArraysOfMotors [ NUMBER_OF_MOTOR ];



#endif