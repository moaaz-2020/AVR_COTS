/************************************************/
/*****AUTHOR      : MOAAZ RASHAD SEWILAM    *****/
/*****Date        : 26/03/2020              *****/
/*****Version     : 1.0    V                *****/
/*****Description : AVR LCD                 *****/
/*****              REGISTER REPRESENTATION *****/
/************************************************/


/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef  _DIO_REG_H_
#define  _DIO_REG_H_
 
/********* Adresses for each register ***********/

/************************************************/
/*****            PORTA                     *****/
/************************************************/

#define  DIO_PU8_PORTA_REG   *((volatile u8 *)0x3B)
#define  DIO_PU8_DDRA_REG    *((volatile u8 *)0x3A)
#define  DIO_PU8_PINA_REG    *((volatile u8 *)0x39)

/************************************************/
/*****            PORTB                     *****/
/************************************************/

#define  DIO_PU8_PORTB_REG   *((volatile u8 *)0x38)
#define  DIO_PU8_DDRB_REG    *((volatile u8 *)0x37)
#define  DIO_PU8_PINB_REG    *((volatile u8 *)0x36)

/************************************************/
/*****            PORTC                     *****/
/************************************************/

#define  DIO_PU8_PORTC_REG   *((volatile u8 *)0x35)
#define  DIO_PU8_DDRC_REG    *((volatile u8 *)0x34)
#define  DIO_PU8_PINC_REG    *((volatile u8 *)0x33)

/************************************************/
/*****            PORTD                     *****/
/************************************************/

#define  DIO_PU8_PORTD_REG   *((volatile u8 *)0x32)
#define  DIO_PU8_DDRD_REG    *((volatile u8 *)0x31)
#define  DIO_PU8_PIND_REG    *((volatile u8 *)0x30)

#endif