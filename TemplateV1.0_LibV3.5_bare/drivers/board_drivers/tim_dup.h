/**
  * @file    tim_dup.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-31
  * @brief   通用定时器配置函数
  *
  */  

#ifndef __EXTI_DUP_H
#define __EXTI_DUP_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_tim.h"
/* Public define --------------------------------------------------------------------*/


struct BASE_TIMER_X
{
    TIM_TypeDef         *TIMx;
    uint16_t            prescaler;
    uint16_t            period;
    uint16_t            clk_div;
    uint16_t            cnt_mode;
    uint16_t            tim_it;
//    uint8_t             repetition_cnt;
    FunctionalState     cmd;
};

enum BASE_TIM_N
{
    TIMER_2, TIMER_3, TIMER_4, 
};

/* Public function prototypes ------------------------------------------------*/
void BASE_TIM_config(void);
void set_timer_flag(enum BASE_TIM_N timer_n);
uint8_t read_timer_flag(enum BASE_TIM_N timer_n);


#endif
