/*
 * LED_prog.c
 *
 * Created: 25/08/2024 16:47:13
 *  Author: maboh
 */ 

#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "LED_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>

void LED_voidOn(u8 copy_u8port, u8 copy_u8pin){
	
	DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT );
	DIO_voidSetPinVal(copy_u8port, copy_u8pin, HIGH);
	
}


void LED_voidOff(u8 copy_u8port, u8 copy_u8pin){
		
		DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT );
		DIO_voidSetPinVal(copy_u8port, copy_u8pin, LOW);
	
}

void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin){
		DIO_voidSetPinDir(copy_u8port, copy_u8pin, OUTPUT );
		DIO_voidToggelPinVal(copy_u8port, copy_u8pin);
		_delay_ms(100);
		DIO_voidToggelPinVal(copy_u8port, copy_u8pin);
		
			
}
