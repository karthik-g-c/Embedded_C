

#ifndef INC_STM32L476xx_H_
#define INC_STM32L476xx_H_

#include<stdint.h>

#define __vo volatile

//FLASH and SRAM base addresss of the mcu

#define FLASH_BASE				0x08000000U
#define SRAM1_BASE				0x20000000U
#define SRAM2_BASE				0x20018000U

//BUS peripheral base addresses of the mcu

#define PERIPH_BASE				0x40020000U
#define AHBI_BASE				PERIPH_BASE
#define AHB2_BASE				0x48000000U
#define APBI_BASE				0x40000000U
#define APB2_BASE				0x40010000U

//Peripheral and gpio base addresses

#define RCC_BASE				0x40021000U

//----gpio

#define GPIOA_BASE				0x48000000U
#define GPIOB_BASE				0x48000400U
#define GPIOC_BASE				0x48000800U
#define GPIOD_BASE				0x48000C00U
#define GPIOE_BASE				0x48001000U
#define GPIOF_BASE				0x48001400U
#define GPIOG_BASE				0x48001800U
#define GPIOH_BASE				0x48001C00U

//----SPI

#define SPI1_BASE				0x40013000U
#define SPI2_BASE				0x40003800U
#define SPI3_BASE				0x40003C00U

//----I2C

#define I2C1_BASE				0x40005400U
#define I2C2_BASE				0x40005800U
#define I2C3_BASE				0x40005C00U

//----USART AND UART

#define USART1_BASE				0x40013800U
#define USART2_BASE				0x40004400U
#define USART3_BASE				0x40004800U
#define UART4_BASE				0x40004C00U
#define UART5_BASE				0x40005000U


//Register Configuration of the PERIPHERALS of the mcu in a structural format.....

typedef	struct							// as the struct is arranged in its order the 32 bit data type make 0x04 difference
{
	__vo uint32_t MODER;				//---gpio mode register offset: 0x00
	__vo uint32_t OTYPER;				//---output type register offset:0x04
	__vo uint32_t OSPEEDR;				//---output speed register offset:0x08
	__vo uint32_t PUPDR;				//---pull up/down register offset:0x0C
	__vo uint32_t IDR;					//---input data register offset:0x10
	__vo uint32_t ODR;					//---output data register offset:0x14
	__vo uint32_t BSRR;					//---bit set/reset register offset:0x18
	__vo uint32_t LCKR;					//---GPIO port configuration lock register off:0x1C
	__vo uint32_t AFR[2];				//---alternate function register off:0x20-0x24(low-high)
	__vo uint32_t BRR;					//---bit reset register off:0x28
	__vo uint32_t ASCR;					//---analog switch control register off:0x2C
}GPIO_regdef_t;


typedef struct
{
	__vo uint32_t CR;							//---Clock control register 0x00
	__vo uint32_t ICSCR;							//---Internal clock sources calibration register 0x04
	__vo uint32_t CFGR;							//---Clock configuration register 0x08
	__vo uint32_t PLLCFGR;						//---PLL configuration register 0x0C
	__vo uint32_t PLLSAI1CFGR;					//---PLLSAI1 configuration register 0x10
	__vo uint32_t PLLSAI2CFGR;					//---PLLSAI2 configuration register	0x14
	__vo uint32_t CIER;							//---Clock interrupt enable register 0x18
	__vo uint32_t CIFR;							//---Clock interrupt flag register  0x1C
	__vo uint32_t CICR;							//---Clock interrupt clear register 0x20
	uint32_t      RESERVED0;
	__vo uint32_t AHB1RSTR;						//---AHB1 peripheral reset register 0x28
	__vo uint32_t AHB2RSTR;						//---AHB2 peripheral reset register 0x2C
	__vo uint32_t AHB3RSTR;						//---AHB3 peripheral reset register 0x30
	uint32_t      RESERVED1;
	__vo uint32_t APB1RSTR1;						//---APB1 peripheral reset register1 0x38
	__vo uint32_t APB1RSTR2;						//---APB1 peripheral reset register2 0x3C
	__vo uint32_t APB2RSTR;						//---APB2 peripheral reset register 0x40
	uint32_t      RESERVED2;
	__vo uint32_t AHB1ENR;						//---AHB1 CLOCK ENABLE register 0x48
	__vo uint32_t AHB2ENR;						//---AHB2 CLOCK ENABLE register 0x4C
	__vo uint32_t AHB3ENR;						//---AHB3 CLOCK ENABLE register 0x50
	uint32_t      RESERVED3;
	__vo uint32_t APB1ENR1;						//---APB1 CLOCK ENABLE register1 0x58
	__vo uint32_t APB1ENR2;						//---APB1 CLOCK ENABLE register2 0x5C
	__vo uint32_t APB2ENR;						//---APB2 CLOCK ENABLE register 0x60
	uint32_t      RESERVED4;
	__vo uint32_t AHB1SMENR;					//---AHB1 peripheral clocks enable in Sleep and Stop modes register 0x68
	__vo uint32_t AHB2SMENR;					//---AHB2 peripheral clocks enable in Sleep and Stop modes register 0x6C
	__vo uint32_t AHB3SMENR;					//---AHB3 peripheral clocks enable in Sleep and Stop modes register 0x70
	uint32_t      RESERVED5;
	__vo uint32_t APB1SMENR1;					//---APB1 peripheral clocks enable in Sleep and Stop modes register1 0x78
	__vo uint32_t APB1SMENR2;					//---APB1 peripheral clocks enable in Sleep and Stop modes register2 0x7C
	__vo uint32_t APB2SMENR;					//---APB2 peripheral clocks enable in Sleep and Stop modes register 0x80
	uint32_t      RESERVED6;
	__vo uint32_t CCIPR;						//---Peripheral independent clock configuration register 0x88
	uint32_t      RESERVED7;
	__vo uint32_t BDCR;						//---Backup domain control register 0x90
	__vo uint32_t CSR;						//---Control status register 0x94
	__vo uint32_t CRRCR;						//---Clock recovery RC register 0x98
	__vo uint32_t CCIPR2;						//---Peripheral independent clock configuration register 0x9C
}RCC_regdef_t;

