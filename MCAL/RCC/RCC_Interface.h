/****************************************************************************************************************************** 
*                                            Author: Abdelrahman Gamal OKASHA                                                 *
*			                                 Created: 10/4/2026                                                               *
*			                                 File: RCC_Interface.h                                                            *
*			                                 [ RCC Module Driver ]                                                            *
******************************************************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* RCC CLOCK SOURCE INTERFACE OPTIONs */
#define RCC_HSI                        0b00
#define RCC_HSE                        0b01
#define RCC_PLL                        0b10


/* HSE TYPE */
#define HSE_CRYSTAL                    0
#define HSE_RC                         1

/* RCC BUS IDs INTERFACE OPTIONs */
#define RCC_AHB1                       0
#define RCC_AHB2                       1
#define RCC_APB1                       2
#define RCC_APB2                       3

/* AHB BUS CLOCK PRESCALLER INTERFACE OPTIONs */
#define AHB_SYSCLK                     0b0000
#define AHB_SYSCLK_DIVISION_2          0b1000
#define AHB_SYSCLK_DIVISION_4          0b1001
#define AHB_SYSCLK_DIVISION_8          0b1010
#define AHB_SYSCLK_DIVISION_16         0b1011
#define AHB_SYSCLK_DIVISION_64         0b1100
#define AHB_SYSCLK_DIVISION_128        0b1101
#define AHB_SYSCLK_DIVISION_256        0b1110
#define AHB_SYSCLK_DIVISION_512        0b1111


/* APB1 BUS CLOCK PRESCALLER INTERFACE OPTIONs */
#define APB1_SYSCLK                      0b000
#define APB1_SYSCLK_DIVISION_2           0b100
#define APB1_SYSCLK_DIVISION_4           0b101
#define APB1_SYSCLK_DIVISION_8           0b110
#define APB1_SYSCLK_DIVISION_16          0b111


/* APB2 BUS CLOCK PRESCALLER INTERFACE OPTIONs */
#define APB2_SYSCLK                      0b000
#define APB2_SYSCLK_DIVISION_2           0b100
#define APB2_SYSCLK_DIVISION_4           0b101
#define APB2_SYSCLK_DIVISION_8           0b110
#define APB2_SYSCLK_DIVISION_16          0b111


/* MCO1 OUTPUT CLOCK INTERFACE OPTIONs */
#define MCO1_CLOCK_HSI                   0b00
#define MCO1_CLOCK_LSE                   0b01
#define MCO1_CLOCK_HSE                   0b10
#define MCO1_CLOCK_PLL                   0b11

/* MCO1 PRESCALLER INTERFACE OPTIONs */
#define MCO1_NO_DIVISON                  0b000
#define MCO1_DIVISON_FACTOR_2            0b100
#define MCO1_DIVISON_FACTOR_3            0b101
#define MCO1_DIVISON_FACTOR_4            0b110
#define MCO1_DIVISON_FACTOR_5            0b111


/* MCO2 OUTPUT CLOCK INTERFACE OPTIONs */
#define MCO2_CLOCK_SYSCLOCK              0b00
#define MCO2_CLOCK_PLLI2S                0b01
#define MCO2_CLOCK_HSE                   0b10
#define MCO2_CLOCK_PLL                   0b11

/* MCO2 PRESCALLER INTERFACE OPTIONs */
#define MCO2_NO_DIVISON                  0b000
#define MCO2_DIVISON_FACTOR_2            0b100
#define MCO2_DIVISON_FACTOR_3            0b101
#define MCO2_DIVISON_FACTOR_4            0b110
#define MCO2_DIVISON_FACTOR_5            0b111



void RCC_voidInitSystemClock(void);

VALIDATION RCC_enumEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);
VALIDATION RCC_enumDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

VALIDATION RCC_enumEnableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);
VALIDATION RCC_enumDisableLowPowerPeripheralClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

VALIDATION RCC_enumResetPeripheral(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

#endif /* RCC_INTERFACE_H_ */