/*
 * 02led_button.c
 *
 *  Created on: 05-Jan-2021
 *      Author: Admin
 */


#include "stm32l476xx.h"

#define LOW 0

#define BTN_PRESSED LOW

void delay(){
	for(uint32_t i=0;i<500000/6;i++);
}

int main()
{
	GPIO_Handle_t Gpioled, Gpiobtn;

	Gpioled.pGPIOx = GPIOA;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;

	GPIO_pclkctrl(GPIOA, ENABLE);

	GPIO_init(&Gpioled);

	Gpiobtn.pGPIOx = GPIOC;
	Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;

	GPIO_pclkctrl(GPIOC, ENABLE);

	GPIO_init(&Gpiobtn);

	while(1)
	{
		if(GPIO_readfrminputpin(GPIOC, GPIO_PIN_NO_13) == BTN_PRESSED){
			delay();
			GPIO_toggleoutputpin(GPIOA, GPIO_PIN_NO_5);
		}
	}
}
