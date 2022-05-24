
#include "Io.h"
#include "led.h"
 #include "switch.h"
#include "tm4c123gh6pm.h"
#include "lcd.h"
#include "delay.h"
#include "TM4C123GH6PM1.h"
#include "keypad.h"
#include "intTochar.h"
#include "chartoint.h"
#include "buzzer.h"
#include "switch3.h"

unsigned char arr_ERR[] = { "ERR" };
unsigned char arr_popcorn[] = {"popcorn"};
unsigned char arr_beef[]={"Beef weight?"};
unsigned char arr_chicken[]={"chicken weight?"};
unsigned char arr_cooking[]={"cooking time?"};
unsigned char pressSW2[]={"press SW2"};
unsigned char choose[]={"choose a meal"};
unsigned char toolong[]={"too long time"};	

unsigned char timer[]={'0','0',':','0','0'};


int i ;
int j;
int x;
int z;


int weighttotime;

int timetotime;

int A;
int B;
int C;
int D;




int main(void){
	

LCD_init();
keypad_Init();
SW3_init();
Buzzer_Init();
LED_vInit();

SW_init();


while(1){
	
			Led_Off();
	
	LCD_vSendString(choose,13);

	
			switch(keypad_v8Read())
			{
				case'A':
					
					LCD_ClearScreen();
				
					LCD_vSendString(arr_popcorn,7);
					Delay(1000);
				
				
					while (SW2_Input()==0x01){}; // loop until sw2 pushed
					LCD_ClearScreen();

					for(i=5;i>=0;i--)
					{
						
						for (j=9;j>=0;j--)
						{
label:			if(j<0)
							{
								j=0;
							}
							if ((SW1_Input()==0x10) & (SW3_Input()==0x10))
							{

					//			timer[3]=intTochar(i);
					//			timer[4]=intTochar(j);
								timer[3]=i+'0';
								timer[4]=j+'0';
								Led_On();
								LCD_ClearScreen();
								LCD_vSendString( timer,5);				
								Delay(1000);		
							

					  	}
							else
							{
								Led_Off();		
								break;
							}
								
						}
					if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
							break;	
					}
				
	   	 	while(timer[0]!='0'| timer[1]!='0'| timer[3]!='0'| timer[4]!='0')
				{
label2:		GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0x0E ;
					Delay(1000);
					if(SW3_Input()==0x00)
					{
						goto label2;
					}
				
				
				
				if((SW1_Input()==0x10) & (SW2_Input() ==0x00))
					{
					goto label;
					
					}
				else if((SW1_Input()==0x00) & (SW2_Input()==0x01))
				{
					LCD_ClearScreen();
					Led_Off();
					break;
				}
				}
				LCD_ClearScreen();
				Buzzer_led_flash();
				
				break;
				
				
				
				
				
				
				
				
				
				
				case'B':
					
				LCD_ClearScreen();
				
label7:	LCD_vSendString(arr_beef,12);
				Delay(1000);
				while(keypad_v8Read()=='B');
				while(keypad_v8Read()==0);

				if(keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9')
				{
					
				LCD_ClearScreen();
				weighttotime = charToint(keypad_v8Read()) * 0.5 * 60;
				i= weighttotime/60;
				j=(weighttotime%60)/10;
				z=(weighttotime%60)%10;
	
				LCD_vSendString(pressSW2,9);
				while (SW2_Input()==0x01){}; // loop until sw2 pushed
				LCD_ClearScreen();
					
				goto label5;				
				for(i=5;i>=0;i--)
				{
					for (j=5;j>=0;j--)
					{
						for (z=9;z>=0;z--)
	label3:		{
							if(z<0)
							{
								z=0;
							}
							if ((SW1_Input()==0x10) & (SW3_Input()==0x10))
label5:				{
								timer[1]=i +'0';
								timer[3]=j +'0';
								timer[4]=z +'0';
								Led_On();
								LCD_ClearScreen();
								LCD_vSendString( timer,5);
								Delay(1000);				
							}
							else
							{
								Led_Off();
								break;
							}
						}
						if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
							break;	
					}
					if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
							break;
				}
				
	   	 	while(timer[0]!='0'| timer[1]!='0'| timer[3]!='0'| timer[4]!='0')
				{
label4:		GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0x0E ;
					Delay(1000);
					if(SW3_Input()==0x00)
					{
						goto label4;
					}
				
				
				
				if((SW1_Input()==0x10) & (SW2_Input() ==0x00))
					{
					goto label3;
					
					}
				else if((SW1_Input()==0x00) & (SW2_Input()==0x01))
				{
					LCD_ClearScreen();
					Led_Off();
					break;
				}
				}
				LCD_ClearScreen();
				Buzzer_led_flash();
				break;
			}
				
				else 
				{
					LCD_ClearScreen();
					LCD_vSendString( arr_ERR,3);
					Delay(2000);
					LCD_ClearScreen();
					goto label7;
				}

				
				
				
				
				
				
				
				
				
				
			
				
				case 'C':
					
				LCD_ClearScreen();
				
label23:LCD_vSendString(arr_chicken,15);
				Delay(1000);
				while(keypad_v8Read()=='C');
				while(keypad_v8Read()==0);
				if(keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9')
				{
				LCD_ClearScreen();
				weighttotime = charToint(keypad_v8Read()) * 0.2 * 60;
				i= weighttotime/60;
				j=(weighttotime%60)/10;
				z=(weighttotime%60)%10;
					
				LCD_vSendString(pressSW2,9);
				while (SW2_Input()==0x01){}; // loop until sw2 pushed
				LCD_ClearScreen();
					
				goto label20;
				for(i=1;i>=0;i--)
				{
					for (j=5;j>=0;j--)
					{
						
						for (z=9;z>=0;z--)
label21:			{
							if(z<0)
							{
								z=0;
							}
							if ((SW1_Input()==0x10) & (SW3_Input()==0x10))
label20:					{
							timer[1]=i +'0';
							timer[3]=j +'0';
							timer[4]=z +'0';
							Led_On();
							LCD_ClearScreen();
							LCD_vSendString( timer,5);
							Delay(1000);				
							}
							else
							{
								Led_Off();		
								break;
							}
								
						}
					if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
							break;	
					}
				if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
							break;
				}
				
				
				while(timer[0]!='0'| timer[1]!='0'| timer[3]!='0'| timer[4]!='0')
				{
label22:	GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0x0E ;
					Delay(1000);
					if(SW3_Input()==0x00)
					{
						goto label22;
					}

					if((SW1_Input()==0x10) & (SW2_Input() ==0x00))
					{
					goto label21;
					
					}

					else if((SW1_Input()==0x00) & (SW2_Input()==0x01))
					{
					LCD_ClearScreen();
					Led_Off();
					break;
					}
				}
				
				LCD_ClearScreen();
				Buzzer_led_flash();
				
				break;

			}
				else 
				{
					LCD_ClearScreen();
					LCD_vSendString( arr_ERR,3);
					Delay(2000);
					LCD_ClearScreen();
					goto label23;
				}



				
				
				
				
				
				
				
				
				
				
				
				
				
				case'D':
				
					LCD_ClearScreen();				
				
label8:		LCD_vSendString(arr_cooking,13);
					Delay(1000);
					while(keypad_v8Read()=='D');
					while(keypad_v8Read()==0);
					if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
					{
						A= charToint(keypad_v8Read());
						timer[0]= '0';
						timer[1]= '0';
						timer[3]='0';
						timer[4]= A + '0';
						LCD_ClearScreen();
						LCD_vSendString(timer,5);
						while(keypad_v8Read()!=0x00);
						while(keypad_v8Read()==0x00)
						{
							if (SW1_Input()==0x00)
								goto label8;
							else if (SW2_Input()==0x00)
							goto label123;
						}
						
						if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
						{
							B= charToint(keypad_v8Read());
							timer[0]= '0';
							timer[1]= '0';
							timer[3]= timer[4];
							timer[4]=B + '0';
							LCD_ClearScreen();
							LCD_vSendString(timer,5);
							while(keypad_v8Read()!=0x00);
							while(keypad_v8Read()==0x00)
							{
								if (SW1_Input()==0x00)
									goto label8;
								else if (SW2_Input()==0x00)
									goto label123;
							}
							if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
							{
								C=charToint(keypad_v8Read());
								timer[0]= '0';
								timer[1]= timer[3];
								timer[3]= timer[4];
								timer[4]= C + '0';
								LCD_ClearScreen();
								LCD_vSendString(timer,5);
								while(keypad_v8Read()!=0x00);
								while(keypad_v8Read()==0x00)
								{
									if (SW1_Input()==0x00)
										goto label8;
									else if (SW2_Input()==0x00)
										goto label123;
								}
								if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
								{
									D= charToint(keypad_v8Read());
									timer[0]= timer[1];
									timer[1]= timer[3];
									timer[3]= timer[4];
									timer[4]= D + '0';
									LCD_ClearScreen();
									LCD_vSendString(timer,5);
									
									while ((SW2_Input()==0x01) & (SW1_Input()==0x10)){}; 
										
									if (SW2_Input()==0x00)
label123:					{
										timetotime= charToint(timer[0]) * 60 * 10  +  charToint(timer[1])*60 + charToint(timer[3])*10 + charToint(timer[4]);
										
	
										i=timetotime/600;
										if (i>3)
										{
											LCD_ClearScreen();
											LCD_vSendString(toolong,13);
											Delay(2000);
											LCD_ClearScreen();
											
											break;
										}
										j=(timetotime%600)/60;
										x=((timetotime%600)%60)/10;
										z=((timetotime%600)%60)%10;				
										goto label10;

									for(i=3;i>=0;i--)
									{
										for (j=9;j>=0;j--)
										{
											for (x=5;x>=0;x--)
											{
												for(z=9;z>=0;z--)
												{									
label12:									if(z<0)
													{
														z=0;
													}
													
													if ((SW1_Input()==0x10) & (SW3_Input()==0x10))
label10:								{
														timer[0]=i + '0';
														timer[1]=j + '0';
														timer[3]=x + '0';
														timer[4]=z + '0';
														Led_On();
														LCD_ClearScreen();
														LCD_vSendString( timer,5);
														Delay(1000);	
													}
												else
													{
														Led_Off();
														break;
													}
												}
												if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
													break;
											}
											if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
												break;
										}
										if ((SW1_Input()==0x00) | (SW3_Input()==0x00))
											break;
									}
				
								while(timer[0]!='0'| timer[1]!='0'| timer[3]!='0'| timer[4]!='0')
								{
label11:					GPIO_PORTF_DATA_R |= 0x0E ;
									Delay(1000);
									GPIO_PORTF_DATA_R &=~0x0E ;
									Delay(1000);
									if(SW3_Input()==0x00)
									{
										goto label11;
									}
								
				
				
								if((SW1_Input()==0x10) & (SW2_Input() ==0x00))
								{
									LCD_ClearScreen();
									goto label12;
					
								}
								else if((SW1_Input()==0x00) & (SW2_Input()==0x01))
								{
									LCD_ClearScreen();
									Led_Off();
									break;
								}
							}
								LCD_ClearScreen();
								Buzzer_led_flash();
								break;
		
										
								}
								else
								{
									LCD_ClearScreen();
									goto label8;
								}
							}
							else 
							{
								LCD_ClearScreen();
								LCD_vSendString( arr_ERR,3);
								Delay(2000);
								LCD_ClearScreen();
								goto label8;
								}
								
								
							}
						else 
						{
							LCD_ClearScreen();
							LCD_vSendString( arr_ERR,3);
							Delay(2000);
							LCD_ClearScreen();
							goto label8;
						}
					}
					else 
					{
						LCD_ClearScreen();
						LCD_vSendString( arr_ERR,3);
						Delay(2000);
						LCD_ClearScreen();
						goto label8;
					}
				}
				else
				{
					LCD_ClearScreen();
					LCD_vSendString( arr_ERR,3);
					Delay(2000);
					LCD_ClearScreen();
					goto label8;
				}
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
							
				
				case 0:
					break;
				
				
				default:
					LCD_ClearScreen();
					LCD_vSendString( arr_ERR,3);
					Delay(2000);
					LCD_ClearScreen();
					break;
			}
		}

	}
