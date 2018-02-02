#ifndef _ILI9341_H_
#define _ILI9341_H_

#include "stm32f4xx_gpio.h"
#include "IOCFG.h"

#define ILI9341_CMD_DELAY 				0
#define ILI9341_CMD_CMD 					1
#define ILI9341_CMD_DATA 					2


typedef struct _ILI_9431_PARAM{
	uint32_t type; //write cmd or write data
	uint32_t data;
}ILI_9431_PARAM;



//Write read Cycle Sequence related
#define LCD_CSX_Status(x)			((x) > 0)?(LCD_CSX_PORT->BSRRL = LCD_CSX_PIN):(LCD_CSX_PORT->BSRRH = LCD_CSX_PIN)		

#define LCD_DCX_Status(x)			((x) > 0)?(LCD_DCX_PORT->BSRRL = LCD_DCX_PIN):(LCD_DCX_PORT->BSRRH = LCD_DCX_PIN)

#define LCD_WRX_Status(x)			((x) > 0)?(LCD_WRX_PORT->BSRRL = LCD_WRX_PIN):(LCD_WRX_PORT->BSRRH = LCD_WRX_PIN)
	
#define LCD_RDX_Status(x)			((x) > 0)?(LCD_RDX_PORT->BSRRL = LCD_RDX_PIN):(LCD_RDX_PORT->BSRRH = LCD_RDX_PIN)	


//set lcd data pin to output status
#define LCD_DIR_OUTPUT()

//set lcd data pin input status
#define LCD_DIR_INPUT()

//lcd data out ->  gpio set 
#define LCD_OUT(x)

//lcd data in -> gpio read
#define LCD_READ()






















#endif
