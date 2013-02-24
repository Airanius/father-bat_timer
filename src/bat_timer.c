/*****************************************************
This program was produced by the
CodeWizardAVR V2.04.4a Advanced
Automatic Program Generator
� Copyright 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : bat_timer
Version : 
Date    : 23.02.2013
Author  : ASV
Company : Home
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega8.h>
#include "Timers.h"
#include "inttypes.h"

extern void Perepherial_init(void);

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>

volatile bit flag = 1;

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer1 value
TCNT1=0x0BDB;
// Place your code here
    PORTD.3 ^= 1;
    addSecond(&T1);
    flag = 1;
}

// Declare your global variables here

void main(void)
{
    // Declare your local variables here

    Perepherial_init();
    
    // LCD module initialization
    lcd_init(16);

    // Global enable interrupts
    #asm("sei")


    while (1){
        // Place your code here
        if(flag){   
            flag = 0;
            printTimer(8, 1, T1);
        }
    };
}
