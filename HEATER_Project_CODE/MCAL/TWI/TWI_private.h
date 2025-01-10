/*
 * TWI_private.h
 *
 * Created: 20/10/2024 07:23:19 م
 *  Author: Kareem Hussein
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define TWI_STATUS_VALUE					(TWSR_REG & 0xF8)

#define TWI_STATUS_CODE_START_CON		        	           0x08
#define TWI_STATUS_CODE_RPEATED_START_CON			           0x10
#define TWI_STATUS_CODE_SEND_SLAVE_ADD_WRITE		           0x18
#define TWI_STATUS_CODE_SEND_SLAVE_ADD_READ			           0x40
#define TWI_STATUS_CODE_SEND_MASTER_DATA_BYTE		           0x28 
#define TWI_STATUS_CODE_RECEIVE_MASTER_DATA_BYTE_ACK		   0x50
#define TWI_STATUS_CODE_RECEIVE_MASTER_DATA_BYTE_NACK		   0x58

#endif /* TWI_PRIVATE_H_ */