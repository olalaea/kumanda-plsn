/*
 * definition.h
 *
 *  Created on: 28 ?ub 2017
 *      Author: Ugur
 */

#ifndef DEFINITION_H_
#define DEFINITION_H_

#include "stm32f4xx.h"

//#define BOMBA_ATAR_ON

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
#define PREFIX 			'M'		// Control message Prefix
#define DIGITAL_PREFIX 	'D'		// Prefix for digital part of control message
#define ANALOG_PREFIX 	'A'		// Prefix for analog part of control message
#define SUFFIX 			'\n'	// Suffix of control message

#define ANALOG_MESSAGE_SIZE		24
#define DIGITAL_MESSAGE_SIZE	10
#define ETHERNET_READ_SIZE		38
#define ETHERNET_WRITE_SIZE		87//82

#define JOTSTICK1_DEADBAND	50		//joystick deadband degeri
#define JOYSTICK1_MIN		0		//joystick minimum degeri
#define JOYSTICK1_MAX		4096	//joystick maximum degeri
#define JOYSTICK1_SET_MIN 	0		//joysticki map etmek istedigimiz minimum degeri
#define JOYSTICK1_SET_MAX 	1000	//joysticki map etmek istedigimiz maximum degeri

#define DEFAULT_MESSAGE			"MD0000004096A204804550000000000000500\n"
#define ZERO_MESSAGE			"0000000000000000000000000000000000000\n"

#define PWM_PIN_AMOUNT 			4		// Total number of used pins

#ifdef BOMBA_ATAR_ON
	#define DIGITAL_PIN_AMOUNT	26	// Total number of used pins
#else
	#define DIGITAL_PIN_AMOUNT	23	// Total number of used pins
#endif

typedef struct DIGITAL_IO_PINS {
	uint8_t INDEX;					// Buffer Array Index
	uint16_t PIN;					// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
	uint8_t BUFFER[SAMPLING_RATE];	// Buffer array for Moving average
	uint8_t VALUE;					// Final pin value
}DIGITAL_IO_PIN;

typedef struct ANALOG_IO_PINS {
	uint8_t INDEX;					// Buffer Array Index
	uint16_t PIN;					// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
	uint16_t BUFFER[SAMPLING_RATE];	// Buffer array for Moving average
	uint16_t VALUE;					// Final pin value
}ANALOG_IO_PIN;

typedef struct PWM_IO_PINS {
	uint8_t INDEX;					// Buffer Array Index
	uint16_t PIN;					// Pin Number, ex = GPIO_Pin_12
	GPIO_TypeDef* PORT;				// GPIO Port name, ex = GPIOC, GPIOD
	uint8_t VALUE;					// Final pin value
}PWM_IO_PIN;

void zeroArray(char array[], uint8_t length);
void copyArray(char to[], char from[], uint8_t length, uint8_t start);
uint8_t scale100(uint16_t param);
uint16_t averageArray(uint16_t par[]);
uint8_t scale(uint16_t param);
uint16_t map1000(uint16_t analog_read_value);
void shiftIntArray(uint16_t param[]);
extern uint8_t acil_durum;

#endif /* DEFINITION_H_ */


