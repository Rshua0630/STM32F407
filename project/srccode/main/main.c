/*
@brief : main file
@by : Rshua
@Since : 20180123
**/

#include "IOCFG.h"

int main(void)
{
	unsigned int i = 0;
	IOCFG_Init(&IO_Init_Struct_Table[0],gIO_Init_Table_Size);
	while(1){
		i++;
	}
}
