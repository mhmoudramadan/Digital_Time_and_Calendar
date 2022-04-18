/*
 * CLOCK_Program.c
 *
 *  Created on: Apr 18, 2022 12:35:50 AM
 *      Author: mahmoud ramadan 
 */


#include"../../LIB/LSTD_TYPES.h"
#include"../../HAL/HCLCD/HCLCD_Interface.h"
#include"CLOCK_Interface.h"

static uint8 copy_uint8Time[]="  :  :  ";
static uint8 copy_uint8calendar[]="  :  :20  ";
static uint8 copy_uint8Sec=0;
static uint8 copy_uint8Min=57;
static uint8 copy_uint8Hour=3;
static uint8 copy_uint8Day=3;
static uint8 copy_uint8Date=18;
static uint8 copy_uint8Month=4;
static uint8 copy_uint8year=20;

uint16 counts=0;

void Clock_VidCalculateTime(void *Pv)
{
	copy_uint8Sec++;
	if(copy_uint8Sec==60)
	{
		copy_uint8Sec=0;
		copy_uint8Min++;
	}
	if(copy_uint8Min==60)
	{
		copy_uint8Min=0;
		copy_uint8Hour++;
	}
	if(copy_uint8Hour==23)
	{
		copy_uint8Hour=0;
		copy_uint8Date++;
		copy_uint8Day++;
	}
	if(copy_uint8Day==8)
	{
		copy_uint8Day=1;
	}
	if(copy_uint8Date==31)
	{
		copy_uint8Date=0;
		copy_uint8Month++;
	}
	if(copy_uint8Month==13)
	{
		copy_uint8year++;
	}
	/*Time*/
	copy_uint8Time[7]=copy_uint8Sec%10 +48;
	copy_uint8Time[6]=copy_uint8Sec/10 +48;
	copy_uint8Time[4]=copy_uint8Min%10 +48;
	copy_uint8Time[3]=copy_uint8Min/10 +48;
	copy_uint8Time[1]=copy_uint8Hour%10 +48;
	copy_uint8Time[0]=copy_uint8Hour/10 +48;

	/*Calendar*/
	copy_uint8calendar[9]=copy_uint8year%10 +48;
	copy_uint8calendar[8]=copy_uint8year/10 +48;
	copy_uint8calendar[4]=copy_uint8Month%10 +48;
	copy_uint8calendar[3]=copy_uint8Month/10 +48;
	copy_uint8calendar[1]=copy_uint8Date%10 +48;
	copy_uint8calendar[0]=copy_uint8Date/10 +48;
}
void Clock_vidShowDay(void)
{
	switch(copy_uint8Day)
	{

		case 1:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"SatUrday");
		break;
		}
		case 2:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"SUNDAY");
			break;
		}
		case 3:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"MONDAY");
			break;
		}
		case 4:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"TUESDAY");
			break;
		}
		case 5:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"WEDNESDAY");
			break;
		}
		case 6:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"THURSDAY");
			break;
		}
		case 7:
		{
			HAL_VidHCLCD_4BitModeSetPosition(2,0);
			HAL_VidHCLCD_4BitModeWriteString((uint8*)"SatUrday");
			break;
		}
	}
}
void Clock_VidDisplayTime(void)
{

	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString(copy_uint8calendar);
	HAL_VidHCLCD_4BitModeSetPosition(2,8);
	HAL_VidHCLCD_4BitModeWriteString(copy_uint8Time);
}

void App_Tov(void)
{
	counts++;
	if(counts==1000)
	{
	Clock_VidCalculateTime(NULL);
	counts=0;
	}

}
