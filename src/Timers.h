#ifndef __TIMER_H__
#define __TIMER_H__

#include "board.h"

typedef struct {
uint8_t H;
uint8_t M;
uint8_t S;
} t_timer;

extern t_timer T1;

void printTimer(uint8_t x, uint8_t y, t_timer tim);
void addSecond(t_timer *tim);

#endif //__TIMER_H__