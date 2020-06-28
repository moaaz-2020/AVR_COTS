/*****AUTHOR      : Moaaz Rashad Sewilam           */
/*****Date        : 06/04/2020                     */
/*****Version     : 1.0  V                         */
/*****Description : PRIVATE FOR UART/USART         */
/***************************************************/

/***************************************************/
/*****gaurd of file will call one time in .c********/
/***************************************************/



#ifndef   _UART_PRIV_H_
#define   _UART_PRIV_H_

#define        NORMAL         22
#define        DOUBLE         23

/*********** UCSRA ****************/
// MULTI PROCESSOR COMMUNICATION MODE
#define        MPCM           0 
// DOUBLE THE USART TRANSMITTING SPEED
#define        U2X            1
// PARITY ERROR 
#define        PE             2
// DATA OVER RUN 
#define        DOR            3 
// FRAME ERROR
#define        FE             4 
// USART DATA REGISTER EMPTY
#define        UDRE           5 
// USART TRANSMIT COMPLETE
#define        TXC            6 
// USART RECEIVE COMPLETE
#define        RXC            7 

/************ UCSRB ****************/
// TRANSMIT DATA BIT 8
#define        TXB8           0
// RECEIVE DATA BIT 8
#define        RXB8           1
// CHARACTER SIZE
#define        UCSZ2          2
// TRANSMITER ENABLE
#define        TXEN           3
// RECEIVER ENABLE
#define        RXEN           4
// USART DATA REGISTER EMPTY INTERRUPT ENABLE
#define        UDRIE          5
// TX COMPLETE INTERRUPT ENABLE
#define        TXCIE          6
// RX COMPLETE INTERRUPT ENABLE
#define        RXCIE          7
/************ UCSRC ****************/
// CLOCK POLARITY
#define        UCPOL          0
// ChARACTER SIZE
#define        UCSZ0          1
// ChARACTER SIZE
#define        UCSZ1          2
// USART STOP BIT SELECT
#define        USBS           3
// USART PARITY MODE 
#define        UPM0           4
// USART PARITY MODE 
#define        UPM1           5
// USART MODE SELECT
#define        UMSEL          6
// USART REGISTER SELECT
#define        URSEL          7


#endif
