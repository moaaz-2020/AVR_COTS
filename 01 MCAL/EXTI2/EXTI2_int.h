/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 05/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : EXTERNAL INTERRUPT (2)      */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _EXTI2_INT_H_
#define   _EXTI2_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE EXTERNAL */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuInit(void);

/************************************************/
/* THIS FUNCTION FOR ENABLING THE EXTERNAL      */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuEnable(void);


/************************************************/
/* THIS FUNCTION FOR DISABLING THE EXTERNAL     */
/*                INTERRUPT (2)                 */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   EXTI2_enuDisable(void);

/************************************************/
/* THIS FUNCTION FOR POINT TO THE INTERRUPT     */
/*                    FUNCTION                  */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    EXTI2_voidSetCallBack( void (*ptr)(void));

#endif