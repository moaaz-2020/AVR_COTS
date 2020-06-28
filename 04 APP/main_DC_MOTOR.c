#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"

#include "DIO_int.h"

#include "DCmotor_config.h"
#include "DCmotor_priv.h"
#include "DCmotor_int.h"



int main()
{
	/* SET PIN DIRECTIONS */
	DIO_enumSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_enumSetPinDirection(PORTC,PIN1,OUTPUT);
	/* SET THE INITIALIZATION  POSITION FOR DC MOTOR*/
	DCmotor_int();

	while(1)
	{
		/* FOR MOTOR NO. 0 GO RIGHT */
		DCmotor_vidMove( 0 , RIGHT );
		_delay_ms(2000);
		/* FOR MOTOR NO. STOP */
		DCmotor_vidMove( 0 , STOP );
		_delay_ms(500);
		/* FOR MOTOR NO. 0 GO LEFT */
		DCmotor_vidMove( 0 , LEFT );
		_delay_ms(2000);
		/* FOR MOTOR NO. STOP */
		DCmotor_vidMove( 0 , STOP );
		_delay_ms(500);

	}

	return 0;
}