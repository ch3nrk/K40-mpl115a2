/*
 * dodatki.c
 *
 *  Created on: Oct 22, 2016
 *      Author: ja
 */

#include "dodatki.h"
#include "MyUART.h"


MPL115A2 tab[12]={0};
bool conn[12]={0};
extern bool pusty_bufor;

void negacja(int i){
	
	switch(i){
	
	case 0:
		CZ1_NegVal();
		break;
	case 1:
		CZ2_NegVal();
		break;
	case 2:
		CZ3_NegVal();
		break;
	case 3:
		CZ4_NegVal();
		break;
	case 4:
		CZ5_NegVal();
		break;
	case 5:
		CZ6_NegVal();
		break;	
	case 6:
		CZ7_NegVal();
		break;
	case 7:
		CZ8_NegVal();
		break;
	case 8:
		CZ9_NegVal();
		break;
	case 9:
		CZ10_NegVal();
		break;
	case 10:
		CZ11_NegVal();
		break;
	case 11:
		CZ12_NegVal();
		break;
	}
}


int ktore_podlaczone(void){
	
	  int i,il_cz=0,roz=0;
	  byte wiadomosc[30];
	  byte tmp[4];
	  word ptrr;
	  
	  CZ1_SetInput();
	  if(CZ1_GetVal()){il_cz++;conn[0]=1;}
	  CZ2_SetInput();
	  if(CZ2_GetVal()){il_cz++;conn[1]=1;}
	  CZ3_SetInput();
	  if(CZ3_GetVal()){il_cz++;conn[2]=1;}
	  CZ4_SetInput();
	  if(CZ4_GetVal()){il_cz++;conn[3]=1;}
	  CZ5_SetInput();
	  if(CZ5_GetVal()){il_cz++;conn[4]=1;}
	  CZ6_SetInput();
	  if(CZ6_GetVal()){il_cz++;conn[5]=1;}
	  CZ7_SetInput();
	  if(CZ7_GetVal()){il_cz++;conn[6]=1;}
	  CZ8_SetInput();
	  if(CZ8_GetVal()){il_cz++;conn[7]=1;}
	  CZ9_SetInput();
	  if(CZ9_GetVal()){il_cz++;conn[8]=1;}
	  CZ10_SetInput();
	  if(CZ10_GetVal()){il_cz++;conn[9]=1;}
	  CZ11_SetInput();
	  if(CZ11_GetVal()){il_cz++;conn[10]=1;}
	  CZ12_SetInput();
	  if(CZ12_GetVal()){il_cz++;conn[11]=1;}
	  
	  CZ1_SetOutput();CZ2_SetOutput();CZ3_SetOutput();CZ4_SetOutput();CZ5_SetOutput();CZ6_SetOutput();
	  CZ1_PutVal(0);CZ2_PutVal(0);CZ3_PutVal(0);CZ4_PutVal(0);CZ5_PutVal(0);CZ6_PutVal(0);
	  
	  CZ7_SetOutput();CZ8_SetOutput();CZ9_SetOutput();CZ10_SetOutput();CZ11_SetOutput();CZ12_SetOutput();
	  CZ7_PutVal(0);CZ8_PutVal(0);CZ9_PutVal(0);CZ10_PutVal(0);CZ11_PutVal(0);CZ12_PutVal(0);	  
	  
/*	  strcpy(wiadomosc,"b");
	  for(i=0;i<12;i++){
		  
	      if(conn[i]){
	    	  
	    	strcpy(tmp,"");
	    	sprintf(tmp,"%d,",i+1);
	    	strcat(wiadomosc,tmp);
	    	}
	  }
	  strcat(wiadomosc,"c");
	  roz=strlen(wiadomosc);
	  MyUART_SendBlock(wiadomosc,roz,&ptrr); 
	*/  
	  return il_cz;
}


