/*****AUTHOR      : Moaaz Rashad Sewilam           */
/*****Date        : 06/04/2020                     */
/*****Version     : 1.0  V                         */
/*****Description : PRIVATE FOR TIMER(0)           */
/***************************************************/

/***************************************************/
/*****gaurd of file will call one time in .c********/
/***************************************************/



#ifndef   _TIMER0_PRIV_H_
#define   _TIMER0_PRIV_H_



#define          DISABLE_FOC0             0
#define          ENABLE_FOC0              1

#define          NORMAL                   2
#define          PWM_PHASE_CORRECT        3
#define          CTC                      4
#define          FAST_PWM                 5

#define          NORMAL_PORT_OPERATION    6
#define          RSERVED                  7
#define          CLEAR_OC0                8
#define          SET_OC0                  9
#define          TOGGLE_OC0               10

#define          NO_CLOCK_SOURCE          11
#define          NO_PRESCALING            12
#define          PRESCALER_8              13
#define          PRESCALER_64             14
#define          PRESCALER_256            15
#define          PRESCALER_1024           16
#define          EXT_CLK_T0_FALLING_EDGE  17
#define          EXT_CLK_T0_RISING_EDGE   18

#endif
