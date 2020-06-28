/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 29/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : REGISTERS USED IN ANALOG    */
/*****                   COMPARATOR             */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _ANC_REG_H_
#define   _ANC_REG_H_

 
#define   ADMUX     *((volatile u8 *)0x27)


#define   ADCSRA    *((volatile u8 *)0x26)


#define   SFIOR     *((volatile u8 *)0x50)

#define   ACSR      *((volatile u8 *)0x28)


#endif
