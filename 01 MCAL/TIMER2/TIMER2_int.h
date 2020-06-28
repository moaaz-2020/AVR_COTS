/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 24/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : TIMER (2)                   */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER2_INT_H_
#define   _TIMER2_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION TIMER(2)     */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   TIMER2_enuInit(void);

/************************************************/
/* THIS FUNCTION FOR SETTING TIMER(2) REGISTERS */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuSetTimerReg(u8 Copy_u8Value);


/************************************************/
/* THIS FUNCTION FOR GETTING TIMER(2) REGISTERS */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   TIMER2_enuGetTimerReg(void);

/************************************************/
/* THIS FUNCTION FOR SETTING THE COMPARE VALUE  */
/*            FOR TIMER (2)                     */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuSetCompareValue(u8 Copy_u8Value);


/************************************************/
/* THIS FUNCTION FOR ENABLING OVER-FLOW         */
/*          INTERRUOT  FOR TIMER (2)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuEnableOVInt(void);



/************************************************/
/* THIS FUNCTION FOR DISABLING OVER-FLOW        */
/*           INTERRUPT FOR TIMER (2)            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuDisableOVInt(void);


/************************************************/
/* THIS FUNCTION FOR ENABLING CTC MODE          */
/*            INTERRUPT FOR TIMER (2)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuEnableCTCInt(void);



/************************************************/
/* THIS FUNCTION FOR DISABLING CTC MODE         */
/*            INTERRUPT FOR TIMER (2)           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   TIMER2_enuDisableCTCInt(void);


/************************************************/
/* THIS FUNCTION FOR POINT TO THE OVER-FLOW     */
/*                 TIMER(2)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER2_vidSetOVCallBack( void (*Copy_ptr)(void));


/************************************************/
/* THIS FUNCTION FOR POINT TO THE CTC MODE      */
/*                 TIMER(2)  FUNCTION           */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    TIMER2_vidSetCTCCallBack( void (*Copy_ptr)(void));

#endif