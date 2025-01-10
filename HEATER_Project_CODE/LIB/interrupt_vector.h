/*
 * interrupt_vector.h
 *
 * Created: 10/09/2024 17:06:46
 *  Author: maboh
 */ 


#ifndef INTERRUPT_VECTOR_H_
#define INTERRUPT_VECTOR_H_


#define ISR(__vector_NUM)   void __vector_NUM(void)__attribute__((signal));\
                            void __vector_NUM(void)
							
#define INT0_V       __vector_1
#define INT1_V       __vector_2
#define INT2_V       __vector_3
#define TIMER1_CAPT  __vector_6
#define TIMER0_OVF   __vector_11
#define TIMER0_COMP  __vector_10





#endif /* INTERRUPT_VECTOR_H_ */