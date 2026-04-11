/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 10/4/2026                                                               *
*			                                 File: RCC_Private.h                                                              *
*			                                 [ RCC Module Driver ]                                                            *
******************************************************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* RCC CR REGISTER */
typedef union CR_REGISTER
{
    u32 HSION:1;
    u32 HSIRDY:1;
    u32 RESERVED0:1;
    u32 HSITRIM:5;
    u32 HSICAL:8;
    u32 HSEON:1;
    u32 HSERDY:1;
    u32 HSEBYP:1;
    u32 CSSON:1;
    u32 RESERVED1:4;
    u32 PLLON:1;
    u32 PLLRDY:1;
    u32 PLLI2SON:1;
    u32 PLLI2SRDY:1;
    u32 RESERVED2:4;
    u32 REG;
}CR_REG;

/* RCC PLLCFGR REGISTER */
typedef union PLLCFGR_REGISTER
{
    u32 PLLM:6;
    u32 PLLN:9;
    u32 RESERVED0:1;
    u32 PLLP:2;
    u32 RESERVED1:4;
    u32 PLLSRC:1;
    u32 RESERVED2:1;
    u32 PLLQ:4;
    u32 RESERVED3:4;
    u32 REG;
}PLLCFGR_REG;

/* RCC CFGR REGISTER */
typedef union CFGR_REGISTER
{
    u32 SW:2;
    u32 SWS:2;
    u32 HPRE:4;
    u32 RESERVED0:2;
    u32 PPRE1:3;
    u32 PPRE2:3;
    u32 RTCPRE:5;
    u32 MCO1:2;
    u32 I2SSCR:1;
    u32 MCO1PRE:3;
    u32 MCO2PRE:3;
    u32 MCO2:2;
    u32 REG;
}CFGR_REG;

/* RCC CIR REGISTER */
typedef union CIR_REGISTER
{
    u32 LSIRDYF    :1;
    u32 LSERDYF    :1;
    u32 HSIRDYF    :1;
    u32 HSERDYF    :1;
    u32 PLLRDYF    :1;
    u32 PLLI2SRDYF :1;
    u32 RESERVED0  :1;
    u32 CSSF       :1;
    u32 LSIRDYIE   :1;
    u32 LSERDYIE   :1;
    u32 HSIRDYIE   :1;
    u32 HSERDYIE   :1;
    u32 PLLRDYIE   :1;
    u32 PLLI2SRDYIE:1;
    u32 RESERVED1  :2;
    u32 LSIRDYC    :1;
    u32 LSERDYC    :1;
    u32 HSIRDYC    :1;
    u32 HSERDYC    :1;
    u32 PLLRDYC    :1;
    u32 PLLI2SRDYC :1;
    u32 RESERVED2  :1;
    u32 CSSC       :1;
    u32 RESERVED3  :8;
    u32 REG;
}CIR_REG;

/* RCC AHB1RSTR REGISTER */
typedef union AHB1RSTR_REGISTER
{
    u32 GPIOARST:1; 
    u32 GPIOBRST:1; 
    u32 GPIOCRST:1; 
    u32 GPIODRST:1; 
    u32 GPIOERST:1;
    u32 RESERVED0:2;
    u32 GPIOHRST:1;
    u32 RESERVED1:4;
    u32 CRCRST:1;
    u32 RESERVED2:3;
    u32 RESERVED3:5;
    u32 DMA1RST:1;
    u32 DMA2RST:1;
    u32 RESERVED4:9;
    u32 REG;
}AHB1RSTR_REG;

/* RCC AHB2RSTR REGISTER */
typedef union AHB2RSTR_REGISTER
{
    u32 RESERVED0:7;
    u32 OTGFSRST:1;
    u32 RESERVED1:24;
    u32 REG;
}AHB2RSTR_REG;

/* RCC APB1RSTR REGISTER */
typedef union APB1RSTR_REGISTER
{
    u32 TIM2RST:1;
    u32 TIM3RST:1;
    u32 TIM4RST:1;
    u32 TIM5RST:1;
    u32 RESERVED0:7;
    u32 WWDGRST:1;
    u32 RESERVED1:2;
    u32 SPI2RST:1;
    u32 SPI3RST:1;
    u32 RESERVED2:1;
    u32 USART2RST:1;
    u32 RESERVED3:3;
    u32 I2C1RST:1;
    u32 I2C2RST:1;
    u32 I2C3RST:1;
    u32 RESERVED4:4;
    u32 PWRRST:1;
    u32 RESERVED5:3;
    u32 REG;
}APB1RSTR_REG;