/*
 *
 * Peripheral register definitions
*/

#define GPIOA 				((GPIO_regdef_t*)GPIOA_BASE)
#define GPIOB 				((GPIO_regdef_t*)GPIOB_BASE)
#define GPIOC 				((GPIO_regdef_t*)GPIOC_BASE)
#define GPIOD 				((GPIO_regdef_t*)GPIOD_BASE)
#define GPIOE 				((GPIO_regdef_t*)GPIOE_BASE)
#define GPIOF 				((GPIO_regdef_t*)GPIOF_BASE)
#define GPIOG 				((GPIO_regdef_t*)GPIOG_BASE)
#define GPIOH 				((GPIO_regdef_t*)GPIOH_BASE)

#define RCC					((RCC_regdef_t*)RCC_BASE)


//-------------------Clock enabling definitions------------

/*
 * Gpio clock enabling
 */

#define GPIOA_PCLK_EN()		(RCC->AHB2ENR |= (1<<0))
#define GPIOB_PCLK_EN()		(RCC->AHB2ENR |= (1<<1))
#define GPIOC_PCLK_EN()		(RCC->AHB2ENR |= (1<<2))
#define GPIOD_PCLK_EN()		(RCC->AHB2ENR |= (1<<3))
#define GPIOE_PCLK_EN()		(RCC->AHB2ENR |= (1<<4))
#define GPIOF_PCLK_EN()		(RCC->AHB2ENR |= (1<<5))
#define GPIOG_PCLK_EN()		(RCC->AHB2ENR |= (1<<6))
#define GPIOH_PCLK_EN()		(RCC->AHB2ENR |= (1<<7))

/*
 * USART and UART enabling definitions
 */

#define USART1_PCLK_EN()		(RCC->APB2ENR |= (1<<14))
#define USART2_PCLK_EN()		(RCC->APB1ENR1 |= (1<<17))
#define USART3_PCLK_EN()		(RCC->APB1ENR1 |= (1<<18))
#define UART4_PCLK_EN()			(RCC->APB1ENR1 |= (1<<19))
#define UART5_PCLK_EN()			(RCC->APB1ENR1 |= (1<<20))

/*
 * SPI enabling definitions
 */

#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR1 |= (1<<14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR1 |= (1<<15))

/*
 * I2C enabling definitions
 */

#define I2C1_PCLK_EN()			(RCC->APB1ENR1 |= (1<<21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR1 |= (1<<22))
#define I2C3_PCLK_EN()			(RCC->APB1ENR1 |= (1<<23))
#define I2C4_PCLK_EN()			(RCC->APB1ENR2 |= (1<<1))

/*
 * GPIO Disabling definitions
 */

#define GPIOA_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()		(RCC->AHB2ENR &= ~(1<<7))

/*
 * USART and UART Disabling definitions
 */

#define USART1_PCLK_DI()		(RCC->APB2ENR &= ~(1<<14))
#define USART2_PCLK_DI()		(RCC->APB1ENR1 &= ~(1<<17))
#define USART3_PCLK_DI()		(RCC->APB1ENR1 &= ~(1<<18))
#define UART4_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<19))
#define UART5_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<20))

/*
 * SPI disabling definitions
 */

#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<14))
#define SPI3_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<15))

/*
 * I2C disabling definitions
 */

#define I2C1_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<21))
#define I2C2_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<22))
#define I2C3_PCLK_DI()			(RCC->APB1ENR1 &= ~(1<<23))
#define I2C4_PCLK_DI()			(RCC->APB1ENR2 &= ~(1<<1))

/*
 * Gpio peripheral reset macros
 */

#define GPIOA_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<0)); (RCC->AHB2RSTR &= ~(1<<0));} while(0)
#define GPIOB_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<1)); (RCC->AHB2RSTR &= ~(1<<1));} while(0)
#define GPIOC_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<2)); (RCC->AHB2RSTR &= ~(1<<2));} while(0)
#define GPIOD_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<3)); (RCC->AHB2RSTR &= ~(1<<3));} while(0)
#define GPIOE_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<4)); (RCC->AHB2RSTR &= ~(1<<4));} while(0)
#define GPIOF_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<5)); (RCC->AHB2RSTR &= ~(1<<5));} while(0)
#define GPIOG_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<6)); (RCC->AHB2RSTR &= ~(1<<6));} while(0)
#define GPIOH_REG_RESET()			do{ (RCC->AHB2RSTR |= (1<<7)); (RCC->AHB2RSTR &= ~(1<<7));} while(0)

/*
 * generic macros
 */

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	ENABLE
#define GPIO_PIN_RESET	DISABLE


#include"stm32l47xx_gpio_driver.h"


#endif
