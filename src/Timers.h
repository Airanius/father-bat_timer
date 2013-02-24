#ifndef TIMER_H
#define TIMER_H

#include "inttypes.h"

typedef struct {
uint8_t H;
uint8_t M;
uint8_t S;
} t_timer;

extern t_timer T1;

void printTimer(uint8_t x, uint8_t y, t_timer tim);
void addSecond(t_timer *tim);

#endif TIMER_H