/*
 * ADC_prog.c
 *
 * Created: 9/15/2024 3:32:28 PM
 *  Author: AMIT
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "ADC_interface.h"
#include "ADC_reg.h"





void ADC_voidInit(void){
	
	/*Voltage Reference Selection : AVCC with external capacitor at AREF pin */
	
            	SET_BIT(ADMUX_REG,6) ; 
            	CLR_BIT(ADMUX_REG,7) ; 
	           /* SET ADC PRESCALER */
	           ADCSRA_REG&=0b11111000 ;                                      
	           ADCSRA_REG|=ADC_PRESCALER ;        
			   
	                                   
	
	/* enable adc */
	SET_BIT(ADCSRA_REG,7) ; 
	
}

u16 ADC_u16ReadChannel(u8 copy_u8channel){
	
	ADMUX_REG&=0b11100000 ; 
	ADMUX_REG|=copy_u8channel ; 
	
	/* start conversion */
	SET_BIT(ADCSRA_REG,6) ; 
	
	while(GET_BIT(ADCSRA_REG,4)==0) ; 
	
	return  ADC_REG ; 
	
	
	
}