void wczytaj_wsp(void){
	
  	 int i;
	
	 for(i=0;i<6;i++){
		  if(conn[i]){
			  negacja(i);  
			  Wczytaj_wspolczynniki0(&tab[i]);
			  negacja(i);
		  } 
	  }
	  for(i=6;i<12;i++){
	  	  if(conn[i]){
	  		  negacja(i);
	  		  Wczytaj_wspolczynniki1(&tab[i]);
	  		  negacja(i);
	  	  } 
	  }	
}


void rozkazy(void){
	
	int i;
	for(i=0;i<12;i++)
		if(conn[i]){
			negacja(i);	  
			tab[i].P=tab[i].T=0;	
		}
	  
	Wyslij_rozkaz0();
	Wyslij_rozkaz1();	
	  
	for(i=0;i<12;i++) if(conn[i]) negacja(i); 	
	
}


void petla(void){
	
	 int32_t j;
	 byte wiadomosc[150]={0};
	 byte tmp[7];
	 word ptrr;
	 int roz,i,stan=1,flaga=0;
	 
	 MyUART_ClearRxBuf();
	 MyUART_ClearTxBuf();
	 		
	 int ile_cz=ktore_podlaczone();
	 
	 pusty_bufor=1;
	 wczytaj_wsp();
	 rozkazy();
	 
	 for(;;){
		  
		  if(pusty_bufor){
			  
			  pusty_bufor=0;
			  	  
			  for(i=0;i<15000;i++);//oko³o 3ms
		  	  if(stan==1){//odczytujemy pomiar 
		  		  
		  		  for(i=0;i<6;i++){
		  			  
		  		      if(conn[i]){
		  		    	  
		  		    	negacja(i);
		  		    	
		  		    	if(!(tab[i].P)&&!(tab[i].T)){
		  		    		
		  		    		Sczytaj_dane0(&tab[i]);	
		  		    		flaga++;	
		  		    		tab[i].P=tab[i].T=0;
		  		    	} 
		  		    	
		  		    			  		    	
		  		    	negacja(i);
		  		     }
		  		  }    
		  		  for(i=6;i<12;i++){
		  			  
		  		      if(conn[i]){
		  		    	  		    	  
		  		    	negacja(i);
		  		    	
		  		    	if(!(tab[i].P)&&!(tab[i].T)){
		  		    		
		  		    		Sczytaj_dane1(&tab[i]);	
		  		    		flaga++;
		  		    		tab[i].P=tab[i].T=0;  	
		  		    	}  
		  		    		    		
		  		    	negacja(i); 
		  		      }  		      
		  		  }
		  		  
		  		  if(flaga==ile_cz){
		  			  
		  		    stan=2;
		  			flaga=0;
		  			
		  		  }	    	 
		  	 }	  
		  	 		  
		  	 if(stan==2){//wysy³amy przez UART
		
		  		 strcpy(wiadomosc,"a");
		  		 
		  		 for(i=0;i<12;i++){
		  			 
		  			if(conn[i]){
		  				
		  				strcpy(tmp,"");
		  				sprintf(tmp,"%3.1f,",tab[i].cisnienie);
		  				strcat(wiadomosc,tmp);
		  			}
		  			
		  			else strcat(wiadomosc,"0,");
		  		 }
		  		
		  	     strcat(wiadomosc,"x");
				 roz=strlen(wiadomosc);
		  		 MyUART_SendBlock(wiadomosc,roz,&ptrr);
		  		 stan=1;
		  	 }  
		  }
	 }
}


void SoftwareReset(void)
{
  /* Generic way to request a reset from software for ARM Cortex */
  /* See https://community.freescale.com/thread/99740
     To write to this register, you must write 0x5FA to the VECTKEY field, otherwise the processor ignores the write.
     SYSRESETREQ will cause a system reset asynchronously, so need to wait afterwards.
   */

  SCB_AIRCR = SCB_AIRCR_VECTKEY(0x5FA) | SCB_AIRCR_SYSRESETREQ_MASK;

  for(;;) {
    /* wait until reset */
  }
}
