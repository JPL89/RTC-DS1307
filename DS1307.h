/*
*	@File       DS1307.H	 		
*	@Author		JOSIMAR PEREIRA LEITE
*	@country	Brazil
*	@Date		27/10/2024
*
*	Copyright (C) 2024  JOSIMAR PEREIRA LEITE
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*/
#ifndef DS1307_H
#define DS1307_H

/*
*	CONTROL REGISTER
*	The DS1307 control register is used to control the operation of the SQW/OUT pin.
*
*	 ---------------------------------------------------------
*	|  OUT  |  -  |  -  |  SQWE  |  -  |  -  |  RS1  |  RS0  |
*	---------------------------------------------------------
*
*	 ------------------------------------
*	|  RS1  |  RS0  |  OUTPUT FREQUENCY |
*	------------------------------------
*	|   0   |   0  |    1 HZ            | 
*	------------------------------------
*	|   0   |   1  |    4.096kHz        | 
*	------------------------------------
*	|   1   |   0  |    8.192kHz        | 
*	------------------------------------
*	|   1   |   1  |    32.768KHZ       | 
*	------------------------------------
*
*/

typedef struct
{
/*
*	RTC AND RAM ADDRESS MAP
*	The address map for the RTC and RAM registers of the DS1307
*	The RTC registers
*	are located in address locations 00h to 07h. 
*	The RAM registers are located in address locations 08h to
*	3Fh. During a multi-byte access, when the address pointer reaches 3Fh, 
*	the end of RAM space, it wraps
*	around to location 00h, the beginning of the clock space.
*/
	struct
	{
		/* ADDRESS 0x00 */
		unsigned char Seconds;
		
		/* ADDRESS 0x01 */
		unsigned char Minutes;
		
		/* ADDRESS 0x02 */
		unsigned char Hours;
		
		/* ADDRESS 0x03 */
		unsigned char Day;
		
		/* ADDRESS 0x04 */
		unsigned char Date;
		
		/* ADDRESS 0x05 */
		unsigned char Month;
		
		/* ADDRESS 0x06 */
		unsigned char Year;
	}
	Rtc;

	union
	{
		unsigned char raw;
		
		struct
		{
			/* CCONTROL 0x01 */
			unsigned char RS0:1;
			
			/* CCONTROL 0x02 */
			unsigned char RS1:1;
			
			/* CONTROL 0x04 */
			unsigned char Reserved0:1;
			
			/* CONTROL 0x08 */
			unsigned char Reserved1:1;
			
			/* CONTROL 0x10 */
			unsigned char SQWE:1;
			
			/* CONTROL 0x20 */
			unsigned char Reserved2:1;
			
			/* CONTROL 0x40 */
			unsigned char Reserved3:1;
			
			/* CONTROL 0x80 */
			unsigned char OUT:1;
		} Bit;
	}	
	Control; /* ADDRESS 0x07 */
	
	struct
	{
		/* RAM FROM 0x08 TO 0x3F */
		unsigned char Byte[56];
	}
	Ram; /* ADDRESS 0x07 */
	
}
DS1307_typedef;


#define Encode(x)						( ( x % 10 ) + ( x / 10 ) * 16 )
#define Decode(x)						( ( x % 16 ) + ( x / 16 ) * 10 )

void DS1307_Update(DS1307_typedef * RTC_DS1307);
void DS1307_DataWrite(unsigned char address, unsigned char data);
void DS1307_ControlWrite(unsigned char address, unsigned char data);
void DS1307_RamWrite(unsigned char address, unsigned char data);
unsigned char DS1307_Read(unsigned char address);

#endif /* DS1307_H */
