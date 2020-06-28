/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 24/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED TIMER(2)     */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _TIMER2_REG_H_
#define   _TIMER2_REG_H_

 
#define          TCCR2        *((volatile u8*)0x45)

#define          TIMSK        *((volatile u8*)0x59)

#define          TCNT2        *((volatile u8*)0x44)

#define          OCR2         *((volatile u8*)0x43)
// ASYNCHRONOUS STATUS REGISTER
#define          ASSR         *((volatile u8*)0x42)

#endif
