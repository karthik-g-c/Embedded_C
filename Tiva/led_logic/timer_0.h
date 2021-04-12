#include "TM4C1294NCPDT.h"
void timer_init();

void timer_init() {
	SYSCTL->RCGCTIMER |= (3<<0);
	for(volatile int i = 0;i<100;i++){}
	TIMER0->CTL &= ~(1<<0);
	TIMER0->CFG &= ~(1<<0);
	TIMER0->TAMR |= (1<<0);
	TIMER0->TAILR = 1600000;
	
	TIMER1->CTL &= ~(1<<0);
	TIMER1->CFG &= ~(1<<0);
	TIMER1->TAMR |= (1<<0);
	TIMER1->TAILR = 1600000;
}