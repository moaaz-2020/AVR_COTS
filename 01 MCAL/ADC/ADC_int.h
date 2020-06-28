/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 06/04/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : ANALOG TO DIGITAL CONVERTER */
/*****                    FUNCTION PROTOTYPES   */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _ADC_INT_H_
#define   _ADC_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZTION THE ANALOG   */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ADC_enuInit(void);


/*****************************************************/
/* THIS FUNCTION FOR SELECT THE CHANNEL THE ANALOG   */
/*                TO DIGITAL CONVERTER               */
/* INPUTS : UNSIGHNED CHARACTER                      */
/* RETURN : Error_enuStatus                          */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus   ADC_enuSelect(u8 Copy_u8ChannelId);

/************************************************/
/* THIS FUNCTION FOR ENABLING THE ANALOG        */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : Error_enuStatus                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus   ADC_enuEnable(void);

/************************************************/
/* THIS FUNCTION FOR START CONVERSION BY ANALOG */
/*                TO DIGITAL CONVERTER          */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED SHORT INTEGER             */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u16   ADC_u16StartConversion(void);


#endif