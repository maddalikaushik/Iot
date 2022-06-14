#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
void Init_LED()
{
    DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); 
    DrvGPIO_SetBit(E_GPC, 12);            
}
int main (void)
{
    UNLOCKREG();                        
    DrvSYS_Open(48000000);
    LOCKREG();
    Init_LED();
    while (1)
    {
        DrvGPIO_ClrBit(E_GPC, 12); 
        DrvSYS_Delay(300000);      
        DrvGPIO_SetBit(E_GPC, 12); 
        DrvSYS_Delay(300000);      
    }
}
