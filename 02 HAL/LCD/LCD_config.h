/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 28/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : AVR LCD CONFIGURATION      **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/


#ifndef  _LCD_CONFIG_H
#define  _LCD_CONFIG_H


/************************************************/
/*****        LCD MODE MAY BE :             *****/
/*                            1- 8-BIT      *****/
/*                            2- 4-BIT      *****/
/************************************************/

#define   LCD_MODE      8-BITS


#define   LCD_PORT      PORTD


/************************************************/
/*****      SET CONFIGURATION FOR  DATA PORTS  **/
/*****           RS , RW AND EN                **/
/************************************************/


#define LCD_D0_PIN     PIN0
#define LCD_D0_PORT    PORTD

#define LCD_D1_PIN     PIN1
#define LCD_D1_PORT    PORTD

#define LCD_D2_PIN     PIN2
#define LCD_D2_PORT    PORTD

#define LCD_D3_PIN     PIN3
#define LCD_D3_PORT    PORTD

#define LCD_D4_PIN     PIN4
#define LCD_D4_PORT    PORTD

#define LCD_D5_PIN     PIN5
#define LCD_D5_PORT    PORTD

#define LCD_D6_PIN     PIN6
#define LCD_D6_PORT    PORTD

#define LCD_D7_PIN     PIN7
#define LCD_D7_PORT    PORTD

#define   RS_PORT       PORTC
#define   RS_PIN        PIN0
#define   RW_PORT       PORTC
#define   RW_PIN        PIN1
#define   EN_PORT       PORTC
#define   EN_PIN        PIN2


#endif