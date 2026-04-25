/****************************************************************************************************************************** 
*                                        Author: Abdelrahman Gamal OKASHA                                                     *
*			                             Created: 23/4/2026                                                                   *
*			                             File: GPIO_Program.c                                                                 *
*			                             [ GPIO Module Driver ]                                                               *
******************************************************************************************************************************/


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/* GPIO PORTS INTERFACE OPTIONS */
typedef enum GPIO_PORTx
{
    PORTA = 0,
    PORTB ,
    PORTC ,
    PORTD ,
    PORTE ,
    PORTH
}PortID_t;

/* GPIO PINS INTERACE OPTIONS */
typedef enum GPIO_PINx
{
    PIN0 = 0,
    PIN1 ,
    PIN2 ,
    PIN3 ,
    PIN4 ,
    PIN5 ,
    PIN6 ,
    PIN7 ,
    PIN8 ,
    PIN9 ,
    PIN10 ,
    PIN11 ,
    PIN12 ,
    PIN13 ,
    PIN14 ,
    PIN15 ,
}PinID_t;

/* GPIO MODE INTERFACE OPTIONS */
typedef enum GPIO_MODE
{
    INPUT  = 0b00,
    OUTPUT = 0b01,
    AF     = 0b10,
    ANALOG = 0b11
}PinMode_t;

/* GPIO OUTPUT MODES INTERFACE OPTIONs */
typedef enum GPIO_OUTPUTMODE
{
    PUSHPULL = 0,
    OPENDRAIN ,
}OutputMode_t;

/* GPIO OUTPUT SPEEDS INTERFACE OPTIONS */
typedef enum GPIO_OUTPUTSPEED
{
    LOWSPEED      = 0b00,
    MEDIUMSPEED   = 0b01,
    HIGHSPEED     = 0b10,
    VERYHIGHSPEED = 0b11,
}OutputSpeed_t;

/* GPIO PULL MODE INTERFACE OPTIONS */
typedef enum GPIO_PULLMODE
{
    FLOATING = 0b00,
    PULLUP   = 0b01,
    PULLDOWN = 0b10
}PullMode_t;

/* GPIO STATES INTERFACE OPTIONS */
typedef enum GPIO_STATE
{
    LOW = 0,
    HIGH  
}PinState_t;

/* GPIO ALTERNATE FUNNCTIONS INTERFACE OPTIONS */
typedef enum GPIO_AF
{
    AF0 = 0,
    AF1 ,
    AF2 ,
    AF3 ,
    AF4 ,
    AF5 ,
    AF6 ,
    AF7 ,
    AF8 ,
    AF9 ,
    AF10 ,
    AF11 ,
    AF12 ,
    AF13 ,
    AF14 ,
    AF15 
}AF_t;

/* GPIO PORT SIZE INTERFACE OPTIONS */
typedef enum GPIO_PORTSIZE
{
    PORTSIZE_2 = 2 ,
    PORTSIZE_3 ,
    PORTSIZE_4 ,
    PORTSIZE_5 ,
    PORTSIZE_6 ,
    PORTSIZE_7 ,
    PORTSIZE_8 ,
    PORTSIZE_9 ,
    PORTSIZE_10 ,
    PORTSIZE_11 ,
    PORTSIZE_12 ,
    PORTSIZE_13 ,
    PORTSIZE_14 ,
    PORTSIZE_15 ,
    PORTSIZE_16
}PortSize_t;

/* GPIO PIN CONFIGURATION OBJECT */
typedef struct GPIO_PIN
{
    PortID_t PortID:4;
    PinID_t PinID:4;
    PinMode_t Mode:2;
    PullMode_t PullMode:2;
    OutputMode_t OutputMode:2;
    OutputSpeed_t OutputSpeed:2;
    AF_t AFID;
}GPIO_PinConfig;

VALIDATION GPIO_enumPinInit (const GPIO_PinConfig *PinConfig);
VALIDATION GPIO_enumSetPinState (const GPIO_PinConfig *PinConfig,PinState_t Copy_enumPinState);
VALIDATION GPIO_enumTogglePinState (const GPIO_PinConfig *PinConfig);
VALIDATION GPIO_enumScanPinState (const GPIO_PinConfig *PinConfig,PinState_t *PinState);


/* GPIO PORT CONFIGURATION OBJECT */
typedef struct GPIO_PORT
{
    PortID_t PortID:4;
    PinID_t PortInitPinID:4;
    PortSize_t PortSize;
    PinMode_t Mode:2;
    PullMode_t PullMode:2;
    OutputMode_t OutputMode:2;
    OutputSpeed_t OutputSpeed:2;
}GPIO_PortConfig;

VALIDATION GPIO_enumPortInit (const GPIO_PortConfig *PortConfig);
VALIDATION GPIO_enumSetPortState (const GPIO_PortConfig *PortConfig,u16 Copy_u16PortState);
VALIDATION GPIO_enumTogglePortState (const GPIO_PortConfig *PortConfig);
VALIDATION GPIO_enumScanPortState (const GPIO_PortConfig *PortConfig,u16 *PortState);




#endif /* GPIO_INTERFACE_H_ */