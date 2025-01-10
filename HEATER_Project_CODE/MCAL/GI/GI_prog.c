/*
 * GI_prog.c
 *
 * Created: 9/3/2024 4:27:10 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "GI_reg.h" 



void GI_voidEnable(void){
	
	SET_BIT(SREG_REG,7) ; 
	
	//__asm volatile("SEI") ; 
}

void GI_voidDisable(void) {
	
	CLR_BIT(SREG_REG,7) ; 
	
	//__asm volatile("CLI") ;
	
}