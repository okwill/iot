//
// Smpl_GPIO_EINT1 : External Interrupt pin to trigger interrupt //on GPB15, then Buzz  INT1(GPB.15) pin  INT0(GPB.14) pin

#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"

#include "Driver\DrvSYS.h"
 void Init_LED()
 {
   DrvGPIO_Open(E_GPB,11,E_IO_OUTPUT);
   while (1) {
     DrvGPIO_ClrBit(E_GPB,11); // GPB11 = 0 to turn on Buzzer
   	DrvSYS_Delay(10);	    // Delay
   	DrvGPIO_SetBit(E_GPB,11); // GPB11 = 1 to turn off Buzzer
   	DrvSYS_Delay(10000);	    // Delay
   }
 }
 int main (void)
 {
 	UNLOCKREG();
  DrvSYS_Open(48000000);
 	LOCKREG();


 	DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); // initial GPIO pin GPB11 for controlling Buzzer

 //0 External Interrupt
   DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);                             // configure external interrupt pin GPB15
   DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, Init_LED); // configure external interrupt

   while(1)
 	{
   }
 }
