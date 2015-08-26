#include "LED.h" 


void IO_Init(void)
{
  P0DIR |= 0x02;     //P1_0定义为输出
  P0INP |= 0X02;     //打开下拉
}


void delay()
{int i;
  for(i=0;i<50;i++);
}

void T0()
{
  LED1 = 1;
  __no_operation();
  __no_operation();   
  LED1 = 0;
}

void T1()
{
  LED1 = 1;  
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  __no_operation();
  LED1 = 0;
}

void REST()
{
  LED1 = 0;
  delay();
}
void Sendcolor(unsigned int r,unsigned int g,unsigned int b)
{   IO_Init();
  unsigned int a[24]={0},p=0,j=0,k=0,n;
  
    
       for(p=0;p<8;p++){
      a[p]=((g<<p)&0x80);
      
       }
       for(j=0;j<8;j++){
      a[j+8]=((r<<j)&0x80);
      
       }
       for(k=0;k<8;k++){
      a[k+16]=((b<<k)&0x80);
      
       }
       for(n=0;n<24;n++)
       {
        if(a[n]==0) T0();
        else T1();

       }
  LED1 = 1;
  REST();

}
void Dela_200ms()
{
int i,j;
     for(i=0;i<20;i++)
     {
     for(j=0;j<17740;j++);
     }
}
void Twinkle()
{
 int j=100,i=0,k=0,a=0;
    while(j--){
    for(i=0;i<25;i++) {Sendcolor(i*10,255-i*10,255);Dela_200ms();}
    for(k=0;k<25;k++) {Sendcolor(255,k*10,i*10-k*10);Dela_200ms();}
    for(a=0;a<25;a++) {Sendcolor(255-a*10,255,a*10);Dela_200ms();}
    for(k=0;k<25;k++) {Sendcolor(k*10,255-k*10,255);Dela_200ms();}
    for(k=0;k<25;k++) {Sendcolor(255,k*10,255-k*10);Dela_200ms();}
    for(k=0;k<25;k++) {Sendcolor(255-k*10,255,k*10);Dela_200ms();}
    
    }}