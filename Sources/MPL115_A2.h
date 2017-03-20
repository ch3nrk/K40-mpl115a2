/*
 * MPL115_A2.h
 *
 *  Created on: Oct 22, 2016
 *      Author: ja
 */

#ifndef MPL115_A2_H_
#define MPL115_A2_H_


#include "Events.h"

#define COEFF     0x04 //komenda - wczytaj wspolczynniki
#define CONVER 	  0x12 //komenda - przelicz temp. i cis. na adc
#define TEMP_PRES 0x00 //komenda - wczytaj temp. i cis.


typedef struct {
	
	float cisnienie; //kPa
	float temperatura;//nie liczymy
	float max_nacisk;
	//pomiary adc
	uint16_t P; //cisnienie
	uint16_t T; //temperatura
	//wspolczynniki
	float a0; //offset cisnienia
	float b1; //czulosc cisnienia
	float b2; //wspolczynnik temp od offsetu (TCO)
	float c12;//wspolczynnik temp od czulosci(TCS)
	float wsp_a;//wspolczynnik kierunkowy nacisku 
	float wsp_b; //wartosc cisnienia bez nacisku 
	
}MPL115A2;

void Wczytaj_wspolczynniki0(MPL115A2 * wsk);
void Wyslij_rozkaz0();
void Sczytaj_dane0(MPL115A2 * wsk);
void Wczytaj_wspolczynniki1(MPL115A2 * wsk);
void Wyslij_rozkaz1();
void Sczytaj_dane1(MPL115A2 * wsk);
float kalibracja(char bufor[8]);

#endif /* MPL115_A2_H_ */
