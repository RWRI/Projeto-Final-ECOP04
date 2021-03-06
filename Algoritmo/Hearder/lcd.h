// -----------------------------------------------------------------------
//   Copyright (C) Rodrigo Almeida 2010
// -----------------------------------------------------------------------
//   Arquivo: lcd.h
//            Header da biblioteca de manipula??o do LCD
//   Autor:   Rodrigo Maximiano Antunes de Almeida
//            rodrigomax at unifei.edu.br
//   Licen?a: GNU GPL 2
// -----------------------------------------------------------------------
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// -----------------------------------------------------------------------

#ifndef LCD_H
	#define LCD_H

    #define L_ON	0x0F
    #define L_OFF	0x08
    #define L_CLR	0x01
    #define L_L1	0x80
    #define L_L2	0xC0
    #define L_L3	0x90
    #define L_L4	0xD0
    #define L_CR	0x0F		
    #define L_NCR	0x0C

	void lcdCommand(unsigned char cmd);
	void lcdData(unsigned char valor);
	void lcdInit(void);
        
#endif