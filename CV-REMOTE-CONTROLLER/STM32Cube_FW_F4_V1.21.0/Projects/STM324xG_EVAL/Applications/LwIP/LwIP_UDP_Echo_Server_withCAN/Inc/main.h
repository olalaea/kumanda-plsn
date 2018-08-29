/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm324xg_eval.h"
#include "stm324xg_eval_lcd.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
//#define USE_LCD        /* enable LCD  */
//#define USE_DHCP       /* enable DHCP, if disabled static address is used */

/*Static IP ADDRESS: IP_ADDR0.IP_ADDR1.IP_ADDR2.IP_ADDR3 */
#define IP_ADDR0   (uint8_t) 192
#define IP_ADDR1   (uint8_t) 168
#define IP_ADDR2   (uint8_t) 1
#define IP_ADDR3   (uint8_t) 11
	 
#define REMOTE_IP_ADDR0   (uint8_t) 192
#define REMOTE_IP_ADDR1   (uint8_t) 168
#define REMOTE_IP_ADDR2   (uint8_t) 1
#define REMOTE_IP_ADDR3   (uint8_t) 10

#define TELEMETRY_IP_ADDR0   (uint8_t) 192
#define TELEMETRY_IP_ADDR1   (uint8_t) 168
#define TELEMETRY_IP_ADDR2   (uint8_t) 1
#define TELEMETRY_IP_ADDR3   (uint8_t) 122
   
/*NETMASK*/
#define NETMASK_ADDR0   (uint8_t) 255
#define NETMASK_ADDR1   (uint8_t) 255
#define NETMASK_ADDR2   (uint8_t) 255
#define NETMASK_ADDR3   (uint8_t) 0

/*Gateway Address*/
#define GW_ADDR0   (uint8_t) 192
#define GW_ADDR1   (uint8_t) 168
#define GW_ADDR2   (uint8_t) 1
#define GW_ADDR3   (uint8_t) 1

#define UDP_SERVER_PORT    10546  	/* define the UDP local connection port */
#define UDP_CLIENT_PORT    10546	/* define the UDP remote connection port */
#define UDP_TELEMTRY_PORT  11000

 /* Definition for TIMx clock resources */

 #define TIMx_CLK_ENABLE                __HAL_RCC_TIM3_CLK_ENABLE

 /* Definition for TIMx's NVIC */
 #define TIMx_IRQn                      TIM3_IRQn
 #define TIMx_IRQHandler                TIM3_IRQHandler

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

