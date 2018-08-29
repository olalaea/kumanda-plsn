/*
 * config.h
 *
 *  Created on: 24 Mar 2018
 *      Author: Ayyuce
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32f4xx.h"

#define SAMPLING_RATE 	20 			// each moving average array have 20 element
#define CAN_KENDI_ADRESI	0x00E0

#define KULE_GONDERISI 0x13
#define INDIR_KALDIR_GONDERISI 0x45

#define USART2_RX_BUFFER_SIZE		1024
#define USART5_RX_BUFFER_SIZE		26
#define USART6_RX_BUFFER_SIZE		1024

#define BASLA 1
#define ADRES 2
#define DATA 3
#define SON 4
#define CHECKSUM 5
#define STX 0x82
#define ETX 0x80
#define ADR 0x00
#define ADR1 0x01
#define ADR2 0x02


#define MEASURE_TIME 	20		// Each 10 ms DMA status is controlled
#define SAMPLING_RATE 	20 		// Each moving average array have 20 element
#define MSG_TIME 		50 	 	// Each 50 ms all values are refreshed
#define UART_TIME		50
#define HEARTBEAT 		100		// Each 100 ms hearbeat led is toggled
#define TIMEOUT_TIME 	1000	// If control message doesn't come within 1000 ms timeout will occur, DEFAULT_MESSAGE is written to all output
#define MOTOR_DONUS_KONTROL_TIME 300
#define MOTOR_RESET_TIME 1000
#define ROLE_TIME 		3000
#define INIT_TIME 		1000	// First 2500 ms board is working to get steady
#define TELEMETRY						500		// Telemetry monitoring time

#define READ_MESSAGE_SIZE					26		// Received message size = 32
#define SEND_MESSAGE_SIZE					26		// Transmitted message size = 71
#define ANALOG_MESSAGE_READ_SIZE 	8
#define DIGITAL_MESSAGE_READ_SIZE 14
#define REMOTE_READ_SIZE					26				//Kumanda read mesajýnýn uzunlugu
#define REMOTE_WRITE_SIZE					26				//Kumanda write mesajýnýn uzunlugu

#define PREFIX 							'M'		// Control message Prefix
#define DIGITAL_PREFIX			'D'		// Digital message Prefix
#define ANALOG_PREFIX				'A'		// Analog message Prefix
#define SUFFIX 							'S'		// Suffix of control message

#define JOYSTICK1_DEADBAND	50		//joystick deadband degeri
#define JOYSTICK1_MIN				0			//joystick minimum degeri
#define JOYSTICK1_MAX				4096	//joystick maximum degeri
#define JOYSTICK1_SET_MIN 	0			//joysticki map etmek istedigimiz minimum degeri
#define JOYSTICK1_SET_MAX 	1000	//joysticki map etmek istedigimiz maximum degeri

#define DIGITAL_OUT_AMOUNT	5
#define DIGITAL_IN_AMOUNT		14		// Total number of used pins
#define ANALOG_PIN_AMOUNT		2			// Total number of used pins

#define DEBUG_READ_MESSAGE_SIZE		26	// USART2'de test icin kullanildi
#define DEBUG_SEND_MESSAGE_SIZE		26	// USART2'de test icin kullanildi

#define DEFAULT_MESSAGE			"DEFAULT MESSAGE\n"

/* Definition for ADCx clock resources */
#define ADCx                            ADC1
#define ADCx_CLK_ENABLE()               __HAL_RCC_ADC1_CLK_ENABLE()
#define DMAx_CLK_ENABLE()               __HAL_RCC_DMA2_CLK_ENABLE()     
#define ADCx_CHANNEL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
     
#define ADCx_FORCE_RESET()              __HAL_RCC_ADC_FORCE_RESET()
#define ADCx_RELEASE_RESET()            __HAL_RCC_ADC_RELEASE_RESET()

/* Definition for ADCx's Channel */
#define ADCx_CHANNEL_1                  ADC_CHANNEL_0
#define ADCx_CHANNEL_2                  ADC_CHANNEL_3

/* Definition for ADCx's DMA */
#define ADCx_DMA_CHANNEL                DMA_CHANNEL_0
#define ADCx_DMA_STREAM                 DMA2_Stream0

/* Definition for ADCx's NVIC */
#define ADCx_DMA_IRQn                   DMA2_Stream0_IRQn
#define ADCx_DMA_IRQHandler             DMA2_Stream0_IRQHandler


#define CAN_MESAJ_ALMA_SIZE 128

extern uint16_t testCounter, init_counter, measure_counter;
#endif /* CONFIG_H_ */
