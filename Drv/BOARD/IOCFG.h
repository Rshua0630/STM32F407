#ifndef _IOCFG_H_
#define _IOCFG_H_

#include "stm32f4xx_gpio.h"
//drh 2018/1/26 23:35:37
typedef struct _IO_Init_Struct
{
	GPIO_TypeDef* GPIO_Port;
	GPIO_InitTypeDef IO_Init_Struct;
	BitAction Action; //only for output,if input mode please set to 0
}IO_Init_Struct,*pIO_Init_Struct;



#define GPIO_LCD_BL_PORT								GPIOB
#define GPIO_LCD_BL_PIN									GPIO_Pin_15

//#define GPIO_LCD_RESET_PORT					NRST

//ili 9431 8080-I 16bit interface
#define LCD_CSX_PORT										GPIOB//PG12  active low
#define LCD_CSX_PIN											GPIO_Pin_12	

#define LCD_DCX_PORT										GPIOF//PF12  data/cmd L:CMD H:DATA
#define LCD_DCX_PIN											GPIO_Pin_12

#define LCD_WRX_PORT										GPIOD//PD5  write rising edge 
#define LCD_WRX_PIN											GPIO_Pin_5

#define LCD_RDX_PORT										GPIOD//PD4	read rising edge				
#define LCD_RDX_PIN											GPIO_Pin_4



//public variable
extern uint32_t gIO_Init_Table_Size;
extern IO_Init_Struct IO_Init_Struct_Table[];

//public func
extern void IOCFG_Init(IO_Init_Struct * pio_init_table,uint32_t table_size);
























#endif