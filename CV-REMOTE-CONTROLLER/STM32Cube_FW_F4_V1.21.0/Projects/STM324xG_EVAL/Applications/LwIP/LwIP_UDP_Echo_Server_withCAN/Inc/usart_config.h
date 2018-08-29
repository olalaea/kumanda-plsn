/*
 * usart_2.h
 *
 *  Created on: 3 May 2018
 *      Author: Ayyuce
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#include "stm32f4xx.h"
#include "config.h"

extern UART_HandleTypeDef Uart5Handle;
extern UART_HandleTypeDef Uart6Handle;
extern UART_HandleTypeDef Uart2Handle;

extern uint8_t USART6_Rx_Buffer[USART6_RX_BUFFER_SIZE];
extern uint8_t USART5_Rx_Buffer[USART5_RX_BUFFER_SIZE];
extern char USART2_Rx_Buffer[USART2_RX_BUFFER_SIZE];

extern uint8_t pozisyon_mesaji_geldi;
extern uint32_t positionMessageSize;
extern uint32_t uart5recvIndex, uart6recvIndex, uart2recvIndex;
extern char position_message[USART5_RX_BUFFER_SIZE];
extern uint8_t usart5FirstRunFlag;


void USART2_CONFIG(uint32_t baudrate);
void USART5_CONFIG(uint32_t baudrate);
void USART6_CONFIG(uint32_t baudrate);

void writeUSART6Message(void);
void readUSART6Message(void);
void readGPSData(void);


#endif /* USART_2_H_ */
