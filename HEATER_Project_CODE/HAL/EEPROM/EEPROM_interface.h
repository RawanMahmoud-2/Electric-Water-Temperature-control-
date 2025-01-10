/*
 * EEPROM_interface.h
 *
 * Created: 20/10/2024 10:43:13 م
 *  Author: Kareem Hussein
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


            /*************** APIS PROTOTYPES ***************/

void EEPROM_voidInit     (void);
void EEPROM_voidWriteByte(u16 copy_u16WordAdd, u8 copy_u8Data);
void EEPROM_voidReadByte (u16 copy_u16WordAdd, u8* copy_pu8Data);

#endif /* EEPROM_INTERFACE_H_ */