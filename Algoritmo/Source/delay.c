//Discente: Ryan Wyllyan Ribeiro Inácio
//Matrícula: 2020001770

#include "delay.h"
#include "config.h"
#include "ssd.h"

void delay(char t){
    volatile unsigned char i, j, k, l, m;
    for(m = 0; m < t;m++){
        for(l = 0; l < 4;l++){
            for(j = 0;j < 250;j++){
                for(k = 0; k < 41;k++){
                    for(i = 0;i < 3;i++);
                }
            }
        }
    }
}

void delay_ms(unsigned int valor){
    unsigned int  i;
    unsigned char j;

    for (i =0; i< valor; i++){
      for (j =0 ; j < 200; j++);
    }
}

void cronometro(unsigned long int cont){
    ssdInit();
    
    cont *= 16100;
    cont += 16100;
    
    while(cont >= 16100){
        cont--;
        
        ssdDigit(((cont/16100)%10),3);//1 min
        ssdDigit(((cont/161000)%6),2);//10 min
        ssdDigit(((cont/966000)%10),1);//1 hora
        ssdDigit(((cont/9660000)%6),0);//10 horas
        
        ssdUpdate();
    }
}
