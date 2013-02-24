#ifndef __BOARD_H__
#define __BOARD_H__

#include <mega8.h>
#include "inttypes.h"
#include <spi.h>
#include <lcd.h>

#define Y1 PORTD.3
#define Y2 PORTB.0
#define Y3 PORTB.1
#define Keyb_X (PINC & 0x0F)

extern void Keypad_init(void);
extern void Keypad_scan(void);
extern void Perepherial_init(void);

#endif //__BOARD_H__
