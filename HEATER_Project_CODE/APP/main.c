/*
 * main.c
 *
 * Created: 07/01/2025 12:32:10
 *  Author: maboh
 */ 


#include "../HAL/SSD/SSD_interfaceh.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../LIB/interrupt_vector.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../MCAL/TIMER0/TIM0_interface.h"
#include "../MCAL/GI/GI_interface.h"


#define BUTTON_UP     DIO_u8ReadPinVal(DIO_PORTB,DIO_PIN0)
#define BUTTON_DOWN   DIO_u8ReadPinVal(DIO_PORTB,DIO_PIN1)
#define BUTTON_ON_OFF DIO_u8ReadPinVal(DIO_PORTA,DIO_PIN7)	

#define F_CPU 16000000UL
#include <util/delay.h>


void Heater(u8 temp, u8 heater_temp){
	if(temp<heater_temp){
		LED_voidOn(DIO_PORTC,DIO_PIN5);//HEATER LAMP ON
		LED_voidToggle(DIO_PORTA,DIO_PIN2);//ON-OFF LED TOGGLE EVERY 1SEC
		
	}
	else{
		LED_voidOff(DIO_PORTC,DIO_PIN5);//HEATER LAMP OFF
		
	}
}

void cooler(u8 temp ,u8 cooler_temp){
	if (temp>cooler_temp){
		LED_voidOn(DIO_PORTC,DIO_PIN4);//COOLER LAMP ON
		LED_voidOn(DIO_PORTA,DIO_PIN2);//ON-OFF LED ON
		
	}
	else {
		LED_voidOff(DIO_PORTC,DIO_PIN4);//COOLER LAMP OFF
		
	}
	
	
}

u8 CalculateAverage(u8 *readings, u8 count) {
	u16 sum = 0;
	for (u8 i = 0; i < count; i++) {
		sum += readings[i];
	}
	return sum / count;
}

volatile u8 SET_ON = 0;
volatile u16 timer = 5000;  // Timer to track 5s timeout
// SET-MODE OFF IF BUTTONS ARE NOT PRESSED FOR 5 SEC
void timer_callback(void) {
	if (BUTTON_UP == 0 && BUTTON_DOWN == 0) {
		// No buttons pressed
		if (timer > 0) {
			timer--;  // Decrement timer
		}
		if (timer == 0) {
			// If no buttons are pressed for 5ms, reset SET_ON
			SET_ON = 0;
		}
		} else {
		// Reset the timer when a button is pressed
		timer = 5000;
		SET_ON = 1;
	}
}

int main(){

	ADC_voidInit();
	EEPROM_voidInit();
	GI_voidEnable();
	TIM0_voidOverFlowInit(OV_MODE);
	TIM0_voidSetCallBack(timer_callback,OV_MODE);
	
//u8 SET_ON = 0;

u8 temp_tens  = 0;
u8 temp_units = 0;
u8 set_temp_tens  = 0;
u8 set_temp_units = 0;
u16 val=0;
f32 temp=0;

u8 set_temp_min=35;
u8 set_temp_max=75;
u8 set_temp=60;
u8 last_set_temp = 60;

u8 cooler_temp=0;
u8 heater_temp=0;
u8 heater_system=0;

u8 temp_readings[10] = {0};
u8 index = 0;
u8 count = 0;
u8 temp_avg=0;

while(1)
{    
if (BUTTON_ON_OFF==1)
	{while(BUTTON_ON_OFF==1);//debounce
		heater_system=1;
		}
   //HEATER SYSTEM ON
	while( heater_system==1){
		val = ADC_u16ReadChannel(ADC1_);
		temp =(f32) val*500/1024;

		// Update temperature buffer for averaging
		temp_readings[index++] = temp;
		if (index == 10) index = 0;
		if (count < 10) count++;

		// Calculate average temperature
		temp_avg = CalculateAverage(temp_readings, count);
					
	
	cooler_temp=set_temp+5;
	heater_temp=set_temp-5;
	
	temp_tens = (u8)temp_avg / 10;
	temp_units = (u8)temp_avg % 10;
	

	//setting mode
	set_temp_tens =  (u8)set_temp / 10;
	set_temp_units = (u8)set_temp % 10;
	
	
		if(SET_ON==0){
			SSD_voidDisplayBOTH(temp_tens,temp_units);
		}
		if(BUTTON_UP==1||BUTTON_DOWN==1)
		{SET_ON=1;
		}
		
	//SETTING MODE ON
		if(SET_ON==1){
	    EEPROM_voidReadByte(500,&set_temp);//set setting temp as saved 
		SSD_Toggle(temp_tens,temp_units,set_temp_tens,set_temp_units);
	
		//BUTTON UP
			if(BUTTON_UP==1 && set_temp<set_temp_max){
				while(BUTTON_UP==1);
				set_temp=set_temp+5;	
			}
		//BUTTON DOWN
			else if(BUTTON_DOWN==1 && set_temp>set_temp_min){
				while(BUTTON_DOWN==1);
				set_temp=set_temp-5;	
			}
		//EEPROM SAVE SET VALUE
			if (set_temp != last_set_temp) {
				EEPROM_voidWriteByte(500, set_temp);
				last_set_temp = set_temp;
			}
			
			cooler(temp,cooler_temp);
			Heater(temp,heater_temp);
			
			}
	//HEATER SYSTEM OFF
	if(BUTTON_ON_OFF==1){
	while(BUTTON_ON_OFF==1);
		heater_system=0;
	LED_voidOff(DIO_PORTA,DIO_PIN2);}
	
		
		}
			
	}
}

