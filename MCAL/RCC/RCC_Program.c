/**************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Created: 10/4/2026                                                                 *
*			                             File: RCC_Program.c                                                                *
*			                             [ RCC Module Driver ]                                                              *
****************************************************************************************************************************/

#include "../../LIBs/STD_TYPES.h"
#include "../../LIBs/BIT_MATH.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void RCC_voidInitSystemClock(void)
{
    u32 Local_TimeOutCounter = 0;

    /* SELECT SYSTEM CLOCK SOURCE AND CONFIGURATION */
    #if RCC_SYSTEM_CLOCK_SOURSE == RCC_HSI
        RCC->CFGR.SW  = RCC_HSI;
        #if HSI_TRIMING != STD_OFF
            RCC->CR.HSITRIM = HSI_TRIMING;
        #endif /* HSI_TIMING */
        RCC->CR.HSION = SET;
        while((RCC->CR.HSIRDY == 0) && (Local_TimeOutCounter < RCC_TIMEOUT));
    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_HSE
        RCC->CFGR.SW   = RCC_HSE;
        RCC->CR.HSEBYP = HSE_TYPE;
        RCC->CR.CSSON  = SET;
        RCC->CR.HSEON  = SET;
        while((RCC->CR.HSERDY == 0) && (Local_TimeOutCounter < RCC_TIMEOUT));
    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_PLL
        RCC->CFGR.SW        = RCC_PLL;
        RCC->PLLCFGR.PLLSRC = PLL_CLOCK_SOURCE;
        RCC->PLLCFGR.PLLM   = PLL_INPUT_DIVISION_FACTOR;
        RCC->PLLCFGR.PLLN   = PLL_MULTIPLICATION_FACTOR;
        RCC->PLLCFGR.PLLP   = PLL_OUTPUT_DIVISION_FACTOR;
        RCC->CR.PLLON       = SET;
        while((RCC->CR.PLLRDY == 0) && (Local_TimeOutCounter < RCC_TIMEOUT));          
    #endif /* RCC_SYSTEM_CLOCK_SOURCE */

    /* SET AHB CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if AHB_PRESCALLER != AHB_SYSCLK
        RCC->CFGR.HPRE = AHB_PRESCALLER;
    #endif /* AHB_PRESCALLER */

    /* SET APB1 CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if APB1_PRESCALLER != APB1_SYSCLK
        RCC->CFGR.PPRE1 = APB1_PRESCALLER;
    #endif /* APB1_PRESCALLER */

    /* SET APB2 CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if APB2_PRESCALLER != APB2_SYSCLK
        RCC->CFGR.PPRE2 = APB2_PRESCALLER;
    #endif /* APB2_PRESCALLER */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON AHB1 BUS */
    #if RCC_INIT_CLOCK_GPIOA == STD_ON
        RCC->AHB1ENR.GPIOAEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOA */
    #if RCC_INIT_CLOCK_GPIOB == STD_ON
        RCC->AHB1ENR.GPIOBEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOB */
    #if RCC_INIT_CLOCK_GPIOC == STD_ON
        RCC->AHB1ENR.GPIOCEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOC */
    #if RCC_INIT_CLOCK_GPIOD == STD_ON
        RCC->AHB1ENR.GPIODEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOD */
    #if RCC_INIT_CLOCK_GPIOE == STD_ON
        RCC->AHB1ENR.GPIOEEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOE */
    #if RCC_INIT_CLOCK_GPIOH == STD_ON
        RCC->AHB1ENR.GPIOHEN = SET;
    #endif /* RCC_INIT_CLOCK_GPIOH */
    #if RCC_INIT_CLOCK_CRC   == STD_ON
        RCC->AHB1ENR.CRCEN = SET;
    #endif /* RCC_INIT_CLOCK_CRC */
    #if RCC_INIT_CLOCK_DMA1  == STD_ON
        RCC->AHB1ENR.DMA1EN = SET;
    #endif /* RCC_INIT_CLOCK_DMA1 */
    #if RCC_INIT_CLOCK_DMA2EN == STD_ON
        RCC->AHB1ENR.DMA2EN = SET;
    #endif /* RCC_INIT_CLOCK_DMA2EN */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON AHB2 BUS */
    #if RCC_INIT_CLOCK_USBOTG == STD_ON
        RCC->AHB2ENR.OTGFSEN = SET;
    #endif /* RCC_INIT_CLOCK_USBOTG */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON APB1 BUS */
    #if RCC_INIT_CLOCK_TIM2 == STD_ON
        RCC->APB1ENR.TIM2EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM2 */
    #if RCC_INIT_CLOCK_TIM3 == STD_ON
        RCC->APB1ENR.TIM3EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM3 */
    #if RCC_INIT_CLOCK_TIM4 == STD_ON
        RCC->APB1ENR.TIM4EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM4 */
    #if RCC_INIT_CLOCK_TIM5 == STD_ON
        RCC->APB1ENR.TIM5EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM5 */
    #if RCC_INIT_CLOCK_WWDG == STD_ON
        RCC->APB1ENR.WWDGEN = SET;
    #endif /* RCC_INIT_CLOCK_WWDG */
    #if RCC_INIT_CLOCK_SPI2 == STD_ON
        RCC->APB1ENR.SPI2EN = SET;
    #endif /* RCC_INIT_CLOCK_SPI2 */
    #if RCC_INIT_CLOCK_SPI3 == STD_ON
        RCC->APB1ENR.SPI3EN = SET;
    #endif /* RCC_INIT_CLOCK_SPI3 */
    #if RCC_INIT_CLOCK_USART2 == STD_ON
        RCC->APB1ENR.USART2EN = SET;
    #endif /* RCC_INIT_CLOCK_USART2 */
    #if RCC_INIT_CLOCK_I2C1 == STD_ON
        RCC->APB1ENR.I2C1EN = SET;
    #endif /* RCC_INIT_CLOCK_I2C1 */
    #if RCC_INIT_CLOCK_I2C2 == STD_ON
        RCC->APB1ENR.I2C2EN = SET;
    #endif /* RCC_INIT_CLOCK_I2C2 */
    #if RCC_INIT_CLOCK_I2C3 == STD_ON
        RCC->APB1ENR.I2C3EN = SET;
    #endif /* RCC_INIT_CLOCK_I2C3 */
    #if RCC_INIT_CLOCK_PWR == STD_ON
        RCC->APB1ENR.PWREN = SET;
    #endif /* RCC_INIT_CLOCK_PWR */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON APB2 BUS */
    #if RCC_INIT_CLOCK_TIM1 == STD_ON
        RCC->APB2ENR.TIM1EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM1 */
    #if RCC_INIT_CLOCK_USART1 == STD_ON
        RCC->APB2ENR.USART1EN = SET;
    #endif /* RCC_INIT_CLOCK_USART1 */
    #if RCC_INIT_CLOCK_USART6 == STD_ON
        RCC->APB2ENR.USART6EN = SET;
    #endif /* RCC_INIT_CLOCK_USART6 */
    #if RCC_INIT_CLOCK_ADC1 == STD_ON
        RCC->APB2ENR.ADC1EN = SET;
    #endif /* RCC_INIT_CLOCK_ADC1 */
    #if RCC_INIT_CLOCK_SDIO == STD_ON
        RCC->APB2ENR.SDIOEN = SET;
    #endif /* RCC_INIT_CLOCK_SDIO */
    #if RCC_INIT_CLOCK_SPI1 == STD_ON
        RCC->APB2ENR.SPI1EN = SET;
    #endif /* RCC_INIT_CLOCK_SPI1 */
    #if RCC_INIT_CLOCK_SPI4 == STD_ON
        RCC->APB2ENR.SPI4EN = SET;
    #endif /* RCC_INIT_CLOCK_SPI4 */
    #if RCC_INIT_CLOCK_SYSFG == STD_ON
        RCC->APB2ENR.SYSFGEN = SET;
    #endif /* RCC_INIT_CLOCK_SYSFG */
    #if RCC_INIT_CLOCK_TIM9 == STD_ON
        RCC->APB2ENR.TIM9EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM9 */
    #if RCC_INIT_CLOCK_TIM10 == STD_ON
        RCC->APB2ENR.TIM10EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM10 */
    #if RCC_INIT_CLOCK_TIM11 == STD_ON
        RCC->APB2ENR.TIM11EN = SET;
    #endif /* RCC_INIT_CLOCK_TIM11 */

    /* SET MCO1 OUTPUT CLOCK CONFIGURATIONs */
    RCC->CFGR.MCO1    = MCO1_OUTPUT_CLOCK_SOURCE;
    RCC->CFGR.MCO1PRE = MCO1_PRESCALLER;

    /* SET MCO2 OUTPUT CLOCK CONFIGURATIONs */
    RCC->CFGR.MCO2    = MCO2_OUTPUT_CLOCK_SOURCE;
    RCC->CFGR.MCO2PRE = MCO2_PRESCALLER;
}






