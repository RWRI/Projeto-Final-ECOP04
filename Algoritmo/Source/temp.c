//Discente: Ryan Wyllyan Ribeiro Inácio
//Matrícula: 2020001770

#include <pic18f4520.h>
#include "temp.h"
#include "delay.h"
#include "lcd.h"
#include "adc.h"
#include "stdio.h"

void itoa(unsigned int val, char* st) {
    st[0] = (val / 10000) + 0x30;
    st[1] = ((val % 10000) / 1000) + 0x30;
    st[2] = ((val % 1000) / 100) + 0x30;
    st[3] = ((val % 100) / 10) + 0x30;
    st[4] = (val % 10) + 0x30;
    st[5] = 0;
}

unsigned char i;
unsigned int tmp, tmpd;
char str[6];

void aquecer(unsigned char valor){
    tmpd = 0;
    //transformando de char para int
    for(i = 0;i < valor;i++) tmpd++;
    
    TRISA = 0xC3;
    TRISB = 0x03;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    ADCON1 = 0x06;
    
    TRISA = 0x07;

    adc_init();
    lcdInit();
    
    lcdCommand(L_CLR);
    
    printf("    CUIDADO!\n \n \n   Aquecendo",29);
    
    PORTCbits.RC5 = 1;//liga o aquecedor

    while(1) {
        tmp = adc_amostra(1)*5;
        lcdCommand(L_L4 + 5);
        itoa(tmp, str);
        lcdData(str[2]);
        lcdData(str[3]);
        lcdData(',');
        lcdData(str[4]);
        lcdData(' ');  
        lcdData('C');        
        lcdData(0xDF);//°
        delay_ms(10);
        if(tmp/10 >= tmpd){
            break;
        }
        if(tmp/10 == 79){//desvio da limitação do picsimLab
            while(tmp/10 < tmpd){
                tmp += 5;
                lcdCommand(L_L4 + 5);
                itoa(tmp, str);
                lcdData(str[2]);
                lcdData(str[3]);
                lcdData(',');
                lcdData(str[4]);
                lcdData(' ');  
                lcdData('C');        
                lcdData(0xDF);//°
                delay(3);
            }
            break;
        }
    }
    
    if(tmpd != 90) PORTCbits.RC5 = 0;//desliga o aquecedor
    
    printf("\n  Temperatura\n    atingida",27);
    lcdCommand(L_L3 + 5);
    lcdData(str[2]);
    lcdData(str[3]);
    lcdData(',');
    lcdData(str[4]);
    lcdData(' ');  
    lcdData('C');        
    lcdData(0xDF);//°
    delay(3);
    
}
void resfriar(unsigned char valor){
    tmpd = 0;
    //transformando de char para int
    for(i = 0;i < valor;i++) tmpd++;
    
    TRISA = 0xC3;
    TRISB = 0x03;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    ADCON1 = 0x06;
    
    TRISA = 0x07;

    adc_init();
    lcdInit();
    
    lcdCommand(L_CLR);
    
    PORTCbits.RC5 = 0;//desliga o aquecedor caso esteja ligado
    PORTCbits.RC2 = 1;//liga o cooler
    
    printf("\n \n   Resfriando",16);

     while(1)  {
        tmp = adc_amostra(1)*5;
        lcdCommand(L_L3 + 5);
        itoa(tmp, str);
        lcdData(str[2]);
        lcdData(str[3]);
        lcdData(',');
        lcdData(str[4]);
        lcdData(' ');
        lcdData('C');
        lcdData(0xDF);//°
        delay_ms(10);
        if((tmp+5)/10 <= tmpd){
            break;
        }
    }

    PORTCbits.RC2 = 0;//desliga o cooler
    
    printf("\n  Temperatura\n    atingida",27);
    lcdCommand(L_L3 + 5);
    lcdData(str[2]);
    lcdData(str[3]);
    lcdData(',');
    lcdData(str[4]);
    lcdData(' ');  
    lcdData('C');        
    lcdData(0xDF);//°
    delay(3);
}

	

