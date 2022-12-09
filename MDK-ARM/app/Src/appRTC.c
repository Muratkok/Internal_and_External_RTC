
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    appRTC.c
  * @brief   This file provides code for the configuration
  *          of the RTC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

#include "appRTC.h"
extern RTC_HandleTypeDef hrtc;
char getCurrentTime[20] = {0};
char getCurrentDate[20] = {0};

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

void set_time (RTC_TimeTypeDef *sTime,RTC_DateTypeDef *sDate) 
{ 
	//sTime->Seconds = 0;//second
	RTC_TimeTypeDef tempTime;
	RTC_DateTypeDef tempDate;
  tempTime.Hours = sTime->Hours; // set hours 
  tempTime.Minutes = sTime->Minutes; // set minutes 
  tempTime.Seconds = sTime->Seconds; // set seconds 
  tempTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE; 
  tempTime.StoreOperation = RTC_STOREOPERATION_RESET; 
  if (HAL_RTC_SetTime(&hrtc, &tempTime, RTC_FORMAT_BCD) != HAL_OK) 
  { 
    Error_Handler();
  } 
  tempDate.WeekDay = sDate->WeekDay; // 
 // day 
  tempDate.Month = sDate->Month; // 
 // month 
  tempDate.Date = sDate->Date; // date 
  tempDate.Year = sDate->Year; // year 
  if (HAL_RTC_SetDate(&hrtc, &tempDate, RTC_FORMAT_BCD) != HAL_OK) 
  { 
    Error_Handler();
  } 
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); // backup register 
}


void adjustInternalRTC(void)
{
	RTC_TimeTypeDef adjustTime;
	RTC_DateTypeDef adjustDate;
	
	adjustTime.Hours 		= 0x23;//it will be taken from the external RTC
	adjustTime.Minutes 	= 0x00;
	
	adjustDate.Date 		= 0x03;
	adjustDate.Month 		= 0x12;
	adjustDate.Year 		= 0x22;
	adjustDate.WeekDay 	= RTC_WEEKDAY_SATURDAY;	
	set_time(&adjustTime,&adjustDate);
}
void get_current_RTC(void) 
{ 
		RTC_TimeTypeDef currentTime; 
    RTC_DateTypeDef currentDate; 	   	 
		
		/* Get the RTC current Time */ 
    HAL_RTC_GetTime(&hrtc, &currentTime, RTC_FORMAT_BIN); 
		/* Get the RTC current Date */ 
    HAL_RTC_GetDate(&hrtc, &currentDate, RTC_FORMAT_BIN); 
    sprintf((char*)getCurrentTime,"%02d:%02d:%02d",currentTime.Hours, currentTime.Minutes, currentTime.Seconds); 

    sprintf((char*)getCurrentDate,"%02d/%02d/%2d",currentDate.Date, currentDate.Month, (MILLENNIUM + currentDate.Year)); 
		
}