VALIDATION RCC_enumEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: SET_BIT(RCC->AHB1ENR.REG,Copy_u8PeripheralID); break;
            case RCC_AHB2: SET_BIT(RCC->AHB2ENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB1: SET_BIT(RCC->APB1ENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB2: SET_BIT(RCC->APB2ENR.REG,Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;              break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}






VALIDATION RCC_enumDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: CLEAR_BIT(RCC->AHB1ENR.REG,Copy_u8PeripheralID); break;
            case RCC_AHB2: CLEAR_BIT(RCC->AHB2ENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB1: CLEAR_BIT(RCC->APB1ENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB2: CLEAR_BIT(RCC->APB2ENR.REG,Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;                break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





VALIDATION RCC_enumEnableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: SET_BIT(RCC->AHB1LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_AHB2: SET_BIT(RCC->AHB2LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB1: SET_BIT(RCC->APB1LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB2: SET_BIT(RCC->APB2LPENR.REG,Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;                break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}






VALIDATION RCC_enumDisableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: CLEAR_BIT(RCC->AHB1LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_AHB2: CLEAR_BIT(RCC->AHB2LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB1: CLEAR_BIT(RCC->APB1LPENR.REG,Copy_u8PeripheralID); break;
            case RCC_APB2: CLEAR_BIT(RCC->APB2LPENR.REG,Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;                  break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





VALIDATION RCC_enumResetPeripheral(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: SET_BIT(RCC->AHB1RSTR.REG,Copy_u8PeripheralID); break;
            case RCC_AHB2: SET_BIT(RCC->AHB2RSTR.REG,Copy_u8PeripheralID); break;
            case RCC_APB1: SET_BIT(RCC->APB1RSTR.REG,Copy_u8PeripheralID); break;
            case RCC_APB2: SET_BIT(RCC->APB2RSTR.REG,Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;               break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}