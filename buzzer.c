#include "tm4c123gh6pm.h"
#include "led.h"

void Buzzer_Init()
	{
	SYSCTL_RCGCGPIO_R |=0x10;
	while ((SYSCTL_PRGPIO_R &= 0x10)== 0);
	
//	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x20;
	GPIO_PORTE_AFSEL_R &= ~0x20;
	GPIO_PORTE_DIR_R |= 0x20;
	GPIO_PORTE_DEN_R |= 0x20;
	GPIO_PORTE_PCTL_R &= ~0x00F00000;
	GPIO_PORTE_AMSEL_R &= ~0x20;
	GPIO_PORTE_DATA_R &= ~0x20;
}
	

void Buzzer_led_flash()
{
int i;
	for(i=0; i<3; i++)
	{
		GPIO_PORTF_DATA_R |= 0x0E;
		GPIO_PORTE_DATA_R |= 0x20; //BUZZER PIN IS LOGIC HIGH (BUZZER ON) 
		Delay(1000);
		GPIO_PORTF_DATA_R &=~0x0E;
		GPIO_PORTE_DATA_R &= ~0x20; //BUZZER PIN IS LOGIC LOW (BUZZER OFF)
		Delay(1000);
	}
}