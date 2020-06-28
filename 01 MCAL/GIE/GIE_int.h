/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 05/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : GLOBAL INTERRUPT ENABLE(GIE)*/
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _GIE_INT_H_
#define   _GIE_INT_H_


/************************************************/
/* THIS FUNCTION FOR ENABLING THE GIE           */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void   GIE_enuEnable(void);

/************************************************/
/* THIS FUNCTION FOR DISABLE THE GIE            */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    GIE_enuDisable(void);




#endif