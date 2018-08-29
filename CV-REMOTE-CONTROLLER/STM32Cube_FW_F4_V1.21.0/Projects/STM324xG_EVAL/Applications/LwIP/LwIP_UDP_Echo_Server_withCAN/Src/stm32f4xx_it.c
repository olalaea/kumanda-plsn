/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
#include "can.h"
#include "config.h"
#include "io_config.h"
#include "usart_config.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
	NVIC_SystemReset();
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

extern ADC_HandleTypeDef AdcHandle;
uint32_t heartbeatCounter = 0;
uint32_t motorCounter = 0;
uint32_t udpMessageTimeout = 0;
extern uint8_t resetFlag;
uint32_t resetCounter = 0;
uint32_t messageCAN_timeout_counter = 0;
uint32_t telemetriCounter = 0;
uint32_t uart6recvTimeout=0, uart5recvTimeout=0, uart2recvTimeout=0;

uint16_t testCounter=0, init_counter=0, measure_counter=0;

void SysTick_Handler(void)
{
  /* Update the LocalTime by adding 1 ms each SysTick interrupt */
	init_counter++;
	measure_counter++;
  heartbeatCounter++;
  uart2recvTimeout++;
  udpMessageTimeout++;
  if (resetFlag) resetCounter++;
  messageCAN_timeout_counter++;
  telemetriCounter++;
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}
/**
  * @brief  This function handles EXTI15_10
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void) 
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
* @brief  This function handles CAN1 RX0 interrupt request.
* @param  None
* @retval None
*/
void ADCx_DMA_IRQHandler(void)
{
  HAL_DMA_IRQHandler(AdcHandle.DMA_Handle);
}

void CAN1_RX0_IRQHandler(void)
{
  HAL_CAN_IRQHandler(&CanHandle);
}

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&Uart2Handle);
}


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
