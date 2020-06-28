/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 28/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : LCD FUNCTION IMPLEMENTATION**/
/************************************************/

/************************************************/
/**********  STANDARD LIB DIRECTIVES ************/
/************************************************/

#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

/************************************************/
/********** COMPONENTS DIRECTIVES    ************/
/************************************************/
#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_int.h"
#include "LCD_priv.h"
#include "LCD_config.h"

/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/



/************************************************/
/*    THIS FUNCTION USED TO LCD INITIALIZATION  */
/*    INPUTS : VOID                             */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/


Error_enuStatus  LCD_enuInit(void)
{
	DIO_enumSetPinDirection( RS_PORT , RS_PIN , OUTPUT );
	DIO_enumSetPinDirection( RW_PORT , RW_PIN , OUTPUT );
	DIO_enumSetPinDirection( EN_PORT , EN_PIN , OUTPUT );
	
	 DIO_enumSetPinDirection(LCD_D0_PORT,LCD_D0_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D1_PORT,LCD_D1_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D2_PORT,LCD_D2_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D3_PORT,LCD_D3_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
     DIO_enumSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	
	Error_enuStatus Local_enuError = ES_NOK;
	//#if    LCD_MODE    == 8-BITS
	/************************************************/
    /*     FUNCTION SET :                           */
    /*     DL  =  1  8-BIT MODE                     */
    /*     N   =  1  2-LINES                        */
	/*     F   =  0  5 *7                           */
    /************************************************/
	  LCD_enuSendCmd(0X38);
	  _delay_ms(1);
	/************************************************/
    /*     DISPLAY ON :                             */
    /*     D  =  1  FOR DISPLAY ON                  */
    /*     C   =  0 FOR CURSOR OFF                  */
	/*     B   =  0  BLINKING OFFF                  */
    /************************************************/
	  LCD_enuSendCmd(0X0C);
	  _delay_ms(1);
	/************************************************/
    /*    CLEAR DISPLAY  :                          */
    /************************************************/ 
	  LCD_enuSendCmd(0X01);
	  _delay_ms(2);
	/************************************************/
    /*     ENTRY MODE :                             */
    /*     ID  = 1                                  */
    /*     SH  = 0                                  */
    /************************************************/ 
	   LCD_enuSendCmd(0X06);
	  _delay_ms(1);
	  Local_enuError = ES_OK;
	/*#elif LCD_MODE     == 4-BITS
	
	  Local_enuError = ES_OK;
	#else 
		#error "WRONG LCD MODE"
	
	#endif */
	return Local_enuError;
}   


/************************************************/
/*    THIS FUNCTION USED TO LCD SEND COMMAND    */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

Error_enuStatus  LCD_enuSendCmd(u8 Copy_u8Cmd)
{
       Error_enuStatus  Local_enuError = ES_NOK;
	   
	//#if LCD_MODE    == 8-BITS
	     /******* RS= 0 TO SELECT COMMAND REGISTER ********/
	   DIO_enumSetPinValue(RS_PORT /* PORTA*/ ,RS_PIN /* PIN0 = A0*/, LOW);
	     /******* RW= 0 TO SELECT WRITE DATA ********/
	   DIO_enumSetPinValue(RW_PORT /* PORTA*/ ,RW_PIN /* PIN0 = A0*/, LOW);
	  // DIO_enumSetPortValue( LCD_CONTROL , Copy_u8Cmd);
	   
       LCD_enuLatch(Copy_u8Cmd);
	   
	   Local_enuError = ES_OK;
    /* #elif LCD_MODE     == 4-BITS
	
	  Local_enuError = ES_OK;
	#else 
		#error "WRONG LCD MODE"
	
	#endif */
	return Local_enuError;
}


/************************************************/
/*    THIS FUNCTION USED TO LCD SEND DATA       */
/*    INPUTS : UNSUGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

Error_enuStatus  LCD_enuSendData(u8 Copy_u8Data)
{
	   Error_enuStatus  Local_enuError = ES_NOK;
	   
	   // #if LCD_MODE    == 8-BITS
	   /******* RS= 0 TO SELECT DATA REGISTER ********/
	   DIO_enumSetPinValue(RS_PORT /* PORTA*/ ,RS_PIN /* PIN0 = A0*/, HIGH);
	   /******* RW= 0 TO SELECT WRITE  DATA ********/
	   DIO_enumSetPinValue(RW_PORT /* PORTA*/ ,RW_PIN /* PIN0 = A0*/, LOW);
	   //DIO_enumSetPortValue( LCD_DATA , Copy_u8Data);
	   
	   LCD_enuLatch(Copy_u8Data); 
	   
	   Local_enuError = ES_OK;
	   
	   /* #elif LCD_DATA    == 4-BITS
	   
	   Local_enuError = ES_OK;
	   #else
		   #error "WRONG LCD MODE"
	   #endif */
	   return Local_enuError;
}


/************************************************/
/*    THIS FUNCTION USED TO LCD LATCH           */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

static Error_enuStatus LCD_enuLatch(u8 Copy_u8Cmd)
{
	//#if LCD_MODE    ==  8-BITS
	   DIO_enumSetPortValue(LCD_PORT , Copy_u8Cmd);
	   /***************** SET PIN ENABLE BY NEGATIVE EDGE TRIGGER ***************/
       DIO_enumSetPinValue(EN_PORT /* PORTA*/ ,EN_PIN /* PIN0 = A0*/, HIGH);
	   _delay_ms(2);
	   DIO_enumSetPinValue(EN_PORT /* PORTA*/ ,EN_PIN /* PIN0 = A0*/, LOW);
	   _delay_ms(2);
	   return ES_OK;
	/*#elif LCD_MODE    ==  4-BITS
       return ES_OK;  
    #else
          #error "WRONG LCD MODE"	
    #endif */
}


