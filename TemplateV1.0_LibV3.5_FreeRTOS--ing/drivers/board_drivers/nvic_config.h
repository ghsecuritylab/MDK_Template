/**
  * @file    nvic_config.h 
  * @author  Z B T
  * @version V0.1   Lib STM32 V3.5
  * @date    2016 - 03
  * @brief   嵌套向量中断配置
  *
  */  

#ifndef __NVIC_CONFIG_H
#define __NVIC_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/** 使用不同的cpu时 注意结构体成员的取值范围 e.g channel */
struct NVIC_EXTI 
{
    uint8_t         channel;                /**< EXTI0_IRQn -- EXTI4_IRQn EXTI9_5_IRQn EXTI15_10_IRQn */
    uint8_t         preemption_priority;
    uint8_t         sub_priority;
    FunctionalState cmd;                    /**< ENABLE or DISABLE */
};

struct NVIC_BASE_TIM
{   
    uint8_t         channel;                /**< TIM2_IRQn -- TIM4_IRQn */
    uint8_t         preemption_priority;
    uint8_t         sub_priority;
    FunctionalState cmd;                    /**< ENABLE or DISABLE */
};

/*    Private variables ---------------------------------------------------------*/
void NVIC_EXTI_Configuration(void);
void NVIC_BASE_TIM_Configuration(void);

#endif
