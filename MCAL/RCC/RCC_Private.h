/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 10/4/2026                                                               *
*			                                 File: RCC_Private.h                                                              *
*			                                 [ RCC Module Driver ]                                                            *
******************************************************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* RCC CR REGISTER */
#define HSION              0
#define HSIRDY             1
#define HSITRIM            3
#define HSICAL             8
#define HSEON              16
#define HSERDY             17
#define HSEBYP             18
#define CSSON              19
#define PLLON              24
#define PLLRDY             25
#define PLLI2SON           26
#define PLLI2SRDY          27


/* RCC PLLCFGR REGISTER */
#define PLLM               0
#define PLLN               6
#define PLLP               16
#define PLLSRC             22
#define PLLQ               24


/* RCC CFGR REGISTER */
#define SW0                0
#define SW1                1
#define SWS                2
#define HPRE               4
#define PPRE1              10
#define PPRE2              13
#define RTCPRE             16
#define MCO1               21
#define I2SSCR             23
#define MCO1PRE            24
#define MCO2PRE            27
#define MCO2               30

/* RCC AHB1RSTR REGISTER */
#define GPIOARST           0
#define GPIOBRST           1
#define GPIOCRST           2
#define GPIODRST           3
#define GPIOERST           4
#define GPIOHRST           7
#define CRCRST             12
#define DMA1RST            21
#define DMA2RST            22


/* RCC AHB2RSTR REGISTER */
#define OTGFSRST           7

/* RCC APB1RSTR REGISTER */
#define TIM2RST            0
#define TIM3RST            1
#define TIM4RST            2
#define TIM5RST            3
#define WWDGRST            11
#define SPI2RST            14
#define SPI3RST            15
#define USART2RST          17
#define I2C1RST            21
#define I2C2RST            22
#define I2C3RST            23
#define PWRRST             27


/* RCC APB2RSTR REGISTER */
#define TIM1RST            0
#define USART1RST          4
#define USART6RST          5
#define ADC1RST            8
#define SDIORST            11
#define SPI1RST            12
#define SPI4RST            13
#define SYSFGRST           14
#define TIM9RST            16
#define TIM10RST           17
#define TIM11RST           18


/* RCC AHB1ENR REGISTER */
#define GPIOAEN           0
#define GPIOBEN           1
#define GPIOCEN           2
#define GPIODEN           3
#define GPIOEEN           4
#define GPIOHEN           7
#define CRCEN             12
#define DMA1EN            21
#define DMA2EN            22

/* RCC AHB2ENR REGISTER */
#define OTGFSEN           7

/* RCC APB1ENR REGISTER */
#define TIM2EN            0
#define TIM3EN            1
#define TIM4EN            2
#define TIM5EN            3
#define WWDGEN            11
#define SPI2EN            14
#define SPI3EN            15
#define USART2EN          17
#define I2C1EN            21
#define I2C2EN            22
#define I2C3EN            23
#define PWREN             27

/* RCC APB2RENR REGISTER */
#define TIM1EN            0
#define USART1EN          4
#define USART6EN          5
#define ADC1EN            8
#define SDIOEN            11
#define SPI1EN            12
#define SPI4EN            13
#define SYSFGEN           14
#define TIM9EN            16
#define TIM10EN           17
#define TIM11EN           18


/* RCC REGISTER FILE IMAGE */
typedef struct RCC_REGISTERFILE
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 RESERVED0[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 RESERVED1[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 RESERVED2[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 RESERVED3[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 RESERVED4[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 RESERVED5[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 RESERVED6[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 RESERVED7;
    volatile u32 DCKCFGR;
}RCC_REG;



/* RCC REISTER FILE BASE ADDRESS AND MEMORY MAPPING */
#define RCC_BASE_ADDRESS 0x40023800
#define RCC  ((RCC_REG*)RCC_BASE_ADDRESS)

/* RCC TIME OUT */
#define RCC_TIMEOUT       10000UL

#endif /* RCC_PRIVATE_H_ */