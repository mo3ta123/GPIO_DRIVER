#include"STD_TYPES.h"
#include"RCC.h"
#include"RCC_CONFIG.h"
#define setBit(y) |=(1u<<y)
#define resetBit(y) &=~(1u<<y)
#define toggleBit(y) ^=(1u<<y)

void vRCC_SerSYSCLK(ClkSrcName_t ClkSrc, HSESrcName_t HSESrc, PLLSrcName_t PLLSrc, AHBPreName_t AHBpre, APB1PreName_t APB1pre, APB2PreName_t APB2pre) {
	switch (ClkSrc) {
		case 0:
			switch (HSESrc) {
			case 0:
				RCC_CR setBit(16);
				RCC_CR resetBit(18);
				RCC_CFGR setBit(0);
				RCC_CFGR resetBit(1);
				break;
			case 1:
				RCC_CR setBit(16);
				RCC_CR setBit(18);
				RCC_CFGR setBit(0);
				RCC_CFGR resetBit(1);
				break;
			default:break;
			}
		case 1:
			RCC_CR setBit(0);
			RCC_CFGR resetBit(0);
			RCC_CFGR resetBit(1);
			break;
		case 2:
			switch (PLLSrc) {
			case 0:
				RCC_CR setBit(16);
				RCC_CR setBit(24);
				RCC_PLLCFGR setBit(22);
				RCC_CFGR setBit(1);
				RCC_CFGR resetBit(0);
				break;
			case 1:
				RCC_CR setBit(24);
				RCC_CR setBit(0);
				RCC_PLLCFGR resetBit(22);
				RCC_CFGR setBit(1);
				RCC_CFGR resetBit(0);
				break;
			default:break;
			}
	}
	switch (AHBpre) {
	case 0://1
		RCC_CFGR resetBit(7);
		break;
	case 1://2
		RCC_CFGR setBit(7);
		RCC_CFGR resetBit(6);
		RCC_CFGR resetBit(5);
		RCC_CFGR resetBit(4);
		break;
	case 2://4
		RCC_CFGR setBit(7);
		RCC_CFGR resetBit(6);
		RCC_CFGR resetBit(5);
		RCC_CFGR setBit(4);
		break;
	case 3://8
		RCC_CFGR setBit(7);
		RCC_CFGR resetBit(6);
		RCC_CFGR setBit(5);
		RCC_CFGR resetBit(4);
		break;
	case 4://16
		RCC_CFGR setBit(7);
		RCC_CFGR resetBit(6);
		RCC_CFGR setBit(5);
		RCC_CFGR setBit(4);
		break;
	case 5://64
		RCC_CFGR setBit(7);
		RCC_CFGR setBit(6);
		RCC_CFGR resetBit(5);
		RCC_CFGR resetBit(4);
		break;
	case 6://128
		RCC_CFGR setBit(7);
		RCC_CFGR setBit(6);
		RCC_CFGR resetBit(5);
		RCC_CFGR setBit(4);
		break;
	case 7://256
		RCC_CFGR setBit(7);
		RCC_CFGR setBit(6);
		RCC_CFGR setBit(5);
		RCC_CFGR resetBit(4);
		break;
	case 8://512
		RCC_CFGR setBit(7);
		RCC_CFGR setBit(6);
		RCC_CFGR setBit(5);
		RCC_CFGR setBit(4);
		break;
	default:break;
	}
	switch (APB1pre) {
	case 0://1
		RCC_CFGR resetBit(12);
		break;
	case 1://2
		RCC_CFGR setBit(12);
		RCC_CFGR resetBit(11);
		RCC_CFGR resetBit(10);
		break;
	case 2://4
		RCC_CFGR setBit(12);
		RCC_CFGR resetBit(11);
		RCC_CFGR setBit(10);
		break;
	case 3://8
		RCC_CFGR setBit(12);
		RCC_CFGR setBit(11);
		RCC_CFGR resetBit(10);
		break;
	case 4://16
		RCC_CFGR setBit(12);
		RCC_CFGR setBit(11);
		RCC_CFGR setBit(10);
		break;
	default:break;
	}
	switch (APB2pre) {
	case 0://1
		RCC_CFGR resetBit(15);
		break;
	case 1://2
		RCC_CFGR setBit(15);
		RCC_CFGR resetBit(14);
		RCC_CFGR resetBit(13);
		break;
	case 2://4
		RCC_CFGR setBit(15);
		RCC_CFGR resetBit(14);
		RCC_CFGR setBit(13);
		break;
	case 3://8
		RCC_CFGR setBit(15);
		RCC_CFGR setBit(14);
		RCC_CFGR resetBit(13);
		break;
	case 4://16
		RCC_CFGR setBit(15);
		RCC_CFGR setBit(14);
		RCC_CFGR setBit(13);
		break;
	default:break;
	}
}

void vRCC_EnPerClk(BusName_t BusName, uint8 perName) {
	switch (BusName) {
	case 0:
		RCC_AHB1ENR setBit(perName);
		break;
	case 1:
		RCC_AHB2ENR setBit(perName);
		break;
	case 2:
		RCC_AHB3ENR setBit(perName);
		break;
	case 3:
		RCC_APB1ENR setBit(perName);
		break;
	case 4:
		RCC_APB2ENR setBit(perName);
		break;
	}

}
