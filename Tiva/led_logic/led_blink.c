#include "timer_0.h"
#include "button_led_init.h"

//void delay(int x);
int a;

/*void delay(int x) {
	volatile int i;
	for(i = 0;i<(x*2000);i++);
}*/
	
int main()
{
	btn_led_init();
	timer_init();
	
	NVIC->ISER[1] |= (1<<19); 
	a = 0;
		while(1){
			while(a) {
				GPION->DATA |= (1<<0);
				TIMER1->CTL |= (1<<0);
				while(1) {
						if(TIMER1->RIS & 0x1) {
						TIMER1->ICR |= (1<<0);
						break;
						}
					}
				a--;
				}
		if(!a)
				GPION->DATA &= ~(1<<0);
		}
}
void GPIOJ_Handler(void) {
	TIMER0->CTL |= (1<<0);
	while(1){
	if(TIMER0->RIS & 0x1) {
		TIMER0->ICR |= (1<<0);
		a++;
		break;
	}
	}
}