/*
 * DIO_interface.h
 *
 * Created: 25/08/2024 14:10:52
 *  Author: maboh
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* PIN DIR*/
#define OUTPUT 1
#define INPUT 0

/*PIN VAL */
#define HIGH 1
#define LOW 0


/* PORTS */
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

/* PINS */
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7


/*******************************************************************
* Function Name:DIO_voidSetPinDir
* Purpose:set pin direction (INPUT,OUTPUT)
* Parameters:u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Dir
* Return value: VOid
*******************************************************************/
void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Dir);

/*******************************************************************
* Function Name:DIO_voidSetPinVal
* Purpose:set pin direction (HIGH,LOW)
* Parameters:u8 copy_u8port, u8 copy_u8pin, u8 copy_u8val
* Return value: void
*******************************************************************/
void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8val);


/*******************************************************************
* Function Name:DIO_voidSetPortDir
* Purpose:set port direction (INPUT,OUTPUT)
* Parameters:u8 copy_u8port,  u8 copy_u8Dir
* Return value: void
*******************************************************************/
void DIO_voidSetPortDir(u8 copy_u8port,  u8 copy_u8Dir);


/*******************************************************************
* Function Name:DIO_voidSetPortVal
* Purpose:set port value (HIGH,LOW)
* Parameters:u8 copy_u8port,  u8 copy_u8val
* Return value: void
*******************************************************************/
void DIO_voidSetPortVal(u8 copy_u8port,  u8 copy_u8val);


/*******************************************************************
* Function Name:DIO_voidToggelPinVal
* Purpose: toggle pin value (HIGH,LOW)
* Parameters: u8 copy_u8port, u8 copy_u8pin
* Return value: void
*******************************************************************/
void DIO_voidToggelPinVal(u8 copy_u8port, u8 copy_u8pin);


/*******************************************************************
* Function Name:DIO_u8ReadPinVal
* Purpose: read pin value (HIGH,LOW)
* Parameters: u8 copy_u8port, u8 copy_u8pin
* Return value: u8
*******************************************************************/
u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin);



#endif /* DIO_INTERFACE_H_ */