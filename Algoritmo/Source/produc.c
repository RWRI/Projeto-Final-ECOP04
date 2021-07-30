//Discente: Ryan Wyllyan Ribeiro Inácio
//Matrícula: 2020001770

#include <pic18f4520.h>
#include "stdio.h"
#include "delay.h"
#include "produc.h"
#include "menu.h"
#include "temp.h"

#define LigaMotor PORTCbits.RC0 ^= 1//liga o motor pelo relé 1
#define DesligaMotor PORTCbits.RC0 = 0

 char p, q, o;
 
 void passar(){
    delay(1);//debounce
    for(;;){
       o = opcao();
       if(o == 1){
            break;
       }
    }
 }

void producao() {
    char i;
    
    //configurações do relé
    TRISCbits.TRISC0 = 0;
    TRISEbits.TRISE0 = 0;
    
    printf("\n \n    Producao\n  iniciando...\n",30);
    delay(1);
    
    printf("    Produto:\n \n \n1 Iogurte\n4 Bebida Lactea",46);
    p = opcao();
    if(p == 1){
        printf("\n \n    Iogurte\n  selecionado\n\n",28);
    }else{
        printf("\n \n Bebiba Lactea\n  selecionada\n",31);
    }
    delay(2);
    
    printf("   Quantidade:\n \n \n(1)25%   (4)50%\n(7)75%   (*)100%",55);
    q = opcao();
    switch(q){
        case 1: printf("\n Capacidade que\n sera produzida\n       25%",43); break;
        case 2: printf("\n Capacidade que\n sera produzida\n       50%",43); break;
        case 3: printf("\n Capacidade que\n sera produzida\n       75%",43); break;
        case 4: printf("\n Capacidade que\n sera produzida\n       100%",44); break;
        default : printf("\n ERRO!\n",7); break;
    }
    delay(3);
    
    if(p == 1){
        switch(q){
            case 1: printf("\n    Adicione\n 250 L de leite\n \n(1)ir",41); break;
            case 2: printf("\n    Adicione\n 500 L de leite\n \n(1)ir",41); break;
            case 3: printf("\n    Adicione\n 750 L de leite\n \n(1)ir",41); break;
            case 4: printf("\n    Adicione\n 1000 L de leite\n \n(1)ir",42); break;
            default : printf("\n ERRO!\n",7); break;
        }
        passar();
    }else if(p == 2){
        switch(q){
            case 1: printf("\n    Adicione\n 125 L de soro\n \n(1)ir",40); break;
            case 2: printf("\n    Adicione\n 250 L de soro\n \n(1)ir",40); break;
            case 3: printf("\n    Adicione\n 375 L de soro\n \n(1)ir",40); break;
            case 4: printf("\n    Adicione\n 500 L de soro\n \n(1)ir",40); break;
            default : printf("\n ERRO!\n",7); break;
        }
        passar();
    }
    
    switch(q){
        case 1: printf("\n    Adicione\n12,5Kg de acucar\n \n(1)ir",38); break;
        case 2: printf("\n    Adicione\n25 Kg de acucar\n \n(1)ir",37); break;
        case 3: printf("\n    Adicione\n37,5Kg de acucar\n \n(1)ir",38); break;
        case 4: printf("\n    Adicione\n50 Kg de acucar\n \n(1)ir",37); break;
        default : printf("\n ERRO!\n",7); break;
    }
    passar();
    
    switch(q){
        case 1: printf("\n  Adicione 500g\nde estabilizante\n \n(1)ir",41); break;
        case 2: printf("\n  Adicione 1 kg\nde estabilizante\n \n(1)ir",41); break;
        case 3: printf("\n Adicione 1,5kg\nde estabilizante\n \n(1)ir",41); break;
        case 4: printf("\n  Adicione 2 kg\nde estabilizante\n \n(1)ir",41); break;
        default : printf("\n ERRO!\n",7); break;
    }
    passar();
    
    printf("\n    Iniciar\n homogeneizacao\n \n(1)ir",40);
    passar();
    printf("\n \n   Aguarde!!",15);
    
    LigaMotor;
    cronometro(3);
    DesligaMotor;
    
    printf("\n    Iniciar\n  aquecimento\n \n(1)ir",34);
    passar();
    
    if(p == 2){
        //elevar até 65°
        aquecer(65);
        switch(q){
            case 1: printf("\n    Adicione\n 125 L de leite\n \n(1)ir",41); break;
            case 2: printf("\n    Adicione\n 250 L de leite\n \n(1)ir",41); break;
            case 3: printf("\n    Adicione\n 375 L de leite\n \n(1)ir",41); break;
            case 4: printf("\n    Adicione\n 500 L de leite\n \n(1)ir",41); break;
            default : printf("\n ERRO!\n",7); break;
        }
        passar();
        //eleva até 90°
        aquecer(90);
    }else{
        //eleva até 90°
        aquecer(90);
    }
    
    printf("\n \n   Aguarde!!",15);
    delay(1);
    //contador de 15 minutos
    cronometro(15);
    
    //abaixa até 36°
    resfriar(36);
    
    printf("\n   Adicione o\n    fermento\n \n(1)ir",35);
    passar();
    
    printf("\n \n   Aguarde!!",15);
    delay(1);
    //contador de 24 horas
    cronometro(1440);
    
    printf("\n    Iniciar\n homogeneizacao\n \n(1)ir",40);
    passar();
    
    printf("\n \n   Aguarde!!",15);
    delay(1);
    LigaMotor;
    cronometro(10);
    DesligaMotor;
    
    switch(q){
        case 1: printf("\n    Adicione\n  10kg de polpa\n    de fruta\n(1)ir",52); break;
        case 2: printf("\n    Adicione\n  20kg de polpa\n    de fruta\n(1)ir",52);; break;
        case 3: printf("\n    Adicione\n  30kg de polpa\n    de fruta\n(1)ir",52);; break;
        case 4: printf("\n    Adicione\n  40kg de polpa\n    de fruta\n(1)ir",52);; break;
        default : printf("\n ERRO!\n",7); break;
    }
    passar();
    
    switch(q){
        case 1: printf("\n  Adicione 200g\n  de sorbato de\n    potassio\n(1)ir",55); break;
        case 2: printf("\n  Adicione 400g\n  de sorbato de\n    potassio\n(1)ir",55); break;
        case 3: printf("\n  Adicione 600g\n  de sorbato de\n    potassio\n(1)ir",55); break;
        case 4: printf("\n  Adicione 800g\n  de sorbato de\n    potassio\n(1)ir",55); break;
        default : printf("\n ERRO!\n",7); break;
    }
    passar();
    
    printf("\n    Iniciar\n homogeneizacao\n \n(1)ir",36);
    passar();
    printf("\n \n   Aguarde!!",15);
    delay(1);
    
    LigaMotor;
    cronometro(15);
    DesligaMotor;
    
    printf("\n    Preparar\n   recipiente\n  para extracao\n(1)ir",53);
    passar();
    
    printf("\n \n  Extraindo...",17);
    delay(1);
    
    LigaMotor;
    TRISD = 0x00;
    TRISB = 0x00;
    PORTD = 0xFF;
    PORTB = 0xFF;
    for(i = 0;i < 9;i++){
        delay(5);
        PORTD = PORTD << 1;
        PORTB = PORTB << 1;
    }
    DesligaMotor;
    
    printf("\n    Producao\n    completa\n \n1 voltar ao menu",49);
    passar();
    logo();
}
