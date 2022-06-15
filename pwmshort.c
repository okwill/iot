//
// Smpl_ADC_PWM : ADC7 to read VR1 resistance value, PWM0 output to control LED (GPA12)
//
#include <stdio.h>																											 
#include "NUC1xx.h"
#include "LCD_Driver.h"

//void Delay(int count)
//{
	//while(count--)
	//{
//		__NOP;
	 //}
//}

int32_t main (void)
{
	//Enable 12Mhz and set HCLK->12Mhz
	char adc_value[15]="ADC Value:";	
	//UNLOCKREG();
	//SYSCLK->PWRCON.XTL12M_EN = 1;
	//SYSCLK->CLKSEL0.HCLK_S = 0;
	//LOCKREG();

	InitPWM();
	InitADC();

	Initial_panel();  //call initial pannel function
	clr_all_panel();
							 	
	/* Synch field transmission & Request Identifier Field transmission*/
					 
	while(1)
	{
		while(ADC->ADSR.ADF==0);
		ADC->ADSR.ADF=1;
		PWMA->CMR0=ADC->ADDR[7].RSLT<<4;
		//Show_Word(0,11,' ');
		//Show_Word(0,12,' ');
		//Show_Word(0,13,' ');
		sprintf(adc_value+4,"%d",ADC->ADDR[7].RSLT);
		print_lcd(0, adc_value);
		//Delay(20000);
		ADC->ADCR.ADST=1;
	}
}
