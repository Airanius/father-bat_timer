#include "board.h"

void sendQ(void);

enum {KEY_FREE = 0, 
      KEY_SCAN1,
      KEY_SCAN2,
      KEY_SCAN3,
      KEY_PRESSED
      };

void Keypad_init(void){
    Y1 = 0;
    Y2 = 0;
    Y3 = 0;
};

uint8_t Keys_sates[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const char Keys_nums[12] = {'1', '4', '7', 'T', '2', '5', '8', 'R', '3', '6', '9', '0'};
uint8_t Outputs = 0;

void Keypad_scan(void){
static uint8_t step = 0;
static uint16_t new_state;
uint8_t i;
bit key;
static bit reset = 0;
char str[13];
str[12] = 0;
    
    switch(step++){
    case 0:
        Y1 = 1; Y3 = 0;
        new_state = 0;
        break;
        
    case 1:
        new_state = Keyb_X;
        break;
        
    case 2:
        Y2 = 1; Y1 = 0;
        break;
        
    case 3:
        new_state += Keyb_X << 4;
        break;
        
    case 4:
        Y3 = 1; Y2 = 0;
        break;
        
    case 5:
        new_state += Keyb_X << 8;
        break;
    
    default:
        sendQ();
        for (i = 0; i < 12; i++){
            key = new_state & 1;
            str[i] = key + '0';
            new_state >>= 1;
            if (key && Keys_sates[i] != KEY_PRESSED){
                Keys_sates[i]++;
                if (Keys_sates[i] == KEY_PRESSED){
                    if (reset){
                        lcd_putchar('-');
                        reset = 0;
                        resetQ(Keys_nums[i] - '0');
                    }             
                    else{
                        setQ(Keys_nums[i] - '0');
                    }
                    if (i == 7) {
                        reset = 1;
                    }
                    //todo: handle event key down
                    lcd_putchar(Keys_nums[i]);
                }
            }
            if (key == 0){
                Keys_sates[i] = KEY_FREE;
            }
        }        
        step = 0;
    }
}

void setQ(uint8_t num){
    if (num != 0 && num < 9)
        Outputs |= 1 << (num - 1);
}

void resetQ(uint8_t num){
    if (num != 0 && num < 9)
        Outputs &= ~(1 << (num - 1));
}

void sendQ(void){
    SPDR = Outputs;
}
