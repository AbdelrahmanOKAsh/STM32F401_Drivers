/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 10/4/2026                                                               *
*			                                 File: RCC_Config.h                                                               *
*			                                 [ RCC Module Driver ]                                                            *
******************************************************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* RCC SYSTEM CLOCK SOURCE [ RCC_HSI , RCC_HSE , RCC_PLL ] */
#define RCC_SYSTEM_CLOCK_SOURSE         RCC_PLL

    /* CONFIGURATION PARAMETERS ACCORDING TO [ RCC_SYSTEM_CLOCK_SOURSE ] */
    #if RCC_SYSTEM_CLOCK_SOURSE == RCC_HSI
        /* HSI TRIMING OPTIONs [ STD_OFF , [ (EACH STEP -40KHz) 0 : 16 : 32 (EACH STEP +40KHz) ] ] */
        #define HSI_TRIMING     STD_OFF

    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_HSE
        /* HSE TYPE [ HSE_RC , HSE_CRYSTAL ] */
        #define HSE_TYPE           HSE_RC

    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_PLL
        /* PLL CLOCK SOURCE [ RCC_HSI , RCC_HSE ] */
        #define PLL_CLOCK_SOURCE              RCC_HSI

        /* PLL INPUT CLOCK DIVISION FACTOR [ 2 : 63 ] */
        #define PLL_INPUT_DIVISION_FACTOR     2
        
        /* PLL MULTIPLICATION FACTOR [ 2 : 510 (EXCEPT ( 432 , 433 , 511 )) ] */
        #define PLL_MULTIPLICATION_FACTOR     2
    
        /* PLL OUTPUT DIVISION FACTOR [ 2 , 4 , 6 , 8 ] */
        #define PLL_OUTPUT_DIVISION_FACTOR    2
    #endif /* RCC_SYSTEM_CLOCK_SOURSE */

/* AHB PRESCALLER COFIGURATIONs */
#define AHB_PRESCALLER          AHB_SYSCLK

/* APB1 PRESCALLER COFIGURATIONs */
#define APB1_PRESCALLER         APB1_SYSCLK

/* APB2 PRESCALLER COFIGURATIONs */
#define APB2_PRESCALLER         APB2_SYSCLK


/* AHB1 PERIPHERALs CLOCK INIT CONFIGURATIONs [ STD_ON , STD_OFF ] */
#define RCC_INIT_CLOCK_GPIOA    STD_OFF
#define RCC_INIT_CLOCK_GPIOB    STD_OFF
#define RCC_INIT_CLOCK_GPIOC    STD_OFF
#define RCC_INIT_CLOCK_GPIOD    STD_OFF
#define RCC_INIT_CLOCK_GPIOE    STD_OFF
#define RCC_INIT_CLOCK_GPIOH    STD_OFF
#define RCC_INIT_CLOCK_CRC      STD_OFF
#define RCC_INIT_CLOCK_DMA1     STD_OFF
#define RCC_INIT_CLOCK_DMA2     STD_OFF


/* AHB2 PERIPHERALs CLOCK INIT CONFIGURATIONs [ STD_ON , STD_OFF ] */
#define RCC_INIT_CLOCK_USBOTG   STD_OFF


/* APB1 PERIPHERALs CLOCK INIT CONFIGURATIONs [ STD_ON , STD_OFF ] */
#define RCC_INIT_CLOCK_TIM2     STD_OFF
#define RCC_INIT_CLOCK_TIM3     STD_OFF
#define RCC_INIT_CLOCK_TIM4     STD_OFF
#define RCC_INIT_CLOCK_TIM5     STD_OFF
#define RCC_INIT_CLOCK_WWDG     STD_OFF
#define RCC_INIT_CLOCK_SPI2     STD_OFF
#define RCC_INIT_CLOCK_SPI3     STD_OFF
#define RCC_INIT_CLOCK_USART2   STD_OFF
#define RCC_INIT_CLOCK_I2C1     STD_OFF
#define RCC_INIT_CLOCK_I2C2     STD_OFF
#define RCC_INIT_CLOCK_I2C3     STD_OFF
#define RCC_INIT_CLOCK_PWR      STD_OFF


/* APB1 PERIPHERALs CLOCK INIT CONFIGURATIONs [ STD_ON , STD_OFF ] */
#define RCC_INIT_CLOCK_TIM1      STD_OFF
#define RCC_INIT_CLOCK_USART1    STD_OFF
#define RCC_INIT_CLOCK_USART6    STD_OFF
#define RCC_INIT_CLOCK_ADC1      STD_OFF
#define RCC_INIT_CLOCK_SDIO      STD_OFF
#define RCC_INIT_CLOCK_SPI1      STD_OFF
#define RCC_INIT_CLOCK_SPI4      STD_OFF
#define RCC_INIT_CLOCK_SYSFG     STD_OFF
#define RCC_INIT_CLOCK_TIM9      STD_OFF
#define RCC_INIT_CLOCK_TIM10     STD_OFF
#define RCC_INIT_CLOCK_TIM11     STD_OFF


#define MCO1_OUTPUT_CLOCK_SOURCE         MCO1_CLOCK_HSI
#define MCO1_PRESCALLER                  MCO1_NO_DIVISON

#define MCO2_OUTPUT_CLOCK_SOURCE         MCO2_CLOCK_SYSCLOCK
#define MCO2_PRESCALLER                  MCO2_NO_DIVISON



#endif /* RCC_CONFIG_H_ */