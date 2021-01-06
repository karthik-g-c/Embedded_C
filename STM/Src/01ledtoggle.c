/*
 * 01ledtoggle.c
 *
 *  Created on: 04-Jan-2021
 *      Author: Admin
 */


#include "stm32l476xx.h"


void delay(){
	for(uint32_t i=0;i<500000/2;i++);
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


	while(1)
	{
			GPIO_toggleoutputpin(GPIOA, GPIO_PIN_NO_5);
			delay();
	}
}
