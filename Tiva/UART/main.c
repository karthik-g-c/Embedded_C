#include "TM4C1294NCPDT.h"
#include "uart_my.h"

int main()
{
	volatile int j = 0;

	char a[]  = "Hello! World\r\n";
	uart0_init();
	
	SYSCTL->RCGCGPIO |= (1<<12) | (1<<8);
	
	GPION->DIR |= (1<<0);
	GPION->DEN |= (1<<0);
	GPIOJ_AHB->DIR &= ~(1<<0);
	GPIOJ_AHB->DEN |= (1<<0);
	
	GPIOJ_AHB->PUR |= (1<<0);
	
	while(1){
		while((GPIOJ_AHB->DATA & (1<<0)) != 0){;}
		delay();
		GPION->DATA |= (1<<0);
		delay();
	uart_trans(a);
	a++;
	if((j++) == 25)
		{
		j = 0;
		a = 'A';
		}
			GPION->DATA &= ~(1<<0);
	}
}
