/*
 * main.c
 *
 *  Created on: Apr 18, 2022 12:16:49 AM
 *      Author: mahmoud ramadan 
 */
#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"
#include"HAL/HCLCD/HCLCD_Interface.h"
#include"HAL/CLOCK/CLOCK_Interface.h"
#include"MCAL/MTIMER0/MTIMER0_Config.h"
#include"MCAL/MTIMER0/MTIMER0_Interface.h"
#include"MCAL/MGIE/MGIE_Interface.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include<util/delay.h>

int main(void)
{
	/*Initialize LCD PINS*/
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RS_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RW_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,E_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN6,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN7,PIN_OUTPUT);
	HAL_VidHCLCD_4BitModeInit();
	MTIMER0_VidTimerOverFlow_SetCallBack(App_Tov);
	MGIE_Enable();
	MTIMER0_VidInit();


	while(1)
	{
		Clock_vidShowDay();
		Clock_VidDisplayTime();
	}
	return 0;
}
