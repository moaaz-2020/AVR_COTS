#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "DIO_int.h"

int main()
{
	DIO_enumSetPinDirection(PORTA ,PIN0,OUTPUT);
	while(1)
	{
		DIO_enumSetPinValue(PORTA ,PIN0,HIGH);
	   _delay_ms(100);
	   DIO_enumSetPinValue(PORTA ,PIN0,LOW);
	   _delay_ms(100);
	}
}

