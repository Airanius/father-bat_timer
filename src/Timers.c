#include <mega8.h>
#include <lcd.h>
#include "Timers.h"


t_timer T1 = {0,0,0};


void put_digit(byte digit){
    lcd_putchar(digit + '0');
}

void addSecond(t_timer *tim){
    tim->S++;
    if (tim->S == 60) {
        tim->S = 0;
        tim->M++;
        if (tim->M >= 60) {
            tim->M = 0;
            tim->H++;
        }
    }
}

void printTimer(byte x, byte y, t_timer tim){
    lcd_gotoxy(x,y);
    if (tim.H > 9){
        put_digit((tim.H / 10));
    }
    put_digit((tim.H % 10));
    lcd_putchar(':');
    put_digit((tim.M / 10));
    put_digit((tim.M % 10));
    lcd_putchar(':');
    put_digit((tim.S / 10));
    if (tim.H < 10){
        put_digit((tim.S % 10));
    }
}

