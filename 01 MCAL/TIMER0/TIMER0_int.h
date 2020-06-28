/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 10/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : TIMER (0)                   */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER0_INT_H_
#define   _TIMER0_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(0)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   TIMER0_enuInit(void);

/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(0) REGISTERS */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuSetTimerReg(u8 Copy_u8Value);


/************************************************/
/* THIS FUNCTION FOR GETTING TIMER(0) REGISTERS */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   TIMER0_enuGetTimerReg(void);

/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER (0)                     */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuSetCompareValue(u8 Copy_u8Value);


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (0)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuEnableOVInt(void);



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (0)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuDisableOVInt(void);


/************************************************/
/* THIS FUNCTION FOR ENABLING CTC MODE          */
/*            INTERRUPT FOR TIMER (0)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuEnableCTCInt(void);



/************************************************/
/* THIS FUNCTION FOR DISABLING CTC MODE         */
/*            INTERRUPT FOR TIMER (0)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER0_enuDisableCTCInt(void);


/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(0)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER0_vidSetOVCallBack( void (*Copy_ptr)(void));


/************************************************/
/* THIS FUNCTION FOR POINT TO THE CTC MODE      */
/*                 TIMER(0)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER0_vidSetCTCCallBack( void (*Copy_ptr)(void));

#endif