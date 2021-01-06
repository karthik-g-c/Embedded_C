/*
 * stm32l47xx_gpio_driver.c
 *
 *  Created on: 04-Jan-2021
 *      Author: Admin
 */

#include"stm32l47xx_gpio_driver.h"

/*
 * gpio Peripheral clock functoin
 */

//------------------function explantion------------
/*
 * @fn		Gpio peripheral clock control
 * @brief	This function enables and disables clock for the gpio's
 *
 * @param[n]	gpio port
 * @param[n]	enable, disable macros
 * @param[n]
 *
 * @return		none
 *
 * @note
 */
void GPIO_pclkctrl(GPIO_regdef_t *pGPIOx, uint8_t ENorDI)
{
	if(ENorDI == ENABLE){
		if(pGPIOx == GPIOA){
					GPIOA_PCLK_EN();
				}
		else if(pGPIOx == GPIOB){
					GPIOB_PCLK_EN();
				}
		else if(pGPIOx == GPIOC){
					GPIOC_PCLK_EN();
				}
		else if(pGPIOx == GPIOD){
					GPIOD_PCLK_EN();
				}
		else if(pGPIOx == GPIOE){
					GPIOE_PCLK_EN();
				}
		else if(pGPIOx == GPIOF){
					GPIOF_PCLK_EN();
				}
		else if(pGPIOx == GPIOG){
					GPIOG_PCLK_EN();
				}
		else if(pGPIOx == GPIOH){
					GPIOH_PCLK_EN();
				}
	}
	else{
		if(pGPIOx == GPIOA){
					GPIOA_PCLK_DI();
					}
		else if(pGPIOx == GPIOB){
					GPIOB_PCLK_DI();
					}
		else if(pGPIOx == GPIOC){
					GPIOC_PCLK_DI();
					}
		else if(pGPIOx == GPIOD){
					GPIOD_PCLK_DI();
					}
		else if(pGPIOx == GPIOE){
					GPIOE_PCLK_DI();
					}
		else if(pGPIOx == GPIOF){
					GPIOF_PCLK_DI();
					}
		else if(pGPIOx == GPIOG){
					GPIOG_PCLK_DI();
					}
		else if(pGPIOx == GPIOH){
					GPIOH_PCLK_DI();
					}

	}
}

/*
 * Gpio init and deinit
 */

//------------------function explantion------------
/*
 * @fn		Gpio Initialization
 * @brief	This function initialises the gpio's
 *
 * @param[n]	gpio handle structure
 * @param[n]
 * @param[n]
 *
 * @return		none
 *
 * @note
 */

void GPIO_init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	/*...Configure Pin mode...*/
	//if(pGPIOHandle->pGPIOx == GPIOA){}
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=3){
		temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
		pGPIOHandle->pGPIOx->MODER |= temp; // setting
	}
	else{

	}
	temp = 0;
	/*...configure speed...*/
	temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp; // setting

	temp = 0;
	/*...configure pull up pull down...*/
	temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl) << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	/*...configure output_type...*/
	temp = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType) << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	/*...CONFIGURE ALT FUNCTIONALITY...*/

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTF){
			//CONFIGURE ALTERNATE FUNCTION
		uint8_t temp1,temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &=  ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}

}

//------------------function explantion------------
/*
 * @fn		Gpio De-Initialization
 * @brief	This function de-initialises the initialised gpio's
 *
 * @param[n]	gpio portbase address
 * @param[n]
 * @param[n]
 *
 * @return		none
 *
 * @note
 */

void GPIO_deinit(GPIO_regdef_t *pGPIOx)
{
	if(pGPIOx == GPIOA){
			GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB){
			GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC){
	    	GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD){
			GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE){
			GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF){
			GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG){
			GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH){
			GPIOH_REG_RESET();
	}
}

/*
 * GPIO input output methods
 */

//------------------function explantion------------
/*
 * @fn		Gpio Reading Input pin
 * @brief	This function reads input from gpio's pin
 *
 * @param[n]	gpio portbase address
 * @param[n]	pin number that has input
 * @param[n]
 *
 * @return		0 OR 1
 *
 * @note
 */
uint8_t GPIO_readfrminputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value=0;
	value = (uint8_t)(pGPIOx->IDR >> PinNumber) & 0x00000001 ;
	return value;
}

//------------------function explantion------------
/*
 * @fn		Gpio Reading Input port
 * @brief	This function reads input from gpio's port
 *
 * @param[n]	gpio portbase address
 * @param[n]
 * @param[n]
 *
 * @return
 *
 * @note
 */
uint16_t GPIO_readfrminputport(GPIO_regdef_t *pGPIOx)
{
	uint16_t value=0;
	value = (uint16_t)(pGPIOx->IDR);
	return value;

}

//------------------function explantion------------
/*
 * @fn		Gpio writing output pin
 * @brief	This function write to gpio's pin
 *
 * @param[n]	gpio portbase address
 * @param[n]	pin number to write
 * @param[n]	Value to be written to the pin(0 or 1)
 *
 * @return		None
 *
 * @note
 */
void GPIO_writetooutputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		//write 1 to the output register corresponding to the pin number
		pGPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
		//write 0 to the output register corresponding to the pin number
		pGPIOx->ODR &= ~(1<<PinNumber);
	}

}

//------------------function explantion------------
/*
 * @fn		Gpio writing output port
 * @brief	This function write to gpio's port
 *
 * @param[n]	gpio portbase address
 * @param[n]	Value to be written to the pin(0 or 1)
 * @param[n]
 *
 * @return		None
 *
 * @note
 */
void GPIO_writetooutputport(GPIO_regdef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}

//------------------function explantion------------
/*
 * @fn		Gpio toggling output pin
 * @brief	This function toggles gpio's pin
 *
 * @param[n]	gpio portbase address
 * @param[n]	Pin number to toggle respectively
 * @param[n]
 *
 * @return		None
 *
 * @note
 */
void GPIO_toggleoutputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1<<PinNumber);
}

/*
 * Irq and inr interrut gpio handling
 */

void GPIO_IRQconfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI)
{

}
void GPIO_IRQHandling(void)
{

}


