#include"GPIO_Priv.h"
#include"GPIO.h"
#include"STD_TYPES.h"
#define setBit(Reg,x) 			Reg|=(1u<<x)
#define resetBit(Reg,x) 		Reg&=~(1u<<x)
#define toggleBit(Reg,x)		Reg^=(1u<<x)
#define checkBit(Reg,x)  		((Reg>>x)&1u)
GPIOx_Struct * PORT_ADD(PORTS port_name){
	GPIOx_Struct* ptr;
	switch(port_name){
		case GPIOA:
			ptr=GPIOA_BASE_ADDRESSE;
			break;
		case GPIOB:
			ptr=GPIOB_BASE_ADDRESSE;
				break;
		case GPIOC:
			ptr=GPIOC_BASE_ADDRESSE;
			break;
		case GPIOD:
			ptr=GPIOD_BASE_ADDRESSE;
			break;
		case GPIOE:
			ptr=GPIOE_BASE_ADDRESSE;
			break;
		case GPIOF:
			ptr=GPIOF_BASE_ADDRESSE;
			break;
		case GPIOG:
			ptr=GPIOG_BASE_ADDRESSE;
			break;
		case GPIOH:
			ptr=GPIOH_BASE_ADDRESSE;
			break;
	}
	return ptr;
}



void vGPIO_PinSetMode(PORTS port_name,PINS pin_value,uint8 mode){//assuming regesters were all zeros in begining.
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	ptr->GPIOx_MODER|=(uint32)(mode<<(pin_value*2));
}

void vGPIO_PinSetOutType(PORTS port_name,PINS pin_value,uint8 OutType){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	if(OutType ==0)resetBit(ptr->GPIOx_OTYPER,pin_value);		//push-pull
	else setBit(ptr->GPIOx_OTYPER,pin_value);								//open drain
	
}
void vGPIO_PinSetOutSpeed(PORTS port_name,PINS pin_value,uint8 speed){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	ptr->GPIOx_OSPEEDR|=(uint32)(speed<<(2*pin_value));

}

void vGPIO_PinSetPull(PORTS port_name,PINS pin_value,uint8 Pull_Type){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	ptr->GPIOx_PUPDR |=(uint32)(Pull_Type<<(pin_value*2));
	
	
}

uint8 u8GPIO_PinReadData(PORTS port_name,PINS pin_value){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	return checkBit(ptr->GPIOx_IDR,pin_value);
	
}
	
void vGPIO_PinWrite(PORTS port_name,PINS pin_value,uint8 value){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	if(value==0)resetBit(ptr->GPIOx_ODR,pin_value); 
	else setBit(ptr->GPIOx_ODR,pin_value);
	
}

void vGPIO_PinLock(PORTS port_name,PINS pin_value){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	setBit(ptr->GPIOx_LCKR,pin_value);
	setBit(ptr->GPIOx_LCKR,16);
	while(checkBit(ptr->GPIOx_LCKR,16)==0);
}



void vGPIO_PinSetAltFn(PORTS port_name,PINS pin_value,uint8 Alt_Fn){
	GPIOx_Struct* ptr=PORT_ADD(port_name);
	if(pin_value<=7){
		ptr->GPIOx_AFRL |=(uint32)(Alt_Fn<<(4*pin_value));
	}
	
	else{
		pin_value-=8;
		ptr->GPIOx_AFRH |=(uint32)(Alt_Fn<<(4*pin_value));
	}
}

