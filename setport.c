#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

void EINT1Callback(void) 
{
    DrvGPIO_SetPortBits(E_GPC,0xffff0fff); 
	  DrvSYS_Delay(300000);	   
    DrvGPIO_SetPortBits(E_GPC,0xffffffff)	; 
	  DrvSYS_Delay(300000);	   
}
int main (void)
{
	  UNLOCKREG();
	  DrvSYS_SetOscCtrl(E_SYS_XTL12M, 1);                 
	  DrvSYS_SelectHCLKSource(0);         
	  LOCKREG();
    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); 
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);                             
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback); 
    while(1)
	  {
    }
}
