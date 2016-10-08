/**
  * @file    nvic_config.c 
  * @author  Z B T
  * @version V0.1   Lib STM32 V3.5
  * @date    2016 - 03
  * @brief   嵌套向量中断配置
  *
  */  

/* Includes ------------------------------------------------------------------*/
#include "nvic_config.h"


#define NUM_NVIC_EXTI       (sizeof(nvic_exti) / sizeof(nvic_exti[0]))
#define NUM_NVIC_BASE_TIM   (sizeof(nvic_base_tim) / sizeof(nvic_base_tim[0]))

const struct NVIC_EXTI nvic_exti[] = 
{   /**< 中断通道 抢占式优先级  响应式优先级 通道使能 */
    EXTI9_5_IRQn, 0, 1, ENABLE,
};
const struct NVIC_BASE_TIM nvic_base_tim[] = 
{   /**< 中断通道 抢占式优先级  响应式优先级 通道使能 */
    TIM2_IRQn, 0, 0, ENABLE,
    TIM3_IRQn, 0, 0, ENABLE,
//    TIM4_IRQn, 0, 0, ENABLE,
    
};

/**
 *  @brief	配置EXTI的NVIC 
 *  @param	None
 *  @return None
 */
void NVIC_EXTI_Configuration(void)
{
    uint8_t i = 0;
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    for (i = 0; i < NUM_NVIC_EXTI; i++)
    {
        NVIC_InitStructure.NVIC_IRQChannel = nvic_exti[i].channel;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = nvic_exti[i].preemption_priority;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = nvic_exti[i].sub_priority;
        NVIC_InitStructure.NVIC_IRQChannelCmd = nvic_exti[i].cmd;
        NVIC_Init(&NVIC_InitStructure);
    }
}

/**
 *  @brief	配基本定时器的NVIC 
 *  @param	None
 *  @return None
 */
void NVIC_BASE_TIM_Configuration(void)
{
    uint8_t i = 0;
    NVIC_InitTypeDef    NVIC_InitStructure;
    
    for (i = 0; i < NUM_NVIC_EXTI; i++)
    {
        NVIC_InitStructure.NVIC_IRQChannel = nvic_base_tim[i].channel;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = nvic_base_tim[i].preemption_priority;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = nvic_base_tim[i].sub_priority;
        NVIC_InitStructure.NVIC_IRQChannelCmd = nvic_base_tim[i].cmd;
        NVIC_Init(&NVIC_InitStructure);
    }
}

