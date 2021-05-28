#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#define CLK_SRC		0		//HSE=0,HSI=1,PLL=2
#define HSE_SRC		0		//CRYSTAL=0 , RC=1
#define PLL_SRC		0		//HSE=0 ,HSI=1
#define BUS_CH		0		// AHB1=0,AHB2=1,AHB3=2,APB1=3,APB2=4
#define PER_NUM		0
#define AHB_PRE		1		//(1,2,4,8,16,64,128,256,512)
#define AHB1_PRE	1		//(1,2,4,8,16)
#define AHB2_PRE	1		//(1,2,4,8,16)

typedef enum {
	HSE = 0,
	HSI,
	PLL
}ClkSrcName_t;

typedef enum {
	HSE_Crystal=0,
	HSE_RC
}HSESrcName_t;

typedef enum {
	PLL_HSE=0,
	PLL_HSI
}PLLSrcName_t;

typedef enum
{
	AHB_Pre1 = 0,
	AHB_Pre2,
	AHB_Pre4,
	AHB_Pre8,
	AHB_Pre16,
	AHB_Pre64,
	AHB_Pre128,
	AHB_Pre256,
	AHB_Pre512
}AHBPreName_t;

typedef enum {
	APB1_Pre1=0,
	APB1_Pre2,
	APB1_Pre4,
	APB1_Pre8,
	APB1_Pre16
}APB1PreName_t;

typedef enum {
	APB2_Pre1 = 0,
	APB2_Pre2,
	APB2_Pre4,
	APB2_Pre8,
	APB2_Pre16
}APB2PreName_t;

typedef enum {
	AHB1=0,
	AHB2,
	AHB3,
	APB1,
	APB2
}BusName_t;

#endif
