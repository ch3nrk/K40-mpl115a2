/*
 * dodatki.h
 *
 *  Created on: Oct 22, 2016
 *      Author: ja
 */

#ifndef DODATKI_H_
#define DODATKI_H_

#include "Events.h"
#include "MPL115_A2.h"


void negacja(int i);
int ktore_podlaczone(void);//spardzamy stan na pinach rst /'1'- cz. pod³aczony 
void wczytaj_wsp(void);
void petla(void);
void SoftwareReset(void);

#endif /* DODATKI_H_ */
