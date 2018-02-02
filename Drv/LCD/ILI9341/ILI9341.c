/*
@brief : ILI9341 interface API  base on 8080-I 16bit
@since : 2018/1/27 10:29:10
@by : Rshua
**/
#include "ILI9341.h"
#include "IOCFG.h"

/*
@brief : lcd open 
@since : 2018/2/1 0:03:49
**/
void DRV_LCD_OPEN(void)
{
	LCD_CSX_Status(0);//CS active low 
}

/*
@brief : please follow the right action DRV_LCD_OPEN -> DRV_LCD_Init
**/
void DRV_LCD_Init(void)
{
	
}


/*
@brief : ILI9341 read write interface
@since : 2018/2/2 22:59:26
**/
void DRV_LCD_WR_CMD(uint16_t cmd)
{
	LCD_CSX_Status(0);// CSX   active low
	LCD_DCX_Status(0);// D/XC  active low when selete to write cmd
	LCD_WRX_Status(0);// WRX   parpare to write cmd 
	// copy cmd to gpio pin
	LCD_OUT(cmd);
	
	LCD_WRX_Status(1); // WRX  finish to write cmd
	LCD_DCX_Status(1); // reset D/XC to write data status 
}

void DRV_LCD_WR_DATA(uint16_t data)
{
	LCD_CSX_Status(0);// CSX   active low
	LCD_DCX_Status(1);// D/XC  active high when selete to write data 
	LCD_WRX_Status(0);// WRX   parpare to write data 
	//copy data to gpio pin
	LCD_OUT(data);
	
	LCD_WRX_Status(1); // WRX  finish to write cmd
	LCD_DCX_Status(1); // reset D/XC to write data status
}

uint16_t DRV_LCD_READ_DATA(uint16_t reg)
{
	DRV_LCD_WR_CMD(reg);//if want to read reg data , write reg frist
	LCD_CSX_Status(0);// CSX   active low
	LCD_DCX_Status(1);// D/XC  active high when selete to read data
	
	//set data pin(gpio) to input status 
	LCD_DIR_INPUT();
	
	LCD_RDX_Status(0); //the frist time read is invaild
	LCD_RDX_Status(1);
	
	LCD_RDX_Status(0); //the second time read is vaild
	LCD_RDX_Status(1);
	
	//read data
	LCD_READ();
		
	//set data pin(gpio) back to output status
	LCD_DIR_OUTPUT();
}