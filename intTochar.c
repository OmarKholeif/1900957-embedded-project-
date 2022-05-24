/* This function is used to convert the result from an integer type to character type in order to enable the printing
on the lcd using 'lcd_Data()'*/

#include <stdint.h>
#include "lcd.h"


unsigned char intTochar(uint32_t y)
{
	int tenthousands;
	int thousands;
	int cents;
	int tens;
	int ones;
unsigned char chr;
if(y<=9){
	switch(y)
	{
		case 0:
					chr = '0';
	        return chr ;
		      break;
		case 1:
	        chr = '1';
	        return chr ;
		      break;
		case 2:
	        chr = '2';
	        return chr ;
		      break;
		case 3:
	       	chr = '3';
	        return chr ;
		      break;
		case 4:
	       	chr = '4';
	        return chr ;
		      break;
		case 5:
	        chr = '5';
	        return chr ;
		      break;
		case 6:
	      	chr = '6';
	        return chr ;
		      break;
		case 7:
					chr = '7';
	        return chr ;;
		      break;
		case 8:
	        chr = '8';
	        return chr ;
		      break;
		case 9:
	        chr = '9';
	        return chr ;
		      break;
	
	}
}
if(y<100 && y>=10)
{
   tens=y/10;
	intTochar(tens);     // Recursive Function
	 ones=y-(tens*10);
	intTochar(ones);
}
if(y<1000 && y>=100)
{
 cents=y/100;
	intTochar(cents);
 tens=(y-(cents*100))/10;
	intTochar(tens);
 ones=y-(cents*100)-(tens*10);
	intTochar(ones);
}
if(y<10000 && y>=1000)
{
 thousands=y/1000;
	intTochar(thousands);
	cents=(y-(thousands*1000))/100;
	intTochar(cents);
 tens=(y-(thousands*1000)-(cents*100))/10;
	intTochar(tens);
 ones=y-(thousands*1000)-(cents*100)-(tens*10);
	intTochar(ones);
}
if(y<100000 && y>=10000)
{
  tenthousands=y/10000;
	intTochar(tenthousands);
	thousands=(y-(tenthousands*10000))/1000;
	intTochar(thousands);
	cents=(y-(tenthousands*10000)-(thousands*1000))/100;
	intTochar(cents);
 tens=(y-(tenthousands*10000)-(thousands*1000)-(cents*100))/10;
	intTochar(tens);
 ones=y-(tenthousands*10000)-(thousands*1000)-(cents*100)-(tens*10);
	intTochar(ones);
}
}
