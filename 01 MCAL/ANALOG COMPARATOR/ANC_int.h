/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 29/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : ANALOG COMPARATOR FUNCTION  */
/*****                     PROTOTYPES           */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _ANC_INT_H_
#define   _ANC_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE ANALOG   */
/*                COMPARATOR                    */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ANC_enuInit(void);


/*****************************************************/
/* THIS FUNCTION FOR SELECT THE CHANNEL THE ANALOG   */
/*   TO DIGITAL CONVERTER WHEN CHOOSE ADC CHANNELS   */
/* INPUTS : UNSIGHNED CHARACTER                      */
/* RETURN : Error_enuStatus                          */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus   ANC_enuSelect(u8 Copy_u8ChannelId);

/************************************************/
/* THIS FUNCTION FOR POINT TO THE ANALOG        */
/*                 COMPARATOR  FUNCTION         */
/* INPUTS : POINTER TO FUNCTION                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void    ANC_vidComparatorCallBack( void (*Copy_ptr)(void));



#endif