/*
 * stm32l47xx_gpio_driver.h
 *
 *  Created on: 04-Jan-2021
 *      Author: Admin
 */

#ifndef INC_STM32L47XX_GPIO_DRIVER_H_
#define INC_STM32L47XX_GPIO_DRIVER_H_


#include "stm32l476xx.h"



typedef struct
{
	uint8_t GPIO_PinNumber;					// POSSIBLE VALUES FROM @GPIO_PIN_NUMBER
	uint8_t GPIO_PinMode;					// POSSIBLE VALUES FROM @GPIO_MODE
	uint8_t GPIO_PinSpeed;					// POSSIBEL VALUES FROM @GPIO_SPEED
	uint8_t GPIO_PinPuPdControl;			// POSSIBLE VALUES FROM @GPIO_PU_PD
	uint8_t GPIO_PinOPType;					// POSSIBLE VALUES FROM @GPIO_OP_TYPE
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct
{
	GPIO_regdef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

//@GPIO_PIN_NUMBER GPIO PIN NUMBERS

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

//@GPIO_MODE

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTF		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6

//@GPIO_OP_TYPE GPIO PIN POSSIBLE TYPE PINS

#define GPIO_OPTYPE_PP		0
#define GPIO_OPTYPE_OD		1

//@GPIO_SPEED GPIO PIN SPEED TYPE

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_HIGH			2
#define GPIO_SPEED_VERYHIGH		3

//@GPIO_PU_PD PIN PULL UP AND PULL DOWN MACROS

#define GPIO_NO_PUPD		0
#define GPIO_PLUP				1
#define GPIO_PLDN				2


/*
 * gpio Peripheral clock functoin
 */

void GPIO_pclkctrl(GPIO_regdef_t *pGPIOx, uint8_t ENorDI);

/*
 * Gpio init and deinit
 */

void GPIO_init(GPIO_Handle_t *pGPIOHandle);
void GPIO_deinit(GPIO_regdef_t *pGPIOx);

/*
 * GPIO input output methods
 */

uint8_t GPIO_readfrminputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_readfrminputport(GPIO_regdef_t *pGPIOx);
void GPIO_writetooutputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_writetooutputport(GPIO_regdef_t *pGPIOx, uint16_t value);
void GPIO_toggleoutputpin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber);

/*
 * Irq and inr interrut gpio handling
 */

void GPIO_IRQconfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI);
void GPIO_IRQHandling(void);



#endif /* INC_STM32L47XX_GPIO_DRIVER_H_ */
