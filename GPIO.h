#ifndef GPIO_H
#define GPIO_H
#include "STD_TYPES.h"
#include "GPIO_Priv.h"
typedef enum{
	GPIOA=0,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH
}PORTS;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PINS;
//pin mode
#define Mode_input 							(uint8)0x00
#define Mode_output 						(uint8)0x01
#define Mode_Alt								(uint8)0x02
#define Mode_analog							(uint8)0x03

//output mode
#define Mode_Output_pushpull		(uint8)0x00
#define Mode_Output_opendrain		(uint8)0x01

//output speed
#define Speed_output_low				(uint8)0x00
#define Speed_output_med				(uint8)0x01
#define Speed_output_high				(uint8)0x02
#define Speed_output_vhigh			(uint8)0x03


void vGPIO_PinSetMode(PORTS,PINS,uint8 mode);
void vGPIO_PinSetOutType(PORTS,PINS,uint8 OutType); //0-> push,pull   1->open drain
void vGPIO_PinSetOutSpeed(PORTS,PINS,uint8 speed);//0-> min speed  3->max speed
void vGPIO_PinSetPull(PORTS,PINS,uint8 Pull_Type);//0-> no pull 1->up 2-> pulldown 3->N/A
uint8 u8GPIO_PinReadData(PORTS,PINS);
void vGPIO_PinWrite(PORTS,PINS,uint8 value);
void vGPIO_PinLock(PORTS,PINS);
void vGPIO_PinSetAltFn(PORTS,PINS,uint8 Alt_Fn);

GPIOx_Struct * PORT_ADD(PORTS port_name);




#endif