/* RCC APB2RSTR REGISTER */
typedef union APB2RSTR_REGISTER
{
    u32 TIM1RST:1;
    u32 RESERVED0:3;
    u32 USART1RST:1;
    u32 USART6RST:1;
    u32 RESERVED1:2;
    u32 ADC1RST:1;
    u32 RESERVED2:2;
    u32 SDIORST:1;
    u32 SPI1RST:1;
    u32 SPI4RST:1;
    u32 SYSFGRST:1;
    u32 RESERVED3:1;
    u32 TIM9RST:1;
    u32 TIM10RST:1;
    u32 TIM11RST:1;
    u32 RESERVED4:13;
    u32 REG;
}APB2RSTR_REG;

/* RCC AHB1ENR REGISTER */
typedef union AHB1ENR_REGISTER
{
    
    u32 GPIOAEN:1; 
    u32 GPIOBEN:1; 
    u32 GPIOCEN:1; 
    u32 GPIODEN:1; 
    u32 GPIOEEN:1;
    u32 RESERVED0:2;
    u32 GPIOHEN:1;
    u32 RESERVED1:4;
    u32 CRCEN:1;
    u32 RESERVED2:3;
    u32 RESERVED3:5;
    u32 DMA1EN:1;
    u32 DMA2EN:1;
    u32 RESERVED4:9;
    u32 REG;
}AHB1ENR_REG;

/* RCC AHB2ENR REGISTER */
typedef union AHB2ENR_REGISTER
{
    u32 RESERVED0:7;
    u32 OTGFSEN:1;
    u32 RESERVED1:24;
    u32 REG;
}AHB2ENR_REG;

/* RCC APB1ENR REGISTER */
typedef union APB1ENR_REGISTER
{
    u32 TIM2EN:1;
    u32 TIM3EN:1;
    u32 TIM4EN:1;
    u32 TIM5EN:1;
    u32 RESERVED0:7;
    u32 WWDGEN:1;
    u32 RESERVED1:2;
    u32 SPI2EN:1;
    u32 SPI3EN:1;
    u32 RESERVED2:1;
    u32 USART2EN:1;
    u32 RESERVED3:3;
    u32 I2C1EN:1;
    u32 I2C2EN:1;
    u32 I2C3EN:1;
    u32 RESERVED4:4;
    u32 PWREN:1;
    u32 RESERVED5:3;
    u32 REG;
}APB1ENR_REG;

/* RCC APB2RENR REGISTER */
typedef union APB2RENR_REGISTER
{
    u32 TIM1EN:1;
    u32 RESERVED0:3;
    u32 USART1EN:1;
    u32 USART6EN:1;
    u32 RESERVED1:2;
    u32 ADC1EN:1;
    u32 RESERVED2:2;
    u32 SDIOEN:1;
    u32 SPI1EN:1;
    u32 SPI4EN:1;
    u32 SYSFGEN:1;
    u32 RESERVED3:1;
    u32 TIM9EN:1;
    u32 TIM10EN:1;
    u32 TIM11EN:1;
    u32 RESERVED4:13;
    u32 REG;
}APB2RENR_REG;

/* RCC AHB1LPENR REGISTER */
typedef union AHB1LPENR_REGISTER
{
    u32 GPIOALPEN:1;
    u32 GPIOBLPEN:1;
    u32 GPIOCLPEN:1;
    u32 GPIODLPEN:1;
    u32 GPIOELPEN:1;
    u32 RESERVED0:2;
    u32 GPIOHLPEN:1;
    u32 RESERVED1:4;
    u32 CRCLPEN  :1;
    u32 RESERVED2:2;
    u32 FLITFLPEN:1;
    u32 SRAM1LPEN:1;
    u32 RESERVED3:4;
    u32 DMA1LPEN :1;
    u32 DMA2LPEN :1;
    u32 RESERVED4:9;
    u32 REG;
}AHB1LPENR_REG;

/* RCC AHB2LPENR REGISTER */
typedef union AHB2LPENR_REGISTER
{
    u32 RESERVED0:7;
    u32 OTGFSLPEN:1;
    u32 RESERVED1:8;
    u32 RESERVED2:16;
    u32 REG;
}AHB2LPENR_REG;

/* RCC APB1LPENR REGISTER */
typedef union APB1LPENR_REGISTER
{
    u32 TIM2LPEN :1;
    u32 TIM3LPEN :1;
    u32 TIM4LPEN :1;
    u32 TIM5LPEN :1;
    u32 RESERVED0:7;
    u32 WWDGLPEN :1;
    u32 RESERVED1:2;
    u32 SPI2LPEN :1;
    u32 SPI3LPEN :1;
    u32 RESERVED2:1;
    u32 USART2LPEN:1;
    u32 RESERVED3:3;
    u32 I2C1LPEN :1;
    u32 I2C2LPEN :1;
    u32 I2C3LPEN :1;
    u32 RESERVED4:4;
    u32 PWRLPEN  :1;
    u32 RESERVED5:3;
    u32 REG;
}APB1LPENR_REG;

