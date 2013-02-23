typedef struct {
unsigned char H;
unsigned char M;
unsigned char S;
} t_timer;

typedef unsigned char byte;

extern t_timer T1;

void printTimer(byte x, byte y, t_timer tim);
void addSecond(t_timer *tim);