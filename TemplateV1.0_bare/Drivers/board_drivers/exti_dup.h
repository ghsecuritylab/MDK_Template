/**
  *
  * @file    exti_dup.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   外部中断配置函数
  *
  */  

#ifndef __EXTI_DUP_H
#define __EXTI_DUP_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
/* Public define --------------------------------------------------------------------*/

struct GPIO_EXTI
{
    GPIO_TypeDef        *port;
    uint16_t            pin;
    GPIOSpeed_TypeDef   speed;
    GPIOMode_TypeDef    mode;
};
struct EXTI_X
{
    uint8_t             port_src;
    uint8_t             pin_src;
    uint32_t            line;
    EXTIMode_TypeDef    mode;
    EXTITrigger_TypeDef trigger;
    FunctionalState     cmd;
};

enum EXTI_N
{
    EXTI_8, EXTI_9, 
};

/* Public function prototypes ------------------------------------------------*/
void GPIO_EXTI_config(void);
void set_exti_flag(enum EXTI_N exti_n);
uint8_t read_exti_flag(enum EXTI_N exti_n);


#endif
