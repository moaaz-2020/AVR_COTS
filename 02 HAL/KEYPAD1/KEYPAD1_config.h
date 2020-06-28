/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 31/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : AVR KEYPAD CONFIGURATION   **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/


#ifndef  _KEYPAD_CONFIG_H_
#define  _KEYPAD_CONFIG_H_




/************************************************/
/*****      PINS CONFIGURATION                 **/
/************************************************/


/*****  ROWS   *******/
#define KEYPAD_D0_PIN     PIN0
#define KEYPAD_D0_PORT    PORTA

#define KEYPAD_D1_PIN     PIN1
#define KEYPAD_D1_PORT    PORTA

#define KEYPAD_D2_PIN     PIN2
#define KEYPAD_D2_PORT    PORTA

#define KEYPAD_D3_PIN     PIN3
#define KEYPAD_D3_PORT    PORTA

/******  COLUNMS  ****/

#define KEYPAD_D4_PIN     PIN0
#define KEYPAD_D4_PORT    PORTB

#define KEYPAD_D5_PIN     PIN1
#define KEYPAD_D5_PORT    PORTB

#define KEYPAD_D6_PIN     PIN2
#define KEYPAD_D6_PORT    PORTB

#define KEYPAD_D7_PIN     PIN3
#define KEYPAD_D7_PORT    PORTB

#define POS_SIGNAL 0
#define NEG_SIGNAL 1

#define NO_KEY_PRESSED  0xFF


#endif