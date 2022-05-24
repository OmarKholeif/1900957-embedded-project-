#include "TM4C123GH6PM1.h"
#include <stdint.h>


#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA
#define RS 0x20 							/* PORTA BIT5 mask */
#define RW 0x40							  /* PORTA BIT6 mask */
#define EN 0x80 							/* PORTA BIT7 mask */

void LCD_command(unsigned char cmnd);
void LCD_init(void);
void lcd_data(unsigned char data);
void LCD_vSendString(unsigned char *string, int X);
void LCD_ClearScreen();