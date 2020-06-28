#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "DIO_int.h"
#include "DIO_reg.h"

#include "LED_int.h"

int main(void)
{
	LED_enumSetLedPin(PORTA ,PIN0);
	LED_enumSetLedPin(PORTB ,PIN0);
	LED_enumSetLedPin(PORTC ,PIN0);
	while(1)
	{
		LED_enumSetLedOn(PORTA ,PIN0);
		LED_enumSetLedOff(PORTB ,PIN0);
		LED_enumSetLedTog(PORTC ,PIN0);
		_delay_ms(500);
		LED_enumSetLedOn(PORTB ,PIN0);
		LED_enumSetLedOff(PORTA ,PIN0);
		LED_enumSetLedTog(PORTC ,PIN0);
		_delay_ms(500);

	}
	return 0;
}
