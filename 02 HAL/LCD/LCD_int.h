/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 28/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : LCD FUNCTION Prototypes    **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef   _LCD_INT_H_
#define   _LCD_INT_H_
 
 
/************************************************/
/*    THIS FUNCTION USED TO LCD INITIALIZATION  */
/*    INPUTS : VOID                             */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/
   
Error_enuStatus  LCD_enuInit(void);  

/************************************************/
/*    THIS FUNCTION USED TO LCD SEND COMMAND    */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/ 


Error_enuStatus  LCD_enuSendCmd(u8 Copy_u8Cmd);

/************************************************/
/*    THIS FUNCTION USED TO LCD SEND DATA       */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/ 


Error_enuStatus  LCD_enuSendData(u8 Copy_u8Data);

/************************************************/
/*    THIS FUNCTION USED TO LCD SEND STRING     */
/*    INPUTS : POINTER TO UNSIGHNED INTEGER     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/ 


Error_enuStatus  LCD_enuSendString(s8* Copy_Ps8Data);

/************************************************/
/*    THIS FUNCTION USED TO LCD CLEAR DISPLAY   */
/*    INPUTS : VOID                             */
/*    RETURN : VOID                             */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/ 

void         LCD_vidClearDisplay(void);

/************************************************/
/*    THIS FUNCTION USED TO LCD SET CURSOR      */
/*    INPUTS : UNSIGHNED INTEGER,               */  
/*                    UNSIGHNED INTEGER         */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/ 


Error_enuStatus  LCD_enuSetCursor(u8 Copy_u8Column , u8 Copy_u8Row );


/************************************************/
/*    THIS FUNCTION USED TO LCD PRINT           */
/*    INPUTS : 2 UNSIGHNED INTEGERS & POINTER   */
/*                TO UNSIGHNED INTEGER          */
/*    RETURN : VOID                             */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/


void        LCD_vidPrint(u8 copy_u8Column,u8 copy_u8Row,s8* copy_Ps8Data);


/************************************************/
/*    THIS FUNCTION USED TO LCD CONVERT NUMBER  */
/*             TO STRING                        */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : VOID                             */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

		
void  LCD_Pu8NumberToString(u32 Copy_u32Var);


/************************************************/
/*    THIS FUNCTION USED TO CALCULATE POWER OF  */
/*             NUMBER                           */
/*    INPUTS :UNSIGHNED CHAR & UNSIGHNED INTEGER*/
/*    RETURN :UNSIGHNED INTEGER                 */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

u32   POWER_u32PowerNumbers(u32 Copy_u32Number,u8 Copy_u8Power);

/************************************************/
/*    THIS FUNCTION USED TO WRITE A STRING IN A */
/*             SINE WAVE                        */
/*    INPUTS :UNSIGHNED CHAR POINTER TO ARRAY   */
/*    RETURN :VOID                              */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

void LCD_vidSineWaveWriteStr(u8 *Copy_PAu8String);

#endif 