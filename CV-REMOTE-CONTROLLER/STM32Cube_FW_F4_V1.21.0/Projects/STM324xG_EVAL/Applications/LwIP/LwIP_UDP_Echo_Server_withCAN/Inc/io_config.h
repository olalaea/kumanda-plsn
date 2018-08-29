/*
 * io_config.h
 *
 *  Created on: 8 May 2018
 *      Author: USER
 */

#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

#include <stdint.h>
#include "config.h"
#include "stm32f4xx.h"

void ADC_DMA_CONFIG(void);
void DIGITAL_IN_CONFIG(void);
void DIGITAL_OUT_CONFIG(void);
void CAN1_CONFIG(void);
void USART2_CONFIG(uint32_t baudrate);
void ADC_CHANNEL_CONFIG (uint32_t ADC_CHANNEL, uint32_t RANK, uint32_t ADC_SAMPLETIME_xCYCLES, uint32_t OFFSET);

typedef struct DIGITAL_IO_PINS {
	uint8_t INDEX;						// Buffer Array Index
	uint16_t PIN;							// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
	uint8_t BUFFER[SAMPLING_RATE];	// Buffer array for error corection
	uint8_t VALUE;						// Final pin value
}DIGITAL_IO_PIN;

typedef struct ANALOG_IO_PINS {
	uint8_t INDEX;						// Buffer Array Index
	uint16_t PIN;							// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
	uint16_t BUFFER[SAMPLING_RATE];	// Buffer array for Moving average
	uint16_t VALUE;						// Final pin value
}ANALOG_IO_PIN;

typedef struct USART2_GPIO_PINS {
	uint16_t PIN;							// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
}USART2_GPIO_PIN;


typedef struct CAN_IO_PINS {
	uint16_t PIN;					// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;		// GPIO Port name, ex = GPIOC, GPIOD
}CAN_IO_PIN;

extern char sendUSART2[DEBUG_SEND_MESSAGE_SIZE], readUSART2[DEBUG_READ_MESSAGE_SIZE];

extern ANALOG_IO_PIN STEERING;			extern ANALOG_IO_PIN ACCEL_BRAKE;	

extern DIGITAL_IO_PIN HEADLIGHTS;		extern DIGITAL_IO_PIN IR_LIGHTS;					extern DIGITAL_IO_PIN TAIL_LIGHTS;		extern DIGITAL_IO_PIN HAZARD_LIGHTS;
extern DIGITAL_IO_PIN IGNITION;			extern DIGITAL_IO_PIN MANUAL_OVERRIDE;		extern DIGITAL_IO_PIN HAND_BRAKE;			extern DIGITAL_IO_PIN GEAR_D;
extern DIGITAL_IO_PIN GEAR_N;				extern DIGITAL_IO_PIN GEAR_R;							extern DIGITAL_IO_PIN GEAR_P;					extern DIGITAL_IO_PIN ENGINE_STARTER;
extern DIGITAL_IO_PIN SIGNAL_RIGHT;	extern DIGITAL_IO_PIN SIGNAL_LEFT;

extern DIGITAL_IO_PIN LED_GEAR_P;			extern DIGITAL_IO_PIN LED_GEAR_D;			extern DIGITAL_IO_PIN LED_GEAR_R;
extern DIGITAL_IO_PIN LED_GEAR_N;			extern DIGITAL_IO_PIN BLINK;
extern USART2_GPIO_PIN USART2_Tx; 		extern USART2_GPIO_PIN USART2_Rx;

extern UART_HandleTypeDef Uart2Handle;

#endif /* IO_CONFIG_H_ */
