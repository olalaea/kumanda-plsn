/*
 * io.c
 *
 *  Created on: 3 May 2018
 *      Author: Ayyuce
 */


#include "io_read_write.h"
#include "stm32f4xx.h"
#include "stdio.h"
#include "config.h"
#include "io_config.h"
#include "general_purpose_func.h"
#include "io_pin.h"
#include <stdio.h>
#include <stdlib.h>

char analog_message[ANALOG_MESSAGE_READ_SIZE+1]; uint8_t  digital_message[DIGITAL_MESSAGE_READ_SIZE+1]; // +1 nedir
char remote_message[SEND_MESSAGE_SIZE];
extern uint16_t ADC1ConvertedValue[ANALOG_PIN_AMOUNT];

void ReadAnalogPins(void){
	//DMA her bir analog degeri ADC1ConvertedValue[] arrayinin adresinde tutar.
	//ADC1ConvertedValue[] icerisindeki deger ADC_RegularChannelConfig() fonksiyonunda tanimladigimiz okuma sirasidir.
	shiftIntArray(STEERING.BUFFER);
	STEERING.BUFFER[0] = ADC1ConvertedValue[0];
	STEERING.VALUE = map1000(averageArray(STEERING.BUFFER));

	shiftIntArray(ACCEL_BRAKE.BUFFER);
	ACCEL_BRAKE.BUFFER[0] = ADC1ConvertedValue[1];
	ACCEL_BRAKE.VALUE = map1000(averageArray(ACCEL_BRAKE.BUFFER));

	sprintf(analog_message,"%04d%04d",STEERING.VALUE, ACCEL_BRAKE.VALUE);
}

void ReadDigitalPins(void){
	//bu fonksiyonda okunan tum digital degerler int tipinde Digital_IN_Buffer isminde bir arrayin icinde tutulmustur
	//bu arrayin tum elemanlari char tipinde digital_message isminde bir arrayin icine birebir kopyalanmistir
	uint8_t Digital_IN_Buffer[DIGITAL_MESSAGE_READ_SIZE];
	Digital_IN_Buffer[0]= !HAL_GPIO_ReadPin(HEADLIGHTS.PORT, HEADLIGHTS.PIN);
	Digital_IN_Buffer[1]= !HAL_GPIO_ReadPin(IR_LIGHTS.PORT, IR_LIGHTS.PIN);
	Digital_IN_Buffer[2]= !HAL_GPIO_ReadPin(TAIL_LIGHTS.PORT, TAIL_LIGHTS.PIN);
	Digital_IN_Buffer[3]= !HAL_GPIO_ReadPin(HAZARD_LIGHTS.PORT, HAZARD_LIGHTS.PIN);
	Digital_IN_Buffer[4]= !HAL_GPIO_ReadPin(IGNITION.PORT, IGNITION.PIN);
	Digital_IN_Buffer[5]= !HAL_GPIO_ReadPin(MANUAL_OVERRIDE.PORT, MANUAL_OVERRIDE.PIN);
	Digital_IN_Buffer[6]= !HAL_GPIO_ReadPin(HAND_BRAKE.PORT, HAND_BRAKE.PIN);
	Digital_IN_Buffer[7]= !HAL_GPIO_ReadPin(GEAR_D.PORT, GEAR_D.PIN);
	Digital_IN_Buffer[8]= !HAL_GPIO_ReadPin(GEAR_N.PORT, GEAR_N.PIN);
	Digital_IN_Buffer[9]= !HAL_GPIO_ReadPin(GEAR_R.PORT, GEAR_R.PIN);
	Digital_IN_Buffer[10]= !HAL_GPIO_ReadPin(GEAR_P.PORT, GEAR_P.PIN);
	Digital_IN_Buffer[11]= !HAL_GPIO_ReadPin(ENGINE_STARTER.PORT, ENGINE_STARTER.PIN);
	Digital_IN_Buffer[12]= !HAL_GPIO_ReadPin(SIGNAL_RIGHT.PORT, SIGNAL_RIGHT.PIN);
	Digital_IN_Buffer[13]= !HAL_GPIO_ReadPin(SIGNAL_LEFT.PORT, SIGNAL_LEFT.PIN);

	for (int i = 0; i < DIGITAL_MESSAGE_READ_SIZE; i++)
	{
		digital_message[i] = '0' + Digital_IN_Buffer[i];
	}
}

void WriteDigitalPins(void){ // karsidan mesaj alindiginda ledler yanacak hale getir
	HAL_GPIO_WritePin(LED_GEAR_P.PORT, LED_GEAR_P.PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GEAR_N.PORT, LED_GEAR_N.PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GEAR_D.PORT, LED_GEAR_D.PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GEAR_R.PORT, LED_GEAR_R.PIN, GPIO_PIN_SET);
}

void beatHeart(void){
	HAL_GPIO_TogglePin(BLINK.PORT, BLINK.PIN);
}

void CreateRemoteMessage(void){
	int counter_interim=0;

	remote_message[0]=PREFIX;
	remote_message[1]=DIGITAL_PREFIX;

	for(counter_interim=0; counter_interim<14; counter_interim++){
		remote_message[counter_interim+2]=digital_message[counter_interim];
	}
	remote_message[18]=ANALOG_PREFIX;

	for(counter_interim=0; counter_interim<12; counter_interim++){
			remote_message[counter_interim+19]=analog_message[counter_interim];
		}
	remote_message[25]=SUFFIX;
}

