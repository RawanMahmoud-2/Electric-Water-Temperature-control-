/*
 * TIM_prog.c
 *
 * Created: 9/22/2024 3:33:44 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/interrupt_vector.h"
#include "TIM0_interface.h" 
#include "TIM0_reg.h" 

void(*TIM0_PTR[2])(void)={null} ; 

void TIM0_voidOverFlowInit( u8 copy_u8mode) {
	
	/* select prescaler : see TIM0 interface */
	
	TCCR0_REG&=0b11111000 ;
	TCCR0_REG|=TIM0_PRESCALER ;
	
	if (copy_u8mode==OV_MODE)
	{
			/* select mode : normal mode */
			CLR_BIT(TCCR0_REG,3) ;
			CLR_BIT(TCCR0_REG,6) ;
				
				/* enable  overflow interrupt */
				SET_BIT(TIMSK_REG,0) ;
	}
    else if (copy_u8mode==CTC_MODE)
    {
		/* select mode : normal mode */
		SET_BIT(TCCR0_REG,3) ;
		CLR_BIT(TCCR0_REG,6) ;
		
		OCR0_REG=OCR_VAL ; 
		/* enable  overflow interrupt */
		SET_BIT(TIMSK_REG,1) ;
		
    }
	
	

	
}

void TIM0_voidSetCallBack(void(*ptr)(void),u8 copu_u8mode){
	
	 switch(copu_u8mode){
		 
		 case  OV_MODE : TIM0_PTR[0]=ptr ; break ; 
		 case  CTC_MODE :TIM0_PTR[1]=ptr ; break ;
		 
	 }
	
	
}


ISR(TIMER0_OVF){
	
TIM0_PTR[0]() ; 
	
	
}


ISR(TIMER0_COMP){
	
	
TIM0_PTR[1]() ;

}

void TIM0_voidFastPWM(u8 copy_u8dc){
	TCCR0_REG&=0b11111000 ;
	TCCR0_REG|=TIM0_PRESCALER ;
	
	SET_BIT(TCCR0_REG,3) ;
	SET_BIT(TCCR0_REG,6) ;
	
	CLR_BIT(TCCR0_REG,4) ;
	SET_BIT(TCCR0_REG,5) ;
	
	OCR0_REG= copy_u8dc*2.56;
	
	
	
	
}
