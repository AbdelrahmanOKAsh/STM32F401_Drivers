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




/****************************************************************************************************************************** 
* Brief: Function Used to CONFIGURE AND INIT SYSTEM CLOCK AT STARTUP                                                          *
* Parameters: VOID                                                                                                            *
* Return:     VOID                                                                                                            *
******************************************************************************************************************************/
void RCC_voidInitSystemClock(void)
{
    u32 Local_u32TimeOutCounter = 0;

    /* SELECT SYSTEM CLOCK SOURCE AND CONFIGURATION */
    #if RCC_SYSTEM_CLOCK_SOURSE == RCC_HSI
        /* ACTIVATE HSI OSCILLATOR */
        RCC->CR |= (1 << HSION);
        /* CONFIGURE HSI TRIMMING VALUE */
        #if HSI_TRIMING != STD_OFF
            RCC->CR |= (HSI_TRIMING << HSITRIM);
        #endif /* HSI_TRIMMING */
        /* POLLING UNTIL HSI OSCILLATOR BEING STABLE */
        while(((RCC->CR >> HSIRDY) & 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT));

    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_HSE
        /* ACTIVATE AND ENABLE HSE */
        RCC->CR |= (1 << HSEON);
        /* ACTIVATE AND ENABLE CLOCK SECURITY SYSTEM */
        RCC->CR |= (1 << CSSON);
        /* CONFIGURE HSE TYPE */
        #if HSE_TYPE == HSE_RC
            RCC->CR |= (1 << HSEBYP);
        #endif
        /* SELECT SYSTEM CLOCK SWITCH AS HSE */
        RCC->CFGR |= (RCC_HSE << SW0);
        /* POLLING UNTIL HSE OSCILLATOR BEING STABLE */
        while(((RCC->CR >> HSERDY) & 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT));

    #elif RCC_SYSTEM_CLOCK_SOURSE == RCC_PLL
        /* ACTIVATE HSI OSCILLATOR */
        RCC->CR |= (1 << HSION);
        /* CONFIGURE PLL */
        RCC->PLLCFGR = (u32)((PLL_INPUT_DIVISION_FACTOR << PLLM) | (PLL_MULTIPLICATION_FACTOR << PLLN) | (PLL_OUTPUT_DIVISION_FACTOR << PLLP) | (PLL_CLOCK_SOURCE << PLLSRC));
        /* ACTIVATE AND ENABLE PLL */
        RCC->CR |= (1 << PLLON);
        /* SELECT SYSTEM CLOCK SWITCH AS PLL */
        RCC->CFGR |= (RCC_PLL << SW0);
        /* POLLING UNTIL PLL CIRCUIT BEING STABLE */
        while(((RCC->CR >> PLLRDY) & 1) && (Local_u32TimeOutCounter < RCC_TIMEOUT));

    #endif /* RCC_SYSTEM_CLOCK_SOURCE */

    /* SET AHB CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if AHB_PRESCALLER != AHB_SYSCLK
        RCC->CFGR |= (AHB_PRESCALLER << HPRE);
    #endif /* AHB_PRESCALLER */

    /* SET APB1 CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if APB1_PRESCALLER != APB1_SYSCLK
       RCC->CFGR |= (APB1_PRESCALLER << PPRE1);
    #endif /* APB1_PRESCALLER */

    /* SET APB2 CLOCK PRESCALLER IF A PRESCALLER CONFIGURED */
    #if APB2_PRESCALLER != APB2_SYSCLK
        RCC->CFGR |= (APB2_PRESCALLER << PPRE2);
    #endif /* APB2_PRESCALLER */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON AHB1 BUS */
    #if RCC_INIT_CLOCK_GPIOA == STD_ON
        RCC->AHB1ENR |= (1 << GPIOAEN);
    #endif /* RCC_INIT_CLOCK_GPIOA */
    #if RCC_INIT_CLOCK_GPIOB == STD_ON
        RCC->AHB1ENR |= (1 << GPIOBEN);
    #endif /* RCC_INIT_CLOCK_GPIOB */
    #if RCC_INIT_CLOCK_GPIOC == STD_ON
        RCC->AHB1ENR |= (1 << GPIOCEN);
    #endif /* RCC_INIT_CLOCK_GPIOC */
    #if RCC_INIT_CLOCK_GPIOD == STD_ON
        RCC->AHB1ENR |= (1 << GPIODEN);
    #endif /* RCC_INIT_CLOCK_GPIOD */
    #if RCC_INIT_CLOCK_GPIOE == STD_ON
        RCC->AHB1ENR |= (1 << GPIOEEN);
    #endif /* RCC_INIT_CLOCK_GPIOE */
    #if RCC_INIT_CLOCK_GPIOH == STD_ON
        RCC->AHB1ENR |= (1 << GPIOHEN);
    #endif /* RCC_INIT_CLOCK_GPIOH */
    #if RCC_INIT_CLOCK_CRC   == STD_ON
        RCC->AHB1ENR |= (1 << CRCEN );
    #endif /* RCC_INIT_CLOCK_CRC */
    #if RCC_INIT_CLOCK_DMA1  == STD_ON
        RCC->AHB1ENR |= (1 << DMA1EN);
    #endif /* RCC_INIT_CLOCK_DMA1 */
    #if RCC_INIT_CLOCK_DMA2  == STD_ON
        RCC->AHB1ENR |= (1 << DMA2EN);
    #endif /* RCC_INIT_CLOCK_DMA2 */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON AHB2 BUS */
    #if RCC_INIT_CLOCK_USBOTG == STD_ON
       RCC->AHB2ENR |= (1 << OTGFSEN);
    #endif /* RCC_INIT_CLOCK_USBOTG */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON APB1 BUS */
    #if RCC_INIT_CLOCK_TIM2   == STD_ON
        RCC->APB1ENR |= (1 << TIM2EN);
    #endif /* RCC_INIT_CLOCK_TIM2 */
    #if RCC_INIT_CLOCK_TIM3   == STD_ON
        RCC->APB1ENR |= (1 << TIM3EN);
    #endif /* RCC_INIT_CLOCK_TIM3 */
    #if RCC_INIT_CLOCK_TIM4   == STD_ON
        RCC->APB1ENR |= (1 << TIM4EN);
    #endif /* RCC_INIT_CLOCK_TIM4 */
    #if RCC_INIT_CLOCK_TIM5   == STD_ON
        RCC->APB1ENR |= (1 << TIM5EN);
    #endif /* RCC_INIT_CLOCK_TIM5 */
    #if RCC_INIT_CLOCK_WWDG   == STD_ON
        RCC->APB1ENR |= (1 << WWDGEN);
    #endif /* RCC_INIT_CLOCK_WWDG */
    #if RCC_INIT_CLOCK_SPI2   == STD_ON
        RCC->APB1ENR |= (1 << SPI2EN);
    #endif /* RCC_INIT_CLOCK_SPI2 */
    #if RCC_INIT_CLOCK_SPI3   == STD_ON
        RCC->APB1ENR |= (1 << SPI3EN);
    #endif /* RCC_INIT_CLOCK_SPI3 */
    #if RCC_INIT_CLOCK_USART2 == STD_ON
        RCC->APB1ENR |= (1 << USART2EN);
    #endif /* RCC_INIT_CLOCK_USART2EN*/
    #if RCC_INIT_CLOCK_I2C1   == STD_ON
        RCC->APB1ENR |= (1 << I2C1EN);
    #endif /* RCC_INIT_CLOCK_I2C1 */
    #if RCC_INIT_CLOCK_I2C2   == STD_ON
        RCC->APB1ENR |= (1 << I2C2EN);
    #endif /* RCC_INIT_CLOCK_I2C2 */
    #if RCC_INIT_CLOCK_I2C3   == STD_ON
        RCC->APB1ENR |= (1 << I2C3EN);
    #endif /* RCC_INIT_CLOCK_I2C3 */
    #if RCC_INIT_CLOCK_PWR    == STD_ON
        RCC->APB1ENR |= (1 << PWREN);
    #endif /* RCC_INIT_CLOCK_PWR */

    /* ENABLE CLOCK FOR ALL ACTIVE PERIPHERALs ON APB2 BUS */
    #if RCC_INIT_CLOCK_TIM1   == STD_ON
        RCC->APB2ENR |= (1 << TIM1EN);
    #endif /* RCC_INIT_CLOCK_TIM1 */
    #if RCC_INIT_CLOCK_USART1 == STD_ON
        RCC->APB2ENR |= (1 << USART1EN);
    #endif /* RCC_INIT_CLOCK_USART1EN */
    #if RCC_INIT_CLOCK_USART6 == STD_ON
        RCC->APB2ENR |= (1 << USART6EN);
    #endif /* RCC_INIT_CLOCK_USART6EN */
    #if RCC_INIT_CLOCK_ADC1   == STD_ON
        RCC->APB2ENR |= (1 << ADC1EN);
    #endif /* RCC_INIT_CLOCK_ADC1 */
    #if RCC_INIT_CLOCK_SDIO   == STD_ON
        RCC->APB2ENR |= (1 << SDIOEN);
    #endif /* RCC_INIT_CLOCK_SDIO */
    #if RCC_INIT_CLOCK_SPI1   == STD_ON
        RCC->APB2ENR |= (1 << SPI1EN);
    #endif /* RCC_INIT_CLOCK_SPI1 */
    #if RCC_INIT_CLOCK_SPI4   == STD_ON
        RCC->APB2ENR |= (1 << SPI4EN);
    #endif /* RCC_INIT_CLOCK_SPI4 */
    #if RCC_INIT_CLOCK_SYSFG  == STD_ON
        RCC->APB2ENR |= (1 << SYSFGEN);
    #endif /* RCC_INIT_CLOCK_SYSFGEN */
    #if RCC_INIT_CLOCK_TIM9   == STD_ON
        RCC->APB2ENR |= (1 << TIM9EN);
    #endif /* RCC_INIT_CLOCK_TIM9 */
    #if RCC_INIT_CLOCK_TIM10  == STD_ON
        RCC->APB2ENR |= (1 << TIM10EN);
    #endif /* RCC_INIT_CLOCK_TIM10 */
    #if RCC_INIT_CLOCK_TIM11  == STD_ON
        RCC->APB2ENR |= (1 << TIM11EN);
    #endif /* RCC_INIT_CLOCK_TIM11 */

    /* SET MCO1 & MCO2 OUTPUT CLOCK CONFIGURATIONs */
    RCC->CFGR = (MCO1_OUTPUT_CLOCK_SOURCE << MCO1) | (MCO1_PRESCALLER << MCO1PRE) | (MCO2_PRESCALLER << MCO2PRE) | (MCO2_OUTPUT_CLOCK_SOURCE << MCO2);  
}





