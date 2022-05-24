#include "tm4c123gh6pm.h"

void SW3_init(){
	SYSCTL_RCGCGPIO_R |= 0x10;
	while ((SYSCTL_PRGPIO_R &= 0x10)== 0){};
	
//	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x10;
	GPIO_PORTE_AFSEL_R &= ~0x10;
	GPIO_PORTE_DIR_R &= ~0x10;
	GPIO_PORTE_PUR_R |=0x10;	
	GPIO_PORTE_DEN_R |= 0x10;
	GPIO_PORTE_PCTL_R &= ~0x000F0000;
	GPIO_PORTE_AMSEL_R &= ~0x10;
}




unsigned char SW3_Input(void)
{

return GPIO_PORTE_DATA_R & 0x10;
}
