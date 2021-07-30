//Discente: Ryan Wyllyan Ribeiro Inácio
//Matrícula: 2020001770

#include "menu.h"
#include "stdio.h"
#include <pic18f4520.h>
#include "bits.h"
#include "delay.h"
#include "lcd.h"

char menu(void){
    printf("      Menu\n \n \n(1) Informacoes\n(4) Produzir\n",43);
    return opcao();
}

char opcao(void){
    bitClr(INTCON2, 7); //liga pull up
    ADCON1 = 0x0E; //config AD
    
    TRISB = 0xFE; //config da porta B
    PORTB = 0x00; //config da porta B
    
    TRISA = 0x00; //config da porta A  
    PORTA = 0x00;//deixa todos os displays deligados
    
    TRISD = 0xFF;//config da porta D
    
    for(;;){
        if(PORTD == 0xF7){//detecta tecla 1
            return 1;
        }
        if(PORTD == 0xFB){//detecta tecla 4
            return 2;
        }
        if(PORTD == 0xFD){//detecta tecla 7
            return 3;
        }
        if(PORTD == 0xFE){//detecta tecla *
            return 4;
        }
    }
}

void logo(void){
    lcdInit();
    
    char i, g[48] = {
    0x01, 0x03, 0x03, 0x0E, 0x1C, 0x18, 0x08, 0x08, 
    0x11, 0x1F, 0x00, 0x01, 0x1F, 0x12, 0x14, 0x1F, 
    0x10, 0x18, 0x18, 0x0E, 0x07, 0x03, 0x02, 0x02, 
    0x08, 0x18, 0x1C, 0x0E, 0x03, 0x03, 0x01, 0x00, 
    0x12, 0x14, 0x1F, 0x08, 0x00, 0x1F, 0x11, 0x00, 
    0x02, 0x03, 0x07, 0x0E, 0x18, 0x18, 0x10, 0x00 
    };
    lcdCommand(0x40);
    for(i = 0;i < 48;i++){
        lcdData(g[i]);
    }
    for(i = 0;i < 14;i++){        
        lcdCommand(L_CLR);
        lcdCommand(L_L1+i);
        lcdData(0);
        lcdData(1);
        lcdData(2);
        lcdCommand(L_L2+i);
        lcdData(3);
        lcdData(4);
        lcdData(5);
        lcdCommand(0x9D-i);
        lcdData(0);
        lcdData(1);
        lcdData(2);
        lcdCommand(0xDD-i);
        lcdData(3);
        lcdData(4);
        lcdData(5);
        delay_ms(400);
    }
}
