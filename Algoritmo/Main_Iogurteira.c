//Discente: Ryan Wyllyan Ribeiro Inácio
//Matricula: 2020001770

#include "menu.h"
#include "info.h"
#include "produc.h"

void main(void) {
    char o;
    logo();
    for(;;){
        o = menu();
        if(o == 1) info();
        if(o == 2) producao();       
    }
    
}
