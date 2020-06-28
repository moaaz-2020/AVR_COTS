/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 31/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : KEYPAD FUNCTION Prototypes **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef   _KEYPAD_INT_H_
#define   _KEYPAD_INT_H_




/************************************************/
/* THIS FUNCTION FOR INITIALIZATION KEYPAD      */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void      KEYPAD_vidInit(void);

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION KEYPAD      */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8       KEYPAD_u8GetPressedKeyPad(void);



#endif
