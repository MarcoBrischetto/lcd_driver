/* 
 * File: example.c
 *
 * Copyright (c) 2015 Manolis Agkopian
 * See the file LICENSE for copying permission.
 *
 * LCD library example code.
 */

// You can change the _XTAL_FREQ if you want, but don't forget to change it in the lcd.c too
#define _XTAL_FREQ 4000000

// In this example the configuration bits are set specifically for the PIC16F876A, if you use a different microcontroller you may have to update them
// Tip: MplabX has a tool to easily auto generate the pragma directives (Main Menu, Window -> PIC Memory Views -> Configuration Bits)
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3/PGM pin io, low voltage programming disabled)
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <xc.h>

#include "lcd.h"

int main ( void ) {
    LCD lcd = { &PORTC, 0, 1, 2, 3, 4, 5 }; // PORT, RS, EN, D4, D5, D6, D7

    LCD_Init(lcd);
    
    while(1){

        LCD_Clear();
        LCD_Set_Cursor(1,0);
        LCD_putrs("HELLO");
        
		for ( unsigned char i = 0; i < 100; ++i ) { // 1s Delay
		 	__delay_ms(10);
		 }

	}

    return (EXIT_SUCCESS);
}

