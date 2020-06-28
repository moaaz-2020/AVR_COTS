/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 21/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED UART/USART   */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _UART_REG_H_
#define   _UART_REG_H_

 
#define          UDR           *((volatile u8*)0x2C)

#define          UCSRA         *((volatile u8*)0x2B)

#define          UCSRB         *((volatile u8*)0x2A)

#define          UBRRL         *((volatile u8*)0x29)

#define          UBRRH         *((volatile u8*)0x40)

#define          UCSRC           UBRRH         

#endif
