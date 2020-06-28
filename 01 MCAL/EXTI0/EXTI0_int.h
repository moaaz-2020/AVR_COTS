/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 05/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : EXTERNAL INTERRUPT (0)      */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _EXTI0_INT_H_
#define   _EXTI0_INT_H_


//       LOW      ==     1
//       IOC      ==     2
//       FALLING  ==     3
//       RISING   ==     4

/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (0)                 */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI0_enuInit(u8 Copy_u8SenseMode);

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (0)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI0_enuEnable(void);


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (0)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI0_enuDisable(void);

/************************************************/
/* THIS FUNCTION FOR POINT TO THE INTERRUPT     */
/*                    FUNCTION                  */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    EXTI0_voidSetCallBack( void (*ptr)(void));

#endif
