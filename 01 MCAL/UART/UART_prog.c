/****************************************************/
/****AUTHOR       : Moaaz Rashad Sewilam            */
/****Date         : 21/04/2020                      */
/****Version      : 1.0  V                          */
/*****Description : UART/USART TANSIMIT FUNCTION    */
/*****                     IMPLEMENTATION           */
/****************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/

#include "UART_priv.h"

#include "UART_config.h"

#include "UART_int.h"

#include "UART_reg.h"


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION UART         */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidInit(void)
{	
    #if     SPEED_MODE     ==   NORMAL
		 CLR_BIT(UCSRA,U2X);
	     u16 UBRR_value = (u16)((F_CPU/(16L*BAUD_RATE))-1);
	#elif   SPEED_MODE     ==   DOUBLE
	     SET_BIT(UCSRA,U2X);
	     u16 UBRR_value = (u16)((F_CPU/(8L*BAUD_RATE))-1);
	#endif	 
	// Store the value of UBRR_value in UBRRL register
	UBRRL = (u8) UBRR_value;
	// Shifting the value of UBRR_value to the right and this value will become store in first two bit of UBRRL and the rest in UBRRH  
	UBRRH = (u8)(UBRR_value>>8);
	// Enabling of receiving and transmitting data  
	UCSRB = (1<<RXEN) | (1<<TXEN);
	// Activate th receiving 8 bit character 
	UCSRC |= ((1<<UCSZ0) | (1<<UCSZ1));
}

/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING CHARACTER    */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidSendChar(u8 UART_CopyData)
{
	// wait for the MCU is ready to send data this mean that the MCU wait for do not any reaction as long as this bit do not equal (1)
	while(!(UCSRA&(1<<UDRE)));
		UDR = UART_CopyData ;
}

/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING 9-BIT DATA   */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void USART_vidTransmitData(u32 Copy_u32Data )
{
    /* Wait for empty transmit buffer */
     while ( !( UCSRA & (1<<UDRE))) ;
     /* Copy 9th bit to TXB8 */
      UCSRB &= ~(1<<TXB8);
      if ( Copy_u32Data & 0x0100 )
	  {
         UCSRB |= (1<<TXB8);
	  }
     /* Put data into buffer, sends the data */
       UDR = Copy_u32Data;
}

/************************************************/
/* THIS FUNCTION FOR RECEIVING CHARACTER        */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8 UART_vidReceiveChar(void)
{
      // wait for the MCU is ready to receive data this mean that the MCU wait for do not any reaction as long as this bit do not equal (1)	
       while(!(UCSRA&(1<<RXC)));
		return UDR ;
}

/************************************************/
/* THIS FUNCTION FOR RECEIVING 9-BIT DATA       */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32 USART_vidReceiveData( void )
{
     u8 Local_u8Status, Local_u8Resh, Local_u8Resl;
         /* Wait for data to be received */
     while ( !(UCSRA & (1<<RXC)) );
         /* Get status and 9th bit, then data */
                  /* from buffer */
             Local_u8Status = UCSRA;
             Local_u8Resh = UCSRB;
             Local_u8Resl = UDR;
         /* If error, return -1 */
    if ( Local_u8Status & (1<<FE)|(1<<DOR)|(1<<PE) )
	{
        return -1;
	}
         /* Filter the 9th bit, then return */
           Local_u8Resh = (Local_u8Resh >> 1) & 0x01;
     return ((Local_u8Resh << 8) | Local_u8Resl);
}


/************************************************/
/* THIS FUNCTION FOR TRANSIMITTING STRING       */
/* INPUTS : UNSIGHNED CHARACTER POINTER         */
/*                  TO STRING                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidSendString(u8 Copy_u8PString[])
{
	u8  Local_u8Iteration = 0 ;
     while(Copy_u8PString[Local_u8Iteration] != '\0')
	 {		 
         UART_vidSendChar(Copy_u8PString[Local_u8Iteration]);
		 Local_u8Iteration++;
	 }
}

/************************************************/
/* THIS FUNCTION FOR RECEIVING STRING           */
/* INPUTS : UNSIGHNED CHARACTER POINTER         */
/*                  TO STRING                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void UART_vidReceiveString(u8 Copy_u8PString[])
{
	u8  Local_u8Current = 0;
	u8  Local_u8Counter = 0;
	while(1)
	{
		Local_u8Current = UART_vidReceiveChar();
		if(Local_u8Current = '\r')
		{
			Copy_u8PString[Local_u8Counter] = '\0';
			break;
		}
		Copy_u8PString[Local_u8Counter] = Local_u8Current;
		Local_u8Counter++;
	}

}