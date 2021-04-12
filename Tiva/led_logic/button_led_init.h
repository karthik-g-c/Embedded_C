#include "TM4C1294NCPDT.h"
void btn_led_init(void);

void btn_led_init(void) {
	SYSCTL->RCGCGPIO |= (1<<12) | (1<<8);
	for(volatile int i = 0;i<100;i++){}
  GPION->DIR |= (1<<0);
	GPION->DEN |= (1<<0);
	GPIOJ_AHB->DIR &= ~(1<<0);
	GPIOJ_AHB->DEN |= (1<<0);
	GPIOJ_AHB->PUR |= (1<<0);
	
	GPIOJ_AHB->IS |= (1<<0);
	GPIOJ_AHB->IBE &= ~(1<<0);
	GPIOJ_AHB->IEV &= ~(1<<0);
	GPIOJ_AHB->IM |= (1<<0);
}