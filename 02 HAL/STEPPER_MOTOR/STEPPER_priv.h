/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 03/04/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : AVR STEPPER MOTOR PRIVATE  **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef  _STEPPER_PRIV_H
#define  _STEPPER_PRIV_H

#define   STOP    0

#define   RIGHT    1

#define   LEFT    2

// STRUCTURE FOR DESCRIPTION THE DC-MOTOR

typedef struct
{
	/* BLUE MOTOR PORT SIMULATE BLUE WIRE FOR STEPPER MOTOR     */
	
	u8 BlueMotorPort;
	
	/* BLUE MOTOR PIN SIMULATE BLUE WIRE FOR STEPPER MOTOR     */
	
	u8 BlueMotorWire;

	/* PINK MOTOR PORT SIMULATE PINK WIRE FOR STEPPER MOTOR     */
    
	u8 PinkMotorPort;
	
	/* PINK MOTOR PIN SIMULATE PINK WIRE FOR STEPPER MOTOR     */
    
	u8 PinkMotorWire;
	
	/* YELLOW MOTOR Port SIMULATE YELLOW WIRE FOR STEPPER MOTOR */
	
	u8 YellowMotorPort;	
	
	/* YELLOW MOTOR PIN SIMULATE YELLOW WIRE FOR STEPPER MOTOR */
	
	u8 YellowMotorWire;
	
	/* ORANGE MOTOR PORT SIMULATE ORANGE WIRE FOR STEPPER MOTOR  */
    
	u8 OrangeMotorPort;	
	
	/* ORANGE MOTOR PIN SIMULATE ORANGE WIRE FOR STEPPER MOTOR  */
    
	u8 OrangeMotorWire;

}StepperMotor;

extern StepperMotor ArraysOfMotors [ NUMBER_OF_MOTORS ];



#endif