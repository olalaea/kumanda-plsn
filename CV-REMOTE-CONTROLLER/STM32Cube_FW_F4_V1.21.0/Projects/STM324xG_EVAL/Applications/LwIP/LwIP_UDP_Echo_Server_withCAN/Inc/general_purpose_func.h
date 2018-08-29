/*
 * general_purpose_func.h
 *
 *  Created on: 24 Mar 2018
 *      Author: USER
 */

#ifndef GENERAL_PURPOSE_FUNC_H_
#define GENERAL_PURPOSE_FUNC_H_
#include <stdint.h>

static void copyArray(char to[], char from[], uint8_t length, uint8_t start);
static void zeroArray(char array[], uint8_t length);
void shiftCharArray(uint8_t param[]);
void shiftIntArray(uint16_t param[]);
uint8_t isAllSame(uint8_t par[]);
uint16_t averageArray(uint16_t par[]);

void zeroChar(char array[], uint8_t length);
void copyChar(char to[], char from[], uint8_t length, uint8_t start);

uint8_t Mesaj_dogrulama(void);
uint8_t scale100(uint16_t param);
uint16_t map1000(uint16_t analog_read_value);

extern uint8_t acil_durum;


#endif /* GENERAL_PURPOSE_FUNC_H_ */