/* RCC APB2LPENR REGISTER */
typedef union APB2LPENR_REGISTER
{
    u32 TIM1LPEN :1;
    u32 RESERVED0:3;
    u32 USART1LPEN:1;
    u32 USART6LPEN:1;
    u32 RESERVED1:2;
    u32 ADC1LPEN:1;
    u32 RESERVED2:2;
    u32 SDIOLPEN :1;
    u32 SPI1LPEN :1;
    u32 SPI4LPEN :1;
    u32 SYSCFGLPEN:1;
    u32 RESERVED3:1;
    u32 TIM9LPEN :1;
    u32 TIM10LPEN:1;
    u32 TIM11LPEN:1;
    u32 RESERVED4:13;
    u32 REG;
}APB2LPENR_REG;

/* RCC BDCR REGISTER */
typedef union BDCR_REGISTER
{
    u32 LSEON    :1;
    u32 LSERDY   :1;
    u32 LSEBYP   :1;
    u32 RESERVED0:5;
    u32 RTCSEL   :2;
    u32 RESERVED1:5;
    u32 RTCEN    :1;
    u32 BDRST    :1;
    u32 RESERVED2:15;
    u32 REG;
}BDCR_REG;

/* RCC CSR REGISTER */
typedef union CSR_REGISTER
{
    u32 LSION    :1;
    u32 LSIRDY   :1;
    u32 RESERVED0:14;
    u32 RESERVED1:8;
    u32 RMVF     :1;
    u32 BORRSTF  :1;
    u32 PINRSTF  :1;
    u32 PORRSTF  :1;
    u32 SFTRSTF  :1;
    u32 IWDGRSTF :1;
    u32 WWDGRSTF :1;
    u32 LPWRRSTF :1;
    u32 REG;
}CSR_REG;

/* RCC SCGR REGISTER */
typedef union SCGR_REGISTER
{
    u32 MODPER   :13;
    u32 INCSTEP  :15;
    u32 RESERVED0:2;
    u32 SPREADSEL:1;
    u32 SSCGEN   :1;    
    u32 REG;
}SSCGR_REG;

/* RCC PLLI2SCFGR REGISTER */
typedef union PLLI2SCFGR_REGISTER
{
    u32 RESERVED0 :6;
    u32 PLLI2SN   :9;
    u32 RESERVED1 :13;
    u32 PLLI2S    :3;
    u32 RESERVED2 :1;
    u32 REG;
}PLLI2SCFGR_REG;

/* RCC DCKCFGR REGISTER */
typedef union DCKCFGR_REGISTER
{
    u32 RESERVED0:16;
    u32 RESERVED1:8;
    u32 TIMPRE   :1;
    u32 RESERVED2:7;
    u32 REG;
}DCKCFGR_REG;


typedef struct RCC_REGISTERFILE
{
    volatile CR_REG CR;
    volatile PLLCFGR_REG PLLCFGR;
    volatile CFGR_REG CFGR;
    volatile CIR_REG CIR;
    volatile AHB1RSTR_REG AHB1RSTR;
    volatile AHB2RSTR_REG AHB2RSTR;
    volatile u32 RESERVED0[2];
    volatile APB1RSTR_REG APB1RSTR;
    volatile APB2RSTR_REG APB2RSTR;
    volatile RESERVED1[2];
    volatile AHB1ENR_REG AHB1ENR;
    volatile AHB2ENR_REG AHB2ENR;
    volatile u32 RESERVED2[2];
    volatile APB1ENR_REG APB1ENR;
    volatile APB2RENR_REG APB2RENR;
    volatile u32 RESERVED3[2];
    volatile AHB1LPENR_REG AHB1LPENR;
    volatile AHB2LPENR_REG AHB2LPENR;
    volatile u32 RESERVED4[2];
    volatile APB1LPENR_REG APB1LPENR;
    volatile APB2LPENR_REG APB2LPENR;
    volatile u32 RESERVED5[2];
    volatile BDCR_REG BDCR;
    volatile CSR_REG CSR;
    volatile RESERVED6[2];
    volatile SSCGR_REG SSCGR;
    volatile PLLI2SCFGR_REG PLLI2SCFGR;
    volatile u32 RESERVED7;
    volatile DCKCFGR_REG DCKCFGR;
}RCC_REG;


/* RCC REISTER FILE BASE ADDRESS AND MEMORY MAPPING */
#define RCC_BASE_ADDRESS 0x40023800
#define RCC  ((RCC_REG*)RCC_BASE_ADDRESS)

/* RCC TIME OUT */
#define RCC_TIMEOUT       10000UL

#endif /* RCC_PRIVATE_H_ */