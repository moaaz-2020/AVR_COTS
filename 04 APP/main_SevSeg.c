#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "SevSeg_config.h"
#include "SevSeg_int.h"

int main()
{
    u8 SevSeg_u8Counter;
	SevSeg_vidInit();
	SevSeg_vidSetCommonPin();
	while(1)
	{
		for(SevSeg_u8Counter=0; SevSeg_u8Counter<=9 ; SevSeg_u8Counter++)
		{
			SevSeg_vidDisplayNumber(SevSeg_u8Counter);
			_delay_ms(200);
		}
	}
	return 0;
}