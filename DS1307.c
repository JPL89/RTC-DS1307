#include "LM3S3xx.h"
#include "DS1307.h"
#include "I2C.h"

void DS1307_Update(DS1307_typedef * RTC_DS1307)
{
	/* ::Loop:: */
	unsigned char i = 0;
	
	/* ADDRESS 0x00 */
	I2C_Master_send(0xD0, 0x00, Encode( RTC_DS1307->Rtc.Seconds) );
	
	/* ADDRESS 0x01 */
	I2C_Master_send(0xD0, 0x01, Encode( RTC_DS1307->Rtc.Minutes) );
	
	/* ADDRESS 0x02 */
	I2C_Master_send(0xD0, 0x02, Encode( RTC_DS1307->Rtc.Hours) );
	
	/* ADDRESS 0x03 */
	I2C_Master_send(0xD0, 0x03, Encode( RTC_DS1307->Rtc.Day) );
	
	/* ADDRESS 0x04 */
	I2C_Master_send(0xD0, 0x04, Encode( RTC_DS1307->Rtc.Date) );
	
	/* ADDRESS 0x05 */
	I2C_Master_send(0xD0, 0x05, Encode( RTC_DS1307->Rtc.Month) );
	
	/* ADDRESS 0x06 */
	I2C_Master_send(0xD0, 0x06, Encode( RTC_DS1307->Rtc.Year) );
	
	/* ADDRESS 0x07 */
	I2C_Master_send(0xD0, 0x07, RTC_DS1307->Control.raw);
			
	/* ADDRESS 0x08 - 0x3F */
	for(i = 0x08; i <= 0x3F; ++i)
	{
		I2C_Master_send(0xD0, i, Encode( RTC_DS1307->Ram.Byte[i]) );
	}
}

void DS1307_DataWrite(unsigned char address, unsigned char data)
{
	I2C_Master_send(0xD0, address, Encode( data ) );
}

void DS1307_ControlWrite(unsigned char address, unsigned char data)
{
	I2C_Master_send(0xD0, address, data);
}

void DS1307_RamWrite(unsigned char address, unsigned char data)
{
	I2C_Master_send(0xD0, address, data );
}

unsigned char DS1307_Read(unsigned char address)
{
	unsigned char byte = I2C_Read(address);	
	return ((unsigned char) Decode( byte ) );
}
