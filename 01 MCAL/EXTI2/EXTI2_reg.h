/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 05/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED INTERRUPT(2) */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _EXTI2_REG_H_
#define   _EXTI2_REG_H_

 
#define     GICR         *((volatile u8 *)0x5B) 

#define     GIFR         *((volatile u8 *)0x5A) 

#define     MCUCR        *((volatile u8 *)0x55) 

#define     MCUCSR       *((volatile u8 *)0x54) 


#endif
