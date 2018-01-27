#ifndef _IOCFG_H_
#define _IOCFG_H_

#include "stm32f4xx_gpio.h"
//drh 2018/1/26 23:35:37
typedef struct _IO_Init_Struct
{
	GPIO_TypeDef* GPIO_Port;
	GPIO_InitTypeDef IO_Init_Struct;
}IO_Init_Struct,*pIO_Init_Struct;





































#endif