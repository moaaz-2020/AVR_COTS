/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 10/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED TIMER(0)     */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER0_REG_H_
#define   _TIMER0_REG_H_

 
#define          TCCR0        *((volatile u8*)0x53)

#define          TIMSK        *((volatile u8*)0x59)

#define          TCNT0        *((volatile u8*)0x52)

#define          OCR0         *((volatile u8*)0x5C)


#endif
