#include "stdio.h"
#include "config.h"
#include "lcd.h"

void printf(char f[],int t){
    lcdInit();
    lcdCommand(L_CLR);
    int i;
    char linha[4] = {0x80,0xC0,0x90,0xD0}, l = 0;
    lcdInit();
    for(i = 0;i<t;i++){
        if(f[i]=='\n'){
            i++;
            lcdCommand(linha[l]);
            l++;
        }
        lcdData(f[i]);
    }
}
