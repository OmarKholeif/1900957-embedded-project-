#include "Io.h"
#define NVIC_ST_CURRENT_R (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_R (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R (*((volatile unsigned long *)0xE000E014))
	


void LED_vInit()
	{
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R &= 0x20)== 0);
	
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x0E;
	GPIO_PORTF_AFSEL_R &= 0x11;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_DATA_R &= ~0x0E;
}



void SysTick_wait(unsigned long d){
NVIC_ST_CTRL_R=0x00;
NVIC_ST_RELOAD_R=d-1;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0x05;
while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
}


void Delay(unsigned int time){
int j;
for(j=0;j<time;j++){
SysTick_wait(16000); //delay 1ms
}
}

void Led_On()
{
GPIO_PORTF_DATA_R &= ~0x0E;
GPIO_PORTF_DATA_R |= 0x0E;
}


void Led_Off()
{
	GPIO_PORTF_DATA_R &= ~0x0E;
}




void Led_Flash(void){ // Led Blinks 3 Times 
int i;
for(i=0;i<3;i++){
GPIO_PORTF_DATA_R |= 0x0E ;
Delay(1000);
GPIO_PORTF_DATA_R &=~0x0E ;
Delay(1000);
}
}


/*

void Led_Blink(void){
while(Button_read('F',0)==0 & Button_read('A',4)==0){
GPIO_PORTF_DATA_R |= 0x0E ;
Delay(1000);
GPIO_PORTF_DATA_R &=~0x0E ;
Delay(1000);
}
}

*/