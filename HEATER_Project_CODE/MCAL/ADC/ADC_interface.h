/*
 * ADC_interface.h
 *
 * Created: 9/15/2024 3:32:15 PM
 *  Author: AMIT
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



/* select adc prescaler */

#define  _2_PRESCALER         1 
#define  _4_PRESCALER         2
#define  _8_PRESCALER         3
#define  _16_PRESCALER        4
#define  _32_PRESCALER        5
#define  _64_PRESCALER        6
#define  _128_PRESCALER       7


#define  ADC_PRESCALER      _128_PRESCALER


/*ADC channel */

#define  ADC0_          0
#define  ADC1_          1
#define  ADC2_          2
#define  ADC3_          3
#define  ADC4_          4
#define  ADC5_          5
#define  ADC6_          6
#define  ADC7_          7





void ADC_voidInit(void) ; 

u16 ADC_u16ReadChannel(u8 copy_u8channel) ; 



#endif /* ADC_INTERFACE_H_ */