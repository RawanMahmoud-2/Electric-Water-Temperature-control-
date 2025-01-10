/*
 * EEPROM_program.c
 *
 * Created: 20/10/2024 10:43:01 م
 *  Author: Kareem Hussein
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/TWI/TWI_interface.h"

/* HCAL */
#include "EEPROM_interface.h"
#include "EEPROM_private.h"


void EEPROM_voidInit(void)
{
	TWI_voidInitMaster();	
}


void EEPROM_voidWriteByte(u16 copy_u16WordAdd, u8 copy_u8Data)
{
	u8 local_u8DeviceAdd = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS;
	
	// Send start condition
	TWI_voidSendStartCondition();
	
	// Send slave address with write operation (device address)
	TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);
	
	// Send word address
	TWI_voidTransmitMasterDataByte((u8)copy_u16WordAdd);
	
	// Send byte data
	TWI_voidTransmitMasterDataByte(copy_u8Data);
	
	// Send stop condition
	TWI_voidSendStopCondition();
	
	// Self-timed Write Cycle delay
	_delay_ms(5);
}


void EEPROM_voidReadByte(u16 copy_u16WordAdd, u8* copy_pu8Data)
{
	if(copy_pu8Data != null)
	{
		u8 local_u8DeviceAdd = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS;
		
		// Send start condition
		TWI_voidSendStartCondition();
		
		// Send slave address with write operation (device address)
		TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);
		
		// Send word address
		TWI_voidTransmitMasterDataByte((u8)copy_u16WordAdd);
		
		// Send repeated start condition in order to switch i2c operation (W >> R)
		TWI_voidSendRepStartCondition();
		
		// Send slave address with read operation (device address)
		TWI_voidSendSlaveAddWithRead(local_u8DeviceAdd);
		
		// Read byte data and respond without ACK
		TWI_voidReceiveMasterDataByteWithoutACK(copy_pu8Data);
		
		// Send stop condition
		TWI_voidSendStopCondition();
		
		// Self-timed Write Cycle delay
		_delay_ms(5);
	}
	else
	{
		//return Error State
	}
}