#include "Io.h"
#define NVIC_ST_CURRENT_R (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_R (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R (*((volatile unsigned long *)0xE000E014))


void LED_vInit();
void Led_On();
void Led_Off();
void SysTick_wait(unsigned long d);
void Delay(unsigned int time);
void Led_Flash(void);
void Led_Blink(void);