/************************************************/
/*    THIS FUNCTION USED TO LCD SEND STRING     */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

Error_enuStatus  LCD_enuSendString(s8* Copy_Ps8Data)
{
      	Error_enuStatus  Local_enuError = ES_NOK;
		while(* Copy_Ps8Data != '\0')
		{
             LCD_enuSendData(* Copy_Ps8Data);
				Copy_Ps8Data++;
				Local_enuError = ES_OK;			
		}
		return Local_enuError;
}


/************************************************/
/*    THIS FUNCTION USED TO LCD CLEAR           */
/*    INPUTS : VOID                             */
/*    RETURN : VOID                             */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

void         LCD_vidClearDisplay(void)
{
	LCD_enuSendCmd(0X01);
}


/************************************************/
/*    THIS FUNCTION USED TO LCD SET CURSOR      */
/*    INPUTS : 2 UNSIGHNED INTEGERS             */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

Error_enuStatus  LCD_enuSetCursor(u8 Copy_u8Column , u8 Copy_u8Row )
{
	Error_enuStatus  Local_enuError = ES_NOK;
	    if((Copy_u8Column<16)&&(Copy_u8Row<3))
		{
			Local_enuError = ES_OK;
			/*****      (0x80) forced the cursor to the begining of 1st line    *****/
			if(1== Copy_u8Row){LCD_enuSendCmd((0x80)+Copy_u8Column);}
			/*****      (0xC0) forced the cursor to the begining of 2nd line    *****/
			if(2== Copy_u8Row){LCD_enuSendCmd((0xC0)+Copy_u8Column);}
		}
		else
		{ Local_enuError = ES_NOK;}
	
		return Local_enuError;
}


/************************************************/
/*    THIS FUNCTION USED TO LCD PRINT           */
/*    INPUTS : 2 UNSIGHNED INTEGERS & POINTER   */
/*                TO UNSIGHNED INTEGER          */
/*    RETURN : VOID                             */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

void        LCD_vidPrint(u8 Copy_u8Column,u8 Copy_u8Row,s8* Copy_Ps8Data)
{ 
	        LCD_enuSetCursor(Copy_u8Column,Copy_u8Row);
	        LCD_enuSendString(Copy_Ps8Data);
}

		
/************************************************/
/*    THIS FUNCTION USED TO LCD CONVERT NUMBER  */
/*             TO STRING                        */
/*    INPUTS : UNSIGHNED INTEGER                */
/*    RETURN : VOID                             */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/
		
void  LCD_Pu8NumberToString(u32 Copy_u32Var) // 123
{
	s8 Local_s8Iteration ;
	u8 Local_u8NumOfDigits = 0;
	u32 Local_u32Reminder , Local_u32PowerTen ;
	Local_u32Reminder = Copy_u32Var ;

	for(Local_s8Iteration = 1 ; ; Local_s8Iteration++)
	{
		Copy_u32Var = Local_u32Reminder ;
		Local_u32PowerTen = POWER_u32PowerNumbers(10, Local_s8Iteration);
		Copy_u32Var /= Local_u32PowerTen ;
		if(Copy_u32Var == 0)
		{
			Local_u8NumOfDigits = Local_s8Iteration - 1 ;
			break;
		}
	}
	for(Local_s8Iteration = Local_u8NumOfDigits ; Local_s8Iteration >= 0 ; Local_s8Iteration--)
	{
		Copy_u32Var = Local_u32Reminder ;
		Local_u32PowerTen = POWER_u32PowerNumbers(10,Local_s8Iteration);
		Local_u32Reminder %= (Local_u32PowerTen) ;
		Copy_u32Var /= (Local_u32PowerTen) ;
		LCD_enuSendData((Copy_u32Var) + 48);
	}
}

/************************************************/
/*    THIS FUNCTION USED TO CALCULATE POWER OF  */
/*             NUMBER                           */
/*    INPUTS :UNSIGHNED CHAR & UNSIGHNED INTEGER*/
/*    RETURN :UNSIGHNED INTEGER                 */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/

u32   POWER_u32PowerNumbers(u32 Copy_u32Number,u8 Copy_u8Power)
{
	u32 Local_u32Increment;
	u32 Local_u32Value = 1;
	for(Local_u32Increment = 1 ; Local_u32Increment <= Copy_u8Power ; Local_u32Increment++)
	{
		Local_u32Value *= Copy_u32Number;
	}
	return Local_u32Value;
}


/************************************************/
/*    THIS FUNCTION USED TO WRITE STRING IN     */
/*             SINE WAVE                        */
/*    INPUTS :UNSIGHNED CHAR POINTER TO ARRAY   */
/*    RETURN :VOID                 */
/************************************************/
/*    PRE_CONDITION :                           */
/*                                              */
/************************************************/
void LCD_vidSineWaveWriteStr(u8 *Copy_PAu8String)
{
	u8 Local_u8Index = 0 , Local_u8Flag = 0;// Counter of count num char in the string
	while( Copy_PAu8String[Local_u8Index] )
	{
		if( !Local_u8Flag )
		{
			/* 0x80 for line-1 */
			LCD_enuSendCmd(0x80 + Local_u8Index );
			Local_u8Flag = 1;
		}
		else if(Local_u8Flag)
		{
			/* 0xC0 for line-1 */
			LCD_enuSendCmd(0xC0 + Local_u8Index );
			Local_u8Flag = 0;
		}
		while( Copy_PAu8String[Local_u8Index] != ' ' )
		{
			LCD_enuSendData(Copy_PAu8String[Local_u8Index]);
			Local_u8Index++;
			_delay_ms(5);
		}
		Local_u8Index++;
	}
}
