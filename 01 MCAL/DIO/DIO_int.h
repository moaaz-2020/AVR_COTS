/************************************************/
/*****AUTHOR      : MOAAZ RASHAD SEWILAM ********/
/*****Date        : 26/03/2020           ********/
/*****Version     : 1.0     V            ********/
/*****Description : AVR DIO INTERFACES   ********/
/************************************************/


/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/   

#ifndef _DIO_INT_h_   
#define _DIO_INT_h_


/************************************************/
/*****  REPRESENTATIONS OF PORT REGISTERS *******/
/************************************************/

#define  PORTA    0
#define  PORTB    1
#define  PORTC    2
#define  PORTD    3

/************************************************/
/*****  REPRESENTATIONS OF PIN REGISTERS  *******/
/************************************************/

#define  PIN0     0
#define  PIN1     1
#define  PIN2     2
#define  PIN3     3
#define  PIN4     4
#define  PIN5     5
#define  PIN6     6
#define  PIN7     7

/************************************************/
/*****      REPRESENTATIONS OF CASES      *******/
/************************************************/

#define  OUTPUT   1
#define  INPUT    0 

#define  HIGH     1
#define  LOW      0
  
/************************************************/
/*    THIS FUNCTION USED TO SET PIN DIRECTION   */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*            AND UNSIGHNED INT                 */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        DIO_enumSetPinDirection(u8 Copy_u8PortId ,u8 Copy_u8PinId,u8 Copy_u8Direction);

/************************************************/
/*    THIS FUNCTION USED TO SET PIN VALUE       */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*            AND UNSIGHNED INT                 */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/
 
Error_enuStatus        DIO_enumSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId,u8 Copy_u8Value);

/************************************************/
/*    THIS FUNCTION USED TO GET PIN VALUE       */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8                     DIO_enumGetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId);

/************************************************/
/*    THIS FUNCTION USED TO SET PORT DIRECTION  */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/
  
Error_enuStatus        DIO_enumSetPortDirection(u8 Copy_u8PortId ,u8 Copy_u8Direction); 

/************************************************/
/*    THIS FUNCTION USED TO SET PORT VALUE      */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        DIO_enumSetPortValue(u8 Copy_u8PortId ,u8 Copy_u8Value);

#endif