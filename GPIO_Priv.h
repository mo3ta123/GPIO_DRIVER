#ifndef GPIO_Priv_H
#define GPIO_Priv_H
#include"STD_TYPES.h"
#define GPIOA_BASE_ADDRESSE ((GPIOx_Struct*)0x40020000)
#define GPIOB_BASE_ADDRESSE ((GPIOx_Struct*)0x40020400)
#define GPIOC_BASE_ADDRESSE ((GPIOx_Struct*)0x40020800)
#define GPIOD_BASE_ADDRESSE ((GPIOx_Struct*)0x40020C00)
#define GPIOE_BASE_ADDRESSE ((GPIOx_Struct*)0x40021000)
#define GPIOF_BASE_ADDRESSE ((GPIOx_Struct*)0x40021400)
#define GPIOG_BASE_ADDRESSE ((GPIOx_Struct*)0x40021800)
#define GPIOH_BASE_ADDRESSE ((GPIOx_Struct*)0x40021C00)


typedef struct{
	uint32 GPIOx_MODER;						//0x00
	uint32 GPIOx_OTYPER;					//0x04
	uint32 GPIOx_OSPEEDR;					//0x08
	uint32 GPIOx_PUPDR;						//0x0c
	uint32 GPIOx_IDR;							//0x10
	uint32 GPIOx_ODR;							//0x14
	uint32 GPIOx_BSRR;						//0x18
	uint32 GPIOx_LCKR;						//0x1c
	uint32 GPIOx_AFRL;						//0x20
	uint32 GPIOx_AFRH;						//0x24
}GPIOx_Struct;












#endif
