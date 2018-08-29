/*
 * general_purpose_func.c
 *
 *  Created on: 24 Mar 2018
 *      Author: Ayyuce
 */

#include "stm32f4xx.h"
#include "stdio.h"
#include "general_purpose_func.h"
#include "config.h"
#include "can.h"

uint16_t CAN_mesaji_toplam_uzunluk=72;
uint8_t mesaj_state=BASLA;
uint8_t mesaj_data[CAN_MESAJ_ALMA_SIZE];
uint8_t mesaj[CAN_MESAJ_ALMA_SIZE];

uint16_t qos=0;
uint16_t paket_no=0;
uint8_t mesaj_tipi=0;
uint8_t slave_adres=0;
/*Char arrayin tum elemanlarini 0lamak icin kullanilir*/
void zeroArray(char array[], uint8_t length){
	for (uint8_t var = 0; var < length; ++var) {
		array[var] = 0;
	}
}

/* Kaynak arrayden hedef arraya, belirtilen uzunluk ve baslangic noktasindan kopyalama yapar */
void copyArray(char to[], char from[], uint8_t length, uint8_t start){
	for (uint8_t var = 0; var < length; ++var) {
		to[var] = from[var + start];
	}
}

/* 0 - 4096 arasinda degisen bir degeri 0-100 arasina oranlar*/
uint8_t scale100(uint16_t param){
	uint8_t value;
	value = (param/4095.0f)*100.0f;
	return value;
}

/* Parametre verilen arrayin tum elemanlarindan aritmetik ortalama hesaplar*/
uint16_t averageArray(uint16_t par[]){
	uint32_t sum=0; uint8_t i=0;
	while(i<SAMPLING_RATE){
		sum += par[i];
		i++;
	}
	return sum/SAMPLING_RATE;
}


/* Analog samandira bilgisi okunduktan sonra ilgili maksimum minimum degerlerine gore 0 - 100 arasindaki bir degere oranlar.
 *  ZYA Arac Samandirasi icin kullanilir
 */
uint8_t scale(uint16_t param){
	if(param<620){
		param = 620;
	} else if (param>3225){
		param = 3225;
	}
	param -= 620;
	uint8_t value;
	value = (param/2605.0f)*100.0f;
	return value;
}


/* Parametre verilen arrayin elemanlarini bir adip saga kaydirir*/
void shiftIntArray(uint16_t param[]){
	for (uint8_t var = SAMPLING_RATE - 1; var > 0; --var) {
		param[var] = param[var - 1];
	}
	param[0] = 0;
}

uint16_t map1000(uint16_t analog_read_value){

	uint16_t JOYSTICK1_ORTA= (JOYSTICK1_MAX-JOYSTICK1_MIN)/2;

	if (analog_read_value > (JOYSTICK1_ORTA - JOYSTICK1_DEADBAND) && analog_read_value < (JOYSTICK1_ORTA + JOYSTICK1_DEADBAND)){
		analog_read_value = JOYSTICK1_ORTA;
	} else if (analog_read_value <50) {
		analog_read_value = JOYSTICK1_MIN;
	} else if (analog_read_value > 4020){
		analog_read_value= JOYSTICK1_MAX;
	}

	return ((JOYSTICK1_SET_MAX-JOYSTICK1_SET_MIN)*(analog_read_value-JOYSTICK1_MIN)/(JOYSTICK1_MAX-JOYSTICK1_MIN)) + JOYSTICK1_SET_MIN;
}

uint8_t Mesaj_dogrulama(void)
{
	uint16_t counter=0, counter_data=0;
	uint8_t mesaj_data_uzunluk=0;
	uint8_t checksum_hesaplanan=0, checksum_okunan=0, timestamp;

	while(counter<CAN_mesaji_toplam_uzunluk)
	{
		switch(mesaj_state)
		{
			case BASLA:
				if(mesaj[counter]==STX)
					mesaj_state=ADRES;
				counter++;
				break;
			case ADRES:
				if(mesaj[counter]==ADR2||mesaj[counter]==ADR1)
				{
					if(mesaj[counter]==ADR2)
						mesaj_tipi=INDIR_KALDIR_GONDERISI;
					else
						mesaj_tipi=KULE_GONDERISI;
					slave_adres=mesaj[counter];
					mesaj_state=DATA;
				}
				else
				{	mesaj_state=BASLA;
					qos++;
				}
					counter++;
				break;
			case DATA:
				mesaj_data_uzunluk=mesaj[counter];
				counter++;
				for(counter_data=0;counter_data<mesaj_data_uzunluk;counter_data++)
				{
					mesaj_data[counter_data]=mesaj[counter];
					checksum_hesaplanan+= mesaj_data[counter_data];
					counter++;
				}
				checksum_okunan= mesaj[counter];
				counter++;
				timestamp= mesaj[counter];
				counter++;
				mesaj_state=SON;
				break;
			case SON:
				if(mesaj[counter]==ETX)
					mesaj_state=CHECKSUM;
				else
				{	mesaj_state=BASLA;
					qos++;
				}
				counter++;
				break;
			case CHECKSUM:
				checksum_hesaplanan=checksum_hesaplanan+mesaj_data_uzunluk+timestamp;
				if(checksum_hesaplanan!=checksum_okunan)
				{
					mesaj_state=BASLA;
					qos++;
					counter++;
					//PARSE_mesaj_data[countr_data];
				}
				else
				{
					mesaj_state=BASLA;
					paket_no++;
					//(PARSE_mesaj_data[counter_data])
					return 1; //mesaj bitti dogru paket mesaj_data icinde dondu.
				}
				break;
			default:
				break;

			}//switch
	}//while
	return 0; //mesaj bitti, dogru paketi bulamadik
}


void copyChar(char to[], char from[], uint8_t length, uint8_t start){
	for (uint8_t var = 0; var < length; ++var) {
		to[var] = from[var + start];
	}
}
