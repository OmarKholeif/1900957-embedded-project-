#include "Io.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "TM4C123GH6PM1.h"

#define KEYPAD_ROW GPIOE
#define KEYPAD_COL GPIOC

void keypad_Init(void);
unsigned char keypad_v8Read(void);
