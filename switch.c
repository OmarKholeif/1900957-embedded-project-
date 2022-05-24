#include "Io.h"
#include "tm4c123gh6pm.h"

void SW_init()
	{
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R & 0x20) == 0);
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x11;
GPIO_PORTF_AMSEL_R &= ~0x11;
GPIO_PORTF_PCTL_R &= ~0x000F000F;
GPIO_PORTF_AFSEL_R &= ~0x11;
GPIO_PORTF_DIR_R &= ~0x11;
GPIO_PORTF_PUR_R |= 0x11;
GPIO_PORTF_DEN_R |= 0x11;
}
	

unsigned int SW1_Input(void)
{

return (GPIO_PORTF_DATA_R & 0x10);
}

unsigned int SW2_Input(void)
{
	
return (GPIO_PORTF_DATA_R & 0x01);
}
