#include <ioCC2530.h>
#include <intrinsics.h>


#define LED1 P0_1    
extern void IO_Init(void);
extern void delay(void);
extern void T0(void);
extern void T1(void);
extern void REST(void);
extern void Sendcolor(unsigned int r,unsigned int g,unsigned int b) ;
extern void Twinkle(void);
extern void Dela_200ms(void);
