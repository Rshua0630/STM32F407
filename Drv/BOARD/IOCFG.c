/*
@brief : config board io status
@since : 20180128
@by : Rshua
**/
#include "stdio.h"
#include "stm32f4xx_conf.h"
#include "IOCFG.h"
 
const static IO_Init_Struct IO_Init_Struct_Table[] =
{
	{GPIOA,{GPIO_Pin_0,GPIO_Mode_IN,GPIO_Speed_2MHz,GPIO_OType_PP,GPIO_PuPd_NOPULL}},
};

const uint32_t gIO_Init_Table_Size = sizeof(IO_Init_Struct_Table) / sizeof(IO_Init_Struct); 

void IOCFG_Init(IO_Init_Struct * pio_init_table,uint32_t table_size)
{
	uint32_t temp = 0;
	//IO_Init_Struct a;
	if(pio_init_table == NULL) return ;
	for(temp = 0; temp < table_size; temp ++){
		//if(IS_GPIO_PIN()) break;
		GPIO_Init(pio_init_table[temp].GPIO_Port,&(pio_init_table[temp].IO_Init_Struct));
	}
}



