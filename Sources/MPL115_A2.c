/*
 * MPL115_A2.c
 *
 *  Created on: Apr 10, 2016
 *      Author: Administrator
 */

#include "MPL115_A2.h"
#include <math.h>


void Wczytaj_wspolczynniki0(MPL115A2 * wsk){

	word ptr;
	char bufor[8]={0};

	MPL115A2_0_SendChar(COEFF);
	MPL115A2_0_RecvBlock(bufor,8,&ptr) ;
	MPL115A2_0_SendStop();	
		
	float A0 = (bufor[0] * 256 + bufor[1]) / 8.0;
	float B1 = (bufor[2] * 256 + bufor[3]) / 8192.0;
	float B2 = (bufor[4] * 256 + bufor[5]) / 16384.0;
	float C12 = ((bufor[6] * 256 + bufor[7]) / 4) / 4194304.0;
	
	wsk->a0=A0;
	wsk->b1=B1;
	wsk->b2=B2;
	wsk->c12=C12;
	
	wsk->wsp_a=kalibracja(bufor);
			
	byte rozkaz[]={CONVER,TEMP_PRES};
	
	MPL115A2_0_SendBlock(rozkaz,2,&ptr);
	MPL115A2_0_SendStop();
	
	wsk->P=wsk->T=0;	
	
	uint32_t i;
	for(i=0;i<300000;i++);//oko³o 3ms
		
	byte buf[4];
			
	MPL115A2_0_SendChar(TEMP_PRES);
	MPL115A2_0_RecvBlock(buf,4,&ptr);
	MPL115A2_0_SendStop();
					
	wsk->P=((uint16_t)(buf[0]<<8)|buf[1])>>6;
	wsk->T=((uint16_t)(buf[2]<<8)|buf[3])>>6;
			
	float PComp=wsk->a0+(wsk->b1+wsk->c12*wsk->T)*wsk->P+wsk->b2*wsk->T;
				
	wsk->wsp_b=(0.0635*PComp+50.0f);
}


byte rozkaz[]={CONVER,TEMP_PRES};

void Wyslij_rozkaz0(){
	
	word ptr;
	
	MPL115A2_0_SendBlock(rozkaz,2,&ptr);
	MPL115A2_0_SendStop();
	
}


void Sczytaj_dane0(MPL115A2 * wsk){
	
	byte bufor[4];
	word ptr;	
	MPL115A2_0_SendChar(TEMP_PRES);
	MPL115A2_0_RecvBlock(bufor,4,&ptr);
	MPL115A2_0_SendBlock(rozkaz,2,&ptr);
	MPL115A2_0_SendStop();
		
	wsk->P=((uint16_t)(bufor[0]<<8)|bufor[1])>>6;
	wsk->T=((uint16_t)(bufor[2]<<8)|bufor[3])>>6;
	//wsk->P = (bufor[0] * 256 + (bufor[1] & 0xC0)) / 64;
	//wsk->P = (bufor[2] * 256 + (bufor[3] & 0xC0)) / 64;
	
	float PComp=wsk->a0+(wsk->b1+wsk->c12*wsk->T)*wsk->P+wsk->b2*wsk->T;
	
	
	wsk->cisnienie=((0.0635*PComp+50.0f)-wsk->wsp_b)/wsk->wsp_a;//uwzgledniamy kalibracje	
	
	if(wsk->cisnienie > -200.0f){
		
		wsk->cisnienie*=0.098f;//jednostka 1/100 [N]
		if(wsk->max_nacisk < wsk->cisnienie) wsk->max_nacisk=wsk->cisnienie;
		//wsk->cisnienie=roundf(wsk->cisnienie);
	}
	else wsk->cisnienie=wsk->max_nacisk;
	
}


