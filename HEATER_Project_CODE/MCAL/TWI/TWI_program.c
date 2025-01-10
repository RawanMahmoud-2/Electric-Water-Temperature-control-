/*
 * TWI_program.c
 *
 * Created: 20/10/2024 07:22:57 م
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"

/* MCAL */
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"


//Master APIS
void TWI_voidInitMaster(void)
{
	// Set Prescaler = 1 , Set Freq. = 400KHZ (F_CPU = 16000000)
	TWBR_REG = 12;
	CLR_BIT(TWSR_REG, TWPS0);
	CLR_BIT(TWSR_REG, TWPS1);
	
	// Enable TWI peripheral
	SET_BIT(TWCR_REG, TWEN);
}


void TWI_voidSendStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWSTA);	
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy wait for flag 
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check Status code = Start condition  Status code
	while(TWI_STATUS_VALUE != TWI_STATUS_CODE_START_CON);
}


void TWI_voidSendRepStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWSTA);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy wait for flag
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check Status code = Repeated Start condition Status code
	while(TWI_STATUS_VALUE != TWI_STATUS_CODE_RPEATED_START_CON);
}


void TWI_voidSendStopCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWSTO);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);	
}


void TWI_voidSendSlaveAddWithWrite(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd < 128)
	{
		// Write slave address to SDA bus
		TWDR_REG = (copy_u8SlaveAdd << 1);
		
		// Select write operation
		CLR_BIT(TWDR_REG, 0);
		
		// Clear Start Condition bit
		CLR_BIT(TWCR_REG, TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy wait for flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		 // Check Status code = Master transmit ( slave address + Write request )Status codes
		while(TWI_STATUS_VALUE != TWI_STATUS_CODE_SEND_SLAVE_ADD_WRITE);
	}	
	else
	{
		// return Error State
	}
}


void TWI_voidSendSlaveAddWithRead(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd < 128)
	{
		// Write slave address to SDA bus
		TWDR_REG = (copy_u8SlaveAdd << 1);
		
		// Select read operation
		SET_BIT(TWDR_REG, 0);
		
		// Clear Start Condition bit
		CLR_BIT(TWCR_REG, TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy wait for flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check Status code = Master transmit ( slave address + Read request )Status code
		while(TWI_STATUS_VALUE != TWI_STATUS_CODE_SEND_SLAVE_ADD_READ);
	}
	else
	{
		// return Error State
	}
}


void TWI_voidTransmitMasterDataByte(u8 copy_u8TxData)
{
	// Write Data into data register
	TWDR_REG = copy_u8TxData;
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy wait for flag
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check Status code = send master data byte Status code
	while(TWI_STATUS_VALUE != TWI_STATUS_CODE_SEND_MASTER_DATA_BYTE);
}


void TWI_voidReceiveMasterDataByteWithACK(u8* copy_pu8RxData)
{
	if(copy_pu8RxData != null)
	{
		// Enable ACK pulse
		SET_BIT(TWCR_REG, TWEA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy wait for flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check Status code = Receive master data byte with ACK Status code
		while(TWI_STATUS_VALUE != TWI_STATUS_CODE_RECEIVE_MASTER_DATA_BYTE_ACK);
		
		*copy_pu8RxData = TWDR_REG;
		
		// Disable ACK pulse
		CLR_BIT(TWCR_REG, TWEA);
	}
	else
	{
		//return Error State
	}
}


void TWI_voidReceiveMasterDataByteWithoutACK(u8* copy_pu8RxData)
{
	if(copy_pu8RxData != null )
	{
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy wait for flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check Status code = Receive master data byte without ACK Status code
		while(TWI_STATUS_VALUE != TWI_STATUS_CODE_RECEIVE_MASTER_DATA_BYTE_NACK);
		
		*copy_pu8RxData = TWDR_REG;
	}
	else
	{
		//return Error State
	}
}
