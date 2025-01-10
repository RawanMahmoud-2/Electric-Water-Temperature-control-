/*
 * SSD_prog.c
 *
 * Created: 27/08/2024 11:16:21
 *  Author: maboh
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interfaceh.h"
#include "SSD_config.h"

#define F_CPU 16000000UL
#include <util/delay.h>


const u8 SSD_NUM_PATTERNS[10] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};


void SSD_voidDisplayNum(u8 copy_u8num, u8 ssd_num , u8 ssd_state)
{
	DIO_voidSetPortDir(SSD_PORT, 0xFF);
	
	if(ssd_num ==SSD1){
		
		if(ssd_state== ON){
	DIO_voidSetPinDir(SSD_EN1_PORT, SSD_EN1_PIN, OUTPUT);
	DIO_voidSetPinVal(SSD_EN1_PORT, SSD_EN1_PIN, LOW);//LOW for common-cathode as ground
    DIO_voidSetPortVal(SSD_PORT,SSD_NUM_PATTERNS[copy_u8num] );
		}
		else if (ssd_state== OFF){
			DIO_voidSetPinDir(SSD_EN1_PORT, SSD_EN1_PIN, OUTPUT);
			DIO_voidSetPinVal(SSD_EN1_PORT, SSD_EN1_PIN, HIGH);	
		}
		
	}
	else if(ssd_num== SSD2){
		if(ssd_state== ON){
		DIO_voidSetPinDir(SSD_EN2_PORT, SSD_EN2_PIN, OUTPUT);
		DIO_voidSetPinVal(SSD_EN2_PORT, SSD_EN2_PIN, LOW);
		DIO_voidSetPortVal(SSD_PORT,SSD_NUM_PATTERNS[copy_u8num]);
		}
		
		else if (ssd_state== OFF){
		DIO_voidSetPinDir(SSD_EN2_PORT, SSD_EN2_PIN, OUTPUT);
		DIO_voidSetPinVal(SSD_EN2_PORT, SSD_EN2_PIN, HIGH);
		}
	}

	
}
void SSD_voidDisplayBOTH(u8 num1, u8 num2){
	SSD_voidDisplayNum(num1,SSD1,ON);
	_delay_ms(5);
	SSD_voidDisplayNum(num1,SSD1,OFF);
	
	SSD_voidDisplayNum(num2,SSD2,ON);
	_delay_ms(5);
	SSD_voidDisplayNum(num2,SSD2,OFF);
	
}


void SSD_Toggle(u8 temp_tens,u8 temp_units,u8 set_temp_tens,u8 set_temp_units){
	for (u8 i = 0; i < 50; i++) 
	{ // Adjust the loop count for longer display time
		SSD_voidDisplayBOTH(temp_tens, temp_units);
	}
_delay_ms(50);
	// Display set temperature
	for (u8 i = 0; i < 50; i++) { // Adjust the loop count for longer display time
		SSD_voidDisplayBOTH(set_temp_tens, set_temp_units);
	}
	
_delay_ms(50);

}
