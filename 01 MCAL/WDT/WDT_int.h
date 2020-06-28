/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 15/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : WATCH DOG TIMER(WDT)        */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _WDT_INT_H_
#define   _WDT_INT_H_


/************************************************/
/***** TIMER PRESCALER AT VCC = 5.0 Volt  *******/
/************************************************/


#define   TIMER_PRESCALING_16.30_MS        0   
#define   TIMER_PRESCALING_32.50_MS        1
#define   TIMER_PRESCALING_65.00_MS        2
#define   TIMER_PRESCALING_0.13_SEC        3
#define   TIMER_PRESCALING_0.26_SEC        4
#define   TIMER_PRESCALING_0.52_SEC        5
#define   TIMER_PRESCALING_1.00_SEC        6
#define   TIMER_PRESCALING_2.10_SEC        7


/************************************************/
/* THIS FUNCTION FOR ENABLING THE WDT           */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   WDT_enuEnable(u8 Copy_u8TimerPrescaling);

/************************************************/
/* THIS FUNCTION FOR DISABLE THE WDT            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   WDT_enuDisable(void);




#endif