void Wczytaj_wspolczynniki1(MPL115A2 * wsk){
	
	word ptr;
	char bufor[8]={0};

	MPL115A2_1_SendChar(COEFF);
	MPL115A2_1_RecvBlock(bufor,8,&ptr);
	MPL115A2_1_SendStop();	
		
	float A0 = (bufor[0] * 256 + bufor[1]) / 8.0;
	float B1 = (bufor[2] * 256 + bufor[3]) / 8192.0;
	float B2 = (bufor[4] * 256 + bufor[5]) / 16384.0;
	float C12 = ((bufor[6] * 256 + bufor[7]) / 4) / 4194304.0;
	
	wsk->a0=A0;
	wsk->b1=B1;
	wsk->b2=B2;
	wsk->c12=C12;
	
	wsk->wsp_a=kalibracja(bufor);
			
	byte rozkaz[]={CONVER,TEMP_PRES};
	
	MPL115A2_1_SendBlock(rozkaz,2,&ptr);
	MPL115A2_1_SendStop();
	
	wsk->P=wsk->T=0;	
	
	uint32_t i;
	for(i=0;i<300000;i++);//oko³o 3ms
		
	byte buf[4];
			
	MPL115A2_1_SendChar(TEMP_PRES);
	MPL115A2_1_RecvBlock(buf,4,&ptr);
	MPL115A2_1_SendStop();
					
	wsk->P=((uint16_t)(buf[0]<<8)|buf[1])>>6;
	wsk->T=((uint16_t)(buf[2]<<8)|buf[3])>>6;
			
	float PComp=wsk->a0+(wsk->b1+wsk->c12*wsk->T)*wsk->P+wsk->b2*wsk->T;
				
	wsk->wsp_b=(0.0635*PComp+50.0f);
}


void Wyslij_rozkaz1(){
	
	word ptr;
	
	MPL115A2_1_SendBlock(rozkaz,2,&ptr);
	MPL115A2_1_SendStop();
	
}


void Sczytaj_dane1(MPL115A2 * wsk){
	
	byte bufor[4];
	word ptr;	
	MPL115A2_1_SendChar(TEMP_PRES);
	MPL115A2_1_RecvBlock(bufor,4,&ptr);
	MPL115A2_1_SendBlock(rozkaz,2,&ptr);
	MPL115A2_1_SendStop();
		
	wsk->P=((uint16_t)(bufor[0]<<8)|bufor[1])>>6;
	wsk->T=((uint16_t)(bufor[2]<<8)|bufor[3])>>6;
	//wsk->P = (bufor[0] * 256 + (bufor[1] & 0xC0)) / 64;
	//wsk->P = (bufor[2] * 256 + (bufor[3] & 0xC0)) / 64;
	
	float PComp=wsk->a0+(wsk->b1+wsk->c12*wsk->T)*wsk->P+wsk->b2*wsk->T;
	

	wsk->cisnienie=((0.0635*PComp+50.0f)-wsk->wsp_b)/wsk->wsp_a;//uwzgledniamy kalibracje	
	
	if(wsk->cisnienie > -200.0f){
		
		wsk->cisnienie*=0.098f;//jednostka 1/100 [N]
		if(wsk->max_nacisk < wsk->cisnienie) wsk->max_nacisk=wsk->cisnienie;
		//wsk->cisnienie=roundf(wsk->cisnienie);
	}
	else wsk->cisnienie=wsk->max_nacisk;
}


float kalibracja(char bufor[8]){

	float WSP_A[7]={ 0.0932, 0.0717, 0.1423, 0.0594, 0.0294, 0.0909, 0.0474 };	
	
	char WSP[7][8]={
			{81,54,-100,-121,-79,101,71,-60},
			{70,34,-87,-119,-62,-104,60,96},
			{66,-58,-81,-89,-69,-11,56,72},
			{72,-107,-90,-30,-66,64,62,8},
			{75,-104,-91,50,-82,6,65,8},
			{65,-31,-80,-87,-66,98,52,-8},
			{65,92,-79,79,-65,27,53,-68}
	};
	
	int i,j,l;
	
	for(i=0;i<7;i++){
		l=0;
		for(j=0;j<8;j++){
			if(WSP[i][j]==bufor[j]) l++;
		}
		
		if(l==8) return WSP_A[i];
	}
	
	return 0.1f;//brak, przypisujemy wsp uniwerslany 
}


