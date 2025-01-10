/*
 * SSD_interfaceh.h
 *
 * Created: 27/08/2024 11:15:48
 *  Author: maboh
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#ifndef SSD_INTERFACEH_H_
#define SSD_INTERFACEH_H_

#define SSD1  0
#define SSD2  1
#define ON    11
#define OFF   22

void SSD_voidDisplayNum(u8 copy_u8num, u8 ssd_num, u8 ssd_state);
void SSD_voidDisplayBOTH(u8 num1, u8 num2);
void SSD_Toggle(u8 temp_tens,u8 temp_units,u8 set_temp_tens,u8 set_temp_units);



#endif /* SSD_INTERFACEH_H_ */