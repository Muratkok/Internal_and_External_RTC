/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APPRTC_H__
#define __APPRTC_H__

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stdio.h"
#include "string.h"


/* USER CODE BEGIN Includes */
#define MILLENNIUM 2000
/* USER CODE END Includes */


extern char time[20];


//void set_time (void);
void adjustInternalRTC(void);
void set_time (RTC_TimeTypeDef *sTime,RTC_DateTypeDef *sDate);
void get_current_RTC(void); 

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__APPRTC_H__ */
