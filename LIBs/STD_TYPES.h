/******************************************************************************************************************************* 
*                                           Author:  Abdelrahman Gamal Abdelwanies Mohamed                                     *
*											Created: 16/10/2023                                                                *
*											File: STD_TYPES.h                                                                  *
*******************************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef signed char s8; 			/*  1byte=8bi   */
typedef unsigned char u8;   		/*  1byte=8bit  */

typedef signed short int s16;		/* 2bytes=16bit */
typedef unsigned short int u16;		/* 2bytes=16bit */

typedef signed long int s32; 		/* 4bytes=32bit */
typedef unsigned long int u32;		/* 4bytes=32bit */

typedef signed long long int s64;	/* 8bytes=64bit */
typedef unsigned long long int u64; /* 8bytes=64bit */

typedef float f32;					/* 4bytes=32bit */
typedef double f64;					/* 8bytes=64bit */

typedef long double f128;			/* 16bytes=128bit */

#define NULL      '\0'
#define TIME_OUT         20000

#define STD_OFF  0
#define STD_ON   1 

#define CLEAR    0
#define SET      1

typedef enum
{
    /* SPECIFIED VALIDATION CODES */
    INVALID=0,
    VALID=1,
    SESSION_TIMEOUT=2,
    IDLE_STATE=3,
    BUSY_STATE=4,
    NULL_POINTER=5,

    /* GPIO SPECIFIED VALIDATION CODES */
    GPIO_INVALID_PIN_MODE=11,
    GPIO_INVALID_PIN_Value=12,
    GPIO_INVALID_PORT_MODE=13,
    GPIO_INVALID_PORT_Value=14,
    GPIO_INVALID_PinID=15,
    GPIO_INVALID_PortID=16,

}VALIDATION;


#define U64_BYTE_SIZE      8

/* u64 Type Based on u8 Type */
typedef struct
{
    u8 BYTE0;
    u8 BYTE1;
    u8 BYTE2;
    u8 BYTE3;
    u8 BYTE4;
    u8 BYTE5;
    u8 BYTE6;
    u8 BYTE7;
}U64NUM_T;




#endif /* STD_TYPES_H_ */