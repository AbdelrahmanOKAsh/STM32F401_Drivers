/****************************************************************************************************************************
*                                        Author: Abdelrahman Gamal OKASHA                                                   *
*			                             Created: 23/4/2026                                                                 *
*			                             File: GPIO_Program.c                                                               *
*			                             [ GPIO Module Driver ]                                                             *
****************************************************************************************************************************/


#include "../../LIBs/STD_TYPES.h"
#include "../../LIBs/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"


/* GPIOx IS AN ARRAY THAT HOLD POINTERS TO GPIOS PORTS [ GPIOA , GPIOB , GPIOC , GPIOD , GPIOE , GPIOH ] */
static GPIO_REG* GPIOx[] = { GPIOA , GPIOB , GPIOC , GPIOD , GPIOE , GPIOH };

/* PORTSIZEMASK IS AN ARRAY THAT HOLD EACH PORT SIZE MASK TO CORRESPONDING PORT SIZE */
static u16 PortSizeMask[] = { 0b11 , 0b111 , 0b1111 , 0b11111 , 0b111111 , 0b1111111 , 0b11111111 , 0b111111111 , 0b1111111111 , 0b11111111111 , 0b111111111111 , 0b1111111111111 , 0b11111111111111 , 0b111111111111111 , 0b1111111111111111 };





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO CONFIGURE A GPIO PIN                                                                                *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE                                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumPinInit (const GPIO_PinConfig *PinConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        if((PinConfig->PortID <= PORTH) && (PinConfig->PinID <= PIN15) && (PinConfig->Mode <= ANALOG) && (PinConfig->PullMode <= PULLDOWN) && (PinConfig->OutputMode <= OPENDRAIN) && (PinConfig->OutputSpeed <= VERYHIGHSPEED) && (PinConfig->AFID <= AF15))
        {
            /* CONFIGURE PIN MODE */
            GPIOx[PinConfig->PortID]->MODER &= ~(   MODERMASK   << (PinConfig->PinID * MODERSTEP));
            GPIOx[PinConfig->PortID]->MODER |= (PinConfig->Mode << (PinConfig->PinID * MODERSTEP));
            /* CONFIGURE PIN PULL MODE */
            GPIOx[PinConfig->PortID]->PUPDR &= ~(    PUPDRMASK      << (PinConfig->PinID * PUPDRSTEP));
            GPIOx[PinConfig->PortID]->PUPDR |= (PinConfig->PullMode << (PinConfig->PinID * PUPDRSTEP));

            if((PinConfig->Mode == OUTPUT) || (PinConfig->Mode == AF))
            {
                /* CONFIGURE PIN OUTPUT MODE */
                GPIOx[PinConfig->PortID]->OTYPER &= ~(     OTYPERMASK      << PinConfig->PinID);
                GPIOx[PinConfig->PortID]->OTYPER |= (PinConfig->OutputMode << PinConfig->PinID);
                /* CONFIGURE PIN OUTPUT SPEED */
                GPIOx[PinConfig->PortID]->OSPEEDR &= ~(     OSPEEDRMASK      << (PinConfig->PinID * OSPEEDRSTEP));
                GPIOx[PinConfig->PortID]->OSPEEDR |= (PinConfig->OutputSpeed << (PinConfig->PinID * OSPEEDRSTEP));

                /* CONFIGURE PIN ALTERNATIVE FUNCTION */
                if(PinConfig->Mode == AF)
                {
                    if(PinConfig->PinID <= PIN7)
                    {
                        GPIOx[PinConfig->PortID]->AFRL &= ~(   AFRLMASK    << (PinConfig->PinID * AFRLSTEP));
                        GPIOx[PinConfig->PortID]->AFRL |= (PinConfig->AFID << (PinConfig->PinID * AFRLSTEP));
                    }

                    else if (PinConfig->PinID <= PIN15)
                    {
                        GPIOx[PinConfig->PortID]->AFRH &= ~(   AFRHMASK    << (PinConfig->PinID * AFRHSTEP));
                        GPIOx[PinConfig->PortID]->AFRH |= (PinConfig->AFID << (PinConfig->PinID * AFRHSTEP));
                    }
                }
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}






/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SET GPIO PIN STATE                                                                                  *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , PIN STATE                                            *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumSetPinState (const GPIO_PinConfig *PinConfig,PinState_t Copy_enumPinState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        switch(Copy_enumPinState)
        {
            case LOW : GPIOx[PinConfig->PortID]->BSRR = (1 << (PinConfig->PinID + BSRRLOWSTEP)); break;
            case HIGH: GPIOx[PinConfig->PortID]->BSRR = (1 <<  PinConfig->PinID);                break;
            default  : Local_ValidationStatus = INVALID;                                         break;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO TOGGLE A GPIO PIN STATE                                                                             *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE                                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumTogglePinState (const GPIO_PinConfig *PinConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        GPIOx[PinConfig->PortID]->ODR ^= (1 << PinConfig->PinID);
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SCAN A GPIO PIN STATE                                                                               *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , POINTER TO [ PinState_t ] DEFINED TYPE               *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumScanPinState (const GPIO_PinConfig *PinConfig,PinState_t *PinState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PinConfig != NULL)
    {
        switch(PinConfig->Mode)
        {
            case INPUT : *PinState = ((GPIOx[PinConfig->PortID]->IDR >> PinConfig->PinID) & 1); break;
            case OUTPUT: *PinState = ((GPIOx[PinConfig->PortID]->ODR >> PinConfig->PinID) & 1); break;
            default    : Local_ValidationStatus = INVALID;                                      break;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}





/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO CONFIGURE A GPIO PORT                                                                               *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PortConfig ] DEFINED TYPE                                                       *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumPortInit (const GPIO_PortConfig *PortConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        if((PortConfig->PortID <= PORTH) && (PortConfig->PortInitPinID <= PIN15) && (PortConfig->PortSize <= PORTSIZE_16) && (PortConfig->Mode <= ANALOG) && (PortConfig->PullMode <= PULLDOWN) && (PortConfig->OutputMode <= OPENDRAIN) && (PortConfig->OutputSpeed <= VERYHIGHSPEED))
        {
            for(u8 PinIndex = PortConfig->PortInitPinID ; PinIndex <= ((PortConfig->PortInitPinID + PortConfig->PortSize) - 1) ; PinIndex++)
            {
                /* CONFIGURE PIN MODE */
                GPIOx[PortConfig->PortID]->MODER &= ~(    MODERMASK   << (PinIndex * MODERSTEP));
                GPIOx[PortConfig->PortID]->MODER |= (PortConfig->Mode << (PinIndex * MODERSTEP));
                /* CONFIGURE PIN PULL MODE */
                GPIOx[PortConfig->PortID]->PUPDR &= ~(     PUPDRMASK      << (PinIndex * PUPDRSTEP));
                GPIOx[PortConfig->PortID]->PUPDR |= (PortConfig->PullMode << (PinIndex * PUPDRSTEP));

                if(PortConfig->Mode == OUTPUT)
                {
                    /* CONFIGURE PIN OUTPUT MODE */
                    GPIOx[PortConfig->PortID]->OTYPER &= ~(      OTYPERMASK      << PinIndex);
                    GPIOx[PortConfig->PortID]->OTYPER |= (PortConfig->OutputMode << PinIndex);
                    /* CONFIGURE PIN OUTPUT SPEED */
                    GPIOx[PortConfig->PortID]->OSPEEDR &= ~(      OSPEEDRMASK      << (PinIndex * OSPEEDRSTEP));
                    GPIOx[PortConfig->PortID]->OSPEEDR |= (PortConfig->OutputSpeed << (PinIndex * OSPEEDRSTEP));
                }
            }
        }

        else
        {
            Local_ValidationStatus = INVALID;
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}






/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SET GPIO PORT STATE                                                                                 *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , PORT STATE                                           *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumSetPortState (const GPIO_PortConfig *PortConfig,u16 Copy_u16PortState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        GPIOx[PortConfig->PortID]->ODR &= ~(PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
        GPIOx[PortConfig->PortID]->ODR |= (           Copy_u16PortState            << PortConfig->PortInitPinID);
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}






/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO TOGGLE A GPIO PORT STATE                                                                            *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE                                                        *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumTogglePortState (const GPIO_PortConfig *PortConfig)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        GPIOx[PortConfig->PortID]->ODR ^= (PortSizeMask[PortConfig->PortSize - 2] << PortConfig->PortInitPinID);
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}






/******************************************************************************************************************************
* BRIEF: FUNCTION USED TO SCAN A GPIO PORT STATE                                                                              *
* PARAMETARS: A PONTER TO AN OBJECT OF [ GPIO_PinConfig ] DEFINED TYPE , POINTER TO [ PortState_t ] DEFINED TYPE              *
* RETURN: ENUM                                                                                                                *
******************************************************************************************************************************/
VALIDATION GPIO_enumScanPortState (const GPIO_PortConfig *PortConfig,u16 *PortState)
{
    VALIDATION Local_ValidationStatus = VALID;
    if(PortConfig != NULL)
    {
        switch(PortConfig->Mode)
        {
            case INPUT : *PortState = ((GPIOx[PortConfig->PortID]->IDR >> PortConfig->PortInitPinID) & PortSizeMask[PortConfig->PortSize - 2]); break;
            case OUTPUT: *PortState = ((GPIOx[PortConfig->PortID]->ODR >> PortConfig->PortInitPinID) & PortSizeMask[PortConfig->PortSize - 2]); break;
            default    : Local_ValidationStatus = INVALID;                                                                                      break; 
        }
    }

    else
    {
        Local_ValidationStatus = NULL_POINTER;
    }

    return Local_ValidationStatus;
}