#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"

#include "Driver\DrvSYS.h"

void Init_LED() // Initialize GPIO pins
{
 DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); // GPC12 pin set to output mode
           DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);        // Goutput Hi to turn off LED
        DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
        DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
 DrvGPIO_SetPortBits(E_GPC,0xffff0fff); // output Low to turn on LED
        DrvSYS_Delay(300000);      // delay
DrvGPIO_SetPortBits(E_GPC,0xffffffff)   ; // output Hi to turn off LED
        DrvSYS_Delay(300000);      // delay
}

int main (void)
{
        UNLOCKREG();                        // unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz
                              // 12MHz crystal input, PLL output 48MHz
        LOCKREG();                                  // lock register from programming

 DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);                             // configure external interrupt pin GPB15
 DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, Init_LED);


        while (1)                                  // forever loop to keep flashing four LEDs one at a time
        {

        }

}
