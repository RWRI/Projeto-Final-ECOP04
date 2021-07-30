//Discente: Ryan Wyllyan Ribeiro Inácio
//Matrícula: 2020001770

#include "stdio.h"
#include "delay.h"
#include "menu.h"

#ifndef INFO_H
#define	INFO_H

void info(){
    logo();
    char msg[48] = "  Iogurteira\n \n \nCapacidade 1000L\nCriada em 2021";
    printf(msg,48);
    delay(5);
    logo();
}

#endif

