#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

void Init_LED() // Initialize GPIO pins
{
		while (1)
	{
	// GPA12 = Blue,  0 : on, 1 : off
	// GPA13 = Green, 0 : on, 1 : off
	// GPA14 = Red,   0 : on, 1 : off

	// set RGBled to Blue
    DrvGPIO_ClrBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13);
    DrvGPIO_SetBit(E_GPA,14);
  	DrvSYS_Delay(1000000);

	// set RGBled to Green
    DrvGPIO_SetBit(E_GPA,12);
    DrvGPIO_ClrBit(E_GPA,13); // GPA13 = Green, 0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,14);
  	DrvSYS_Delay(1000000);

	// set RGBled to Red
    DrvGPIO_SetBit(E_GPA,12);
    DrvGPIO_SetBit(E_GPA,13);
    DrvGPIO_ClrBit(E_GPA,14); // GPA14 = Red,   0 : on, 1 : off
  	DrvSYS_Delay(1000000);

	// set RGBled to off
    DrvGPIO_SetBit(E_GPA,12); // GPA12 = Blue,  0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,13); // GPA13 = Green, 0 : on, 1 : off
    DrvGPIO_SetBit(E_GPA,14); // GPA14 = Red,   0 : on, 1 : off
	DrvSYS_Delay(1000000);

	}
}

int main (void)
{
	UNLOCKREG();			    // unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz
	                      // 12MHz crystal input, PLL output 48MHz
	LOCKREG();				    // lock register from programming

  DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);                             // configure external interrupt pin GPB14
  DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, Init_LED); // configure external interrupt

  while(1)
	{
  }
}
