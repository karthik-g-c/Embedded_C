#include "TM4C1294NCPDT.h"

void uart0_init(void);
void uart0_trans(char a);
void delay(void);

void uart0_init(void){
	SYSCTL->RCGCUART |= (1<<0);
	SYSCTL->RCGCGPIO |= (1<<0);

	GPIOA_AHB->DEN |= (3<<0);
	GPIOA_AHB->AFSEL |= (3<<0);
	GPIOA_AHB->PCTL		|= (1<<(0*4)) | (1<<(1*4));
	
	UART0->CTL &= ~(1<<0);
	
	UART0->IBRD = 8;
	UART0->FBRD = 44;
	
	UART0->LCRH |= (3<<5);
	
	UART0->CC &= 0x0;
	UART0->CTL |= (1<<8);
	
	UART0->CTL |= (1<<0);
}

void delay(void) {		for(volatile int i = 0;i<800000/2;i++){;} }

void uart0_trans(char a)
{
	while((UART0->FR & (1<<5)) !=0){;}
	UART0->DR = a;
	//while(UART0->FR & (1<<3) ){;}
}