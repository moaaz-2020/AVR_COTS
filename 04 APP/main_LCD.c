
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "DIO_int.h"

#include "LCD_int.h"


int main(void)
{
	
    
	LCD_enuInit();

    LCD_enuSendData('M');	
	LCD_enuSendData('O');	
	LCD_enuSendData('A');	
	LCD_enuSendData('A');	
	LCD_enuSendData('Z');	
	
	while(1)
	{
		
		
	}
	return 0;
}