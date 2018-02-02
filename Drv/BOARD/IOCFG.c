/*
@brief : config board io status
@since : 20180128
@by : Rshua
**/
#include "stdio.h"
#include "stm32f4xx_conf.h"
#include "IOCFG.h"

//#define GPIO_
 
IO_Init_Struct IO_Init_Struct_Table[] =
{
	{GPIO_LCD_BL_PORT,{GPIO_LCD_BL_PIN,GPIO_Mode_OUT,GPIO_Speed_2MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL},Bit_SET},
	{LCD_CSX_PORT,{LCD_CSX_PIN,GPIO_Mode_OUT,GPIO_Speed_25MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL},Bit_SET},
	{LCD_DCX_PORT,{LCD_DCX_PIN,GPIO_Mode_OUT,GPIO_Speed_25MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL},Bit_SET},
	{LCD_WRX_PORT,{LCD_WRX_PIN,GPIO_Mode_OUT,GPIO_Speed_25MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL},Bit_SET},
	{LCD_RDX_PORT,{LCD_RDX_PIN,GPIO_Mode_OUT,GPIO_Speed_25MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL},Bit_SET},
};

uint32_t gIO_Init_Table_Size = sizeof(IO_Init_Struct_Table) / sizeof(IO_Init_Struct); 

void IOCFG_Init(pIO_Init_Struct pio_init_table,uint32_t table_size)
{
	uint32_t temp = 0;
	//IO_Init_Struct a;
	if(pio_init_table == NULL) return ;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
		
	for(temp = 0; temp < table_size; temp ++){
		//if(IS_GPIO_PIN()) break;
		GPIO_Init(pio_init_table[temp].GPIO_Port,&(pio_init_table[temp].IO_Init_Struct));
		if(pio_init_table[temp].IO_Init_Struct.GPIO_Mode == GPIO_Mode_OUT){
			GPIO_WriteBit(pio_init_table[temp].GPIO_Port,pio_init_table[temp].IO_Init_Struct.GPIO_Pin,pio_init_table[temp].Action);
		}
	}
}



