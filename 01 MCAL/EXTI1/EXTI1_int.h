/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 05/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : EXTERNAL INTERRUPT (1)      */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _EXTI1_INT_H_
#define   _EXTI1_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuInit(void);

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuEnable(void);


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (1)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI1_enuDisable(void);

/************************************************/
/* THIS FUNCTION FOR POINT TO THE INTERRUPT     */
/*                    FUNCTION                  */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    EXTI1_voidSetCallBack( void (*ptr)(void));

#endif