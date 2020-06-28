
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

#include "DIO_reg.h"
#include "DIO_int.h"

#include "KEYPAD_int.h"

#include "LCD_int.h"

int main(void)
{
	u8 Local_u8Value = 0;
	KEYPAD_vidInit();
	LCD_enuInit();
	LCD_vidClearDisplay();

	while(1)
	{
		Local_u8Value = KEYPAD_u8GetPressedKeyPad();
		if(Local_u8Value != 0xFF)
		{
			LCD_enuSetCursor(5,1);
			LCD_enuSendData(Local_u8Value);
		}

	}
	return 0;
}
