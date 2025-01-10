/*
 * TIM0_interface.h
 *
 * Created: 9/22/2024 3:33:18 PM
 *  Author: AMIT
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_



/* TIMER0 PRESCALER */

#define  _NO_PRESCALER         1 
#define  _8_PRESCALER          2
#define  _64_PRESCALER         3
#define  _256_PRESCALER        4
#define  _1024_PRESCALER       5

#define  TIM0_PRESCALER    _64_PRESCALER

/* TIMER0 MODE */

#define  OV_MODE       0 
#define  CTC_MODE      1 


/* OCR VAL */

#define  OCR_VAL   250

void TIM0_voidFastPWM(u8 copy_u8dc);

void TIM0_voidOverFlowInit( u8 copy_u8mode) ; 

void TIM0_voidSetCallBack(void(*ptr)(void),u8 copu_u8mode) ; 



#endif /* TIM0_INTERFACE_H_ */