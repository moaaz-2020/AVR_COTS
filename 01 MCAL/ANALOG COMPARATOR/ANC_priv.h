/***************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam           */
/*****Date        : 29/04/2020                     */
/*****Version     : 1.0  V                         */
/*****Description : PRIVATE FOR ANALOG COMPARATOR  */
/***************************************************/

/***************************************************/
/*****gaurd of file will call one time in .c********/
/***************************************************/



#ifndef   _ANC_PRIV_H_
#define   _ANC_PRIV_H_



#define           ENABLE_ANC_MUX       1

#define           ANC_TOGGLE           2
#define           ANC_RESERVED         3
#define           ANC_FALLING          4
#define           ANC_RISING           5

#define           ENABLE_ANC_ICU       6
#define           DISABLE_ANC_ICU      7

#define           ENABLE_ANC_INT       8
#define           DISABLE_ANC_INT      9

#define           ENABLE_ANC_BANDGAP   10
#define           DISABLE_ANC_BANDGAP  11

#define           ENABLE_ANC           12
#define           DISABLE_ANC          13

#define           AC0                  5

#endif
