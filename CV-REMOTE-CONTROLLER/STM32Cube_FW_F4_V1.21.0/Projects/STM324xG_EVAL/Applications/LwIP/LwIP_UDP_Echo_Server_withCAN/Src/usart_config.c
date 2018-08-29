/*
 * usart_config.c
 *
 *  Created on: 27 July 2018
 *      Author: Ayyuce
 */

#include "usart_config.h"
#include "stdio.h"
#include "config.h"
#include "string.h"
#include "stdlib.h"
#include "general_purpose_func.h"

UART_HandleTypeDef Uart6Handle;
UART_HandleTypeDef Uart5Handle;
UART_HandleTypeDef Uart2Handle;

uint8_t USART6_Rx_Buffer[USART6_RX_BUFFER_SIZE];
uint8_t USART5_Rx_Buffer[USART5_RX_BUFFER_SIZE];
char USART2_Rx_Buffer[USART2_RX_BUFFER_SIZE];

extern uint32_t  uart5recvTimeout, uart6recvTimeout, uart2recvTimeout;
uint32_t uart5recvIndex = 0, uart6recvIndex=0, uart2recvIndex = 0;

uint8_t gps_mesaj_geldi = 0;
uint8_t pozisyon_mesaji_geldi = 0;
uint32_t positionMessageSize  = 0;

uint8_t usart5FirstRunFlag = 0, usart6FirstRunFlag=0;

uint8_t sendUSART5[32];
char sendUSART6[32];
char readUSART6[32];


void USART2_GPIO_CONFIG (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;	// this is for the GPIO pins used as TX and RX
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6 ; // Pins 5 (TX) and 6 (RX) are used
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.Pull = GPIO_PULLUP;			// this activates the pullup resistors on the IO pins
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
}

void USART2_CONFIG(uint32_t baudrate)
{
	__HAL_RCC_USART2_CLK_ENABLE();
	USART2_GPIO_CONFIG();
	
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	
	Uart2Handle.Instance = USART2;
	
	Uart2Handle.Init.BaudRate 		= baudrate;
  Uart2Handle.Init.WordLength   = UART_WORDLENGTH_8B;
  Uart2Handle.Init.StopBits     = UART_STOPBITS_1;
  Uart2Handle.Init.Parity       = UART_PARITY_NONE;
  Uart2Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  Uart2Handle.Init.Mode         = UART_MODE_TX_RX;
  Uart2Handle.Init.OverSampling = UART_OVERSAMPLING_16;
	
	HAL_UART_Init(&Uart2Handle);
	
	__HAL_UART_ENABLE_IT(&Uart2Handle, UART_IT_RXNE);
	
	HAL_UART_Receive_IT(&Uart2Handle, (uint8_t *)&USART2_Rx_Buffer, 1);
}



void USART5_GPIO_CONFIG(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;	// this is for the GPIO pins used as TX and RX
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_12; 			// Pins 5 (TX) and 6 (RX) are used
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 		// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.Pull = GPIO_PULLUP;				// this activates the pullup resistors on the IO pins
	GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 		// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.Pull = GPIO_PULLUP;				// this activates the pullup resistors on the IO pins
	GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

void USART5_CONFIG(uint32_t baudrate)
{
	__HAL_RCC_UART5_CLK_ENABLE();
	USART5_GPIO_CONFIG();
	
	HAL_NVIC_SetPriority(UART5_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(UART5_IRQn);
	
	Uart5Handle.Instance = UART5;
	
	Uart5Handle.Init.BaudRate 		= baudrate;
  Uart5Handle.Init.WordLength   = UART_WORDLENGTH_8B;
  Uart5Handle.Init.StopBits     = UART_STOPBITS_1;
  Uart5Handle.Init.Parity       = UART_PARITY_NONE;
  Uart5Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  Uart5Handle.Init.Mode         = UART_MODE_TX_RX;
  Uart5Handle.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&Uart5Handle);
	__HAL_UART_ENABLE_IT(&Uart5Handle, UART_IT_RXNE);
	usart5FirstRunFlag = 1;
	HAL_UART_Receive_IT(&Uart5Handle, (uint8_t *)USART5_Rx_Buffer, USART5_RX_BUFFER_SIZE);
}

void updateUSART5Write(void){
	HAL_UART_Transmit_IT(&Uart5Handle, (uint8_t *) sendUSART5, 2);
}

void USART6_GPIO_CONFIG (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;	// this is for the GPIO pins used as TX and RX
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_InitStruct.Pin = GPIO_PIN_6| GPIO_PIN_7 ; // Pins 5 (TX) and 6 (RX) are used
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.Pull = GPIO_PULLUP;			// this activates the pullup resistors on the IO pins
	GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
}

void USART6_CONFIG(uint32_t baudrate)
{
	__HAL_RCC_USART6_CLK_ENABLE();
	USART6_GPIO_CONFIG();
	
	HAL_NVIC_SetPriority(USART6_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(USART6_IRQn);
	
	Uart6Handle.Instance = USART6;
	
	Uart6Handle.Init.BaudRate 		= baudrate;
  Uart6Handle.Init.WordLength   = UART_WORDLENGTH_8B;
  Uart6Handle.Init.StopBits     = UART_STOPBITS_1;
  Uart6Handle.Init.Parity       = UART_PARITY_NONE;
  Uart6Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  Uart6Handle.Init.Mode         = UART_MODE_TX_RX;
  Uart6Handle.Init.OverSampling = UART_OVERSAMPLING_16;
	
	HAL_UART_Init(&Uart6Handle);
	
	__HAL_UART_ENABLE_IT(&Uart6Handle, UART_IT_RXNE);
	
	HAL_UART_Receive_IT(&Uart6Handle, (uint8_t *)USART6_Rx_Buffer, 1);
}

void writeUSART6Message(void){
	HAL_UART_Transmit_IT(&Uart6Handle, (uint8_t *) sendUSART6, 2);
}

void readUSART6Message(void){
	
		HAL_UART_Receive_IT(&Uart6Handle, (uint8_t *)USART6_Rx_Buffer, USART6_RX_BUFFER_SIZE);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if (UartHandle->Instance == UART5)
	{
		HAL_UART_Receive_IT(&Uart5Handle, (uint8_t *)USART5_Rx_Buffer, USART5_RX_BUFFER_SIZE);
		uart5recvTimeout = 0;
		pozisyon_mesaji_geldi = 1;
	}
	
	if (UartHandle->Instance == USART6)
	{
		HAL_UART_Receive_IT(&Uart6Handle, (uint8_t *)&USART6_Rx_Buffer[uart6recvIndex], 1);
		uart6recvIndex++;
		if (uart6recvIndex >= USART6_RX_BUFFER_SIZE) uart6recvIndex = 0;
		uart6recvTimeout = 0;
	}
	
	if (UartHandle->Instance == USART2)
	{
		HAL_UART_Receive_IT(&Uart2Handle, (uint8_t *)&USART2_Rx_Buffer[uart2recvIndex], 1);
		uart2recvIndex++;
		if (uart2recvIndex >= USART2_RX_BUFFER_SIZE) uart2recvIndex = 0;
		uart2recvTimeout = 0;
	}
}