/****************************************************************************************************************************** 
* Brief: FUNCTION USED TO ENABLE PERIPHERAL CLOCK                                                                             *
* Parameters:                                                                                                                 *
*       [1]-BUS ID          [ RCC_AHB1 , RCC_AHB2 , RCC_APB1 , RCC_APB2 ]                                                     *
*       [2]-PERIPHERAL ID                                                                                                     *
* Return: ENUM        [ VALID , INVALID ]                                                                                     *
******************************************************************************************************************************/
VALIDATION RCC_enumEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: RCC->AHB1ENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_AHB2: RCC->AHB2ENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB1: RCC->APB1ENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB2: RCC->APB2ENR |= (1 << Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;           break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: FUNCTION USED TO DISABLE PERIPHERAL CLOCK                                                                            *
* Parameters:                                                                                                                 *
*       [1]-BUS ID          [ RCC_AHB1 , RCC_AHB2 , RCC_APB1 , RCC_APB2 ]                                                     *
*       [2]-PERIPHERAL ID                                                                                                     *
* Return: ENUM        [ VALID , INVALID ]                                                                                     *
******************************************************************************************************************************/
VALIDATION RCC_enumDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: RCC->AHB1ENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_AHB2: RCC->AHB2ENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_APB1: RCC->APB1ENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_APB2: RCC->APB2ENR &= ~(1 << Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;            break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}




/****************************************************************************************************************************** 
* Brief: FUNCTION USED TO ENABLE LOW POWER PERIPHERAL CLOCK                                                                   *
* Parameters:                                                                                                                 *
*       [1]-BUS ID          [ RCC_AHB1 , RCC_AHB2 , RCC_APB1 , RCC_APB2 ]                                                     *
*       [2]-PERIPHERAL ID                                                                                                     *
* Return: ENUM        [ VALID , INVALID ]                                                                                     *
******************************************************************************************************************************/
VALIDATION RCC_enumEnableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: RCC->AHB1LPENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_AHB2: RCC->AHB2LPENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB1: RCC->APB1LPENR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB2: RCC->APB2LPENR |= (1 << Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;             break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}





/****************************************************************************************************************************** 
* Brief: FUNCTION USED TO DISABLE LOW POWER PERIPHERAL CLOCK                                                                  *
* Parameters:                                                                                                                 *
*       [1]-BUS ID          [ RCC_AHB1 , RCC_AHB2 , RCC_APB1 , RCC_APB2 ]                                                     *
*       [2]-PERIPHERAL ID                                                                                                     *
* Return: ENUM        [ VALID , INVALID ]                                                                                     *
******************************************************************************************************************************/
VALIDATION RCC_enumDisableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: RCC->AHB1LPENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_AHB2: RCC->AHB2LPENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_APB1: RCC->APB1LPENR &= ~(1 << Copy_u8PeripheralID); break;
            case RCC_APB2: RCC->APB2LPENR &= ~(1 << Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;              break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}




/****************************************************************************************************************************** 
* Brief: FUNCTION USED TO RESET PERIPHERAL                                                                                    *
* Parameters:                                                                                                                 *
*       [1]-BUS ID          [ RCC_AHB1 , RCC_AHB2 , RCC_APB1 , RCC_APB2 ]                                                     *
*       [2]-PERIPHERAL ID                                                                                                     *
* Return: ENUM        [ VALID , INVALID ]                                                                                     *
******************************************************************************************************************************/
VALIDATION RCC_enumResetPeripheral(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
    VALIDATION Local_ValidationStatus = VALID;
    if((Copy_u8BusID <= RCC_APB2) && (Copy_u8PeripheralID <= 31))
    {
        switch(Copy_u8BusID)
        {
            case RCC_AHB1: RCC->AHB1RSTR |= (1 << Copy_u8PeripheralID); break;
            case RCC_AHB2: RCC->AHB2RSTR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB1: RCC->APB1RSTR |= (1 << Copy_u8PeripheralID); break;
            case RCC_APB2: RCC->APB2RSTR |= (1 << Copy_u8PeripheralID); break;
            default      : Local_ValidationStatus = INVALID;            break;
        }
    }

    else
    {
        Local_ValidationStatus = INVALID;
    }

    return Local_ValidationStatus;
}