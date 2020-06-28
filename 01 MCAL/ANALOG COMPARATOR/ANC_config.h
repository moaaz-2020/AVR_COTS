/***************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam           */
/*****Date        : 29/04/2020                     */
/*****Version     : 1.0  V                         */
/*****Description : CONFIGURATION FOR ANALOG       */ 
/*****                      COMPARATOR             */
/***************************************************/

/***************************************************/
/*****gaurd of file will call one time in .c********/
/***************************************************/



#ifndef   _ANC_CONFIG_H_
#define   _ANC_CONFIG_H_



#define    ANC_MULTIPLEXER                ENABLE_ANC_MUX

#define    ANC_INTERRUPT_MODE_SELECT      ANC_FALLING

#define    ANC_INPUT_CAPTURE              DISABLE_ANC_ICU

#define    ANC_INTERRUPT                  DISABLE_ANC_INT

#define    ANC_BANDGAP_SELECT             DISABLE_ANC_BANDGAP

#define    ANC_DISABLE                    DISABLE_ANC



#endif