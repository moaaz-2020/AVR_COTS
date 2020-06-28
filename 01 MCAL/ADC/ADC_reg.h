/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 06/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED IN ADC       */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _ADC_REG_H_
#define   _ADC_REG_H_

 
#define   ADMUX    *((volatile u8 *)0x27)


#define   ADCSRA   *((volatile u8 *)0x26)


#define   ADCH     *((volatile u8 *)0x25)


#endif
