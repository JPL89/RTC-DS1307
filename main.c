/*
*	@File        MAIN.C	 		
*	@Author		JOSIMAR PEREIRA LEITE
*	@country	Brazil
*	@Date		24/10/2024
*
*	Copyright (C) 2024  JOSIMAR PEREIRA LEITE
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*/

#include "LM3S3xx.h"
#include "i2c.h"
#include "DS1307.h"

static DS1307_typedef DS1307;

int main (void)
{				
	I2C_init();

	DS1307.Rtc.Seconds = 55;
	DS1307.Rtc.Minutes = 22;
	DS1307.Rtc.Hours = 16;
	DS1307.Rtc.Day = 2;
	DS1307.Rtc.Date = 6;
	DS1307.Rtc.Month = 6;
	DS1307.Rtc.Year = 89;
	
	DS1307.Control.Bit.OUT = 1;
	DS1307.Control.Bit.SQWE = 1;
	
	DS1307_Update( &DS1307 );
	
	
	while (1)
	{		
	}
}

