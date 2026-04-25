/****************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                     *
*			                             Created: 23/4/2026                                                                   *
*			                             File: GPIO_Program.c                                                                 *
*			                             [ GPIO Module Driver ]                                                               *
******************************************************************************************************************************/


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/* GPIO REGISTER FILE */
typedef struct GPIO_REGISTERFILE
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
}GPIO_REG;

/* GPIO PORTS BASE ADDRESSES */
#define GPIOA_BASE_ADDRESS   0x40020000
#define GPIOB_BASE_ADDRESS   0x40020400
#define GPIOC_BASE_ADDRESS   0x40020800
#define GPIOD_BASE_ADDRESS   0x40020C00
#define GPIOE_BASE_ADDRESS   0x40021000
#define GPIOH_BASE_ADDRESS   0x40021C00


/* GPIO PORTS MEMORY MAPPED */
#define GPIOA      ((GPIO_REG*) GPIOA_BASE_ADDRESS)
#define GPIOB      ((GPIO_REG*) GPIOB_BASE_ADDRESS)
#define GPIOC      ((GPIO_REG*) GPIOC_BASE_ADDRESS)
#define GPIOD      ((GPIO_REG*) GPIOD_BASE_ADDRESS)
#define GPIOE      ((GPIO_REG*) GPIOE_BASE_ADDRESS)
#define GPIOH      ((GPIO_REG*) GPIOH_BASE_ADDRESS)

/* MODER REGISTER MASK AND STEP */
#define MODERMASK        0b11
#define MODERSTEP        2

/* PUPDR REGISTER MASK */
#define PUPDRMASK        0b11
#define PUPDRSTEP        2

/* OTYPER REGISTER MASK AND STEP */
#define OTYPERMASK      0b1

/* OSPEEDR REGISTER MASK AND STEP */
#define OSPEEDRMASK     0b11
#define OSPEEDRSTEP     2

/* AFRL REGISTER MASK AND STEP */
#define AFRLMASK        0b1111
#define AFRLSTEP        4


/* AFRH REGISTER MASK AND STEP */
#define AFRHMASK        0b1111
#define AFRHSTEP        4

/* BSRR REGISTER STEP */
#define BSRRLOWSTEP      16




#endif /* GPIO_PRIVATE_H_ */