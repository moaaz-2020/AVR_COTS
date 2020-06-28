/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 10/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : UART/USART                  */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _UART_INT_H_
#define   _UART_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION UART         */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidInit(void);

/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING CHARACTER    */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidSendChar(u8 UART_CopyData);


/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING 9-BIT DATA   */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void USART_vidTransmitData(u32 Copy_u32Data );


/************************************************/
/* THIS FUNCTION FOR RECEIVING CHARACTER        */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8 UART_vidReceiveChar(void);

/************************************************/
/* THIS FUNCTION FOR RECEIVING 9-BIT DATA       */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32 USART_vidReceiveData( void );


/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING STRING       */
/* INPUTS : UNSIGHNED CHARACTER POINTER         */
/*                  TO STRING                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidSendString(u8 Copy_u8PString[]);


/************************************************/
/* THIS FUNCTION FOR RECEIVING STRING           */
/* INPUTS : UNSIGHNED CHARACTER POINTER         */
/*                  TO STRING                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidReceiveString(u8 Copy_u8PString[]);

#endif