/**
  * @file  bsp.h
  * @brief 外部中断上层驱动
  * @par   date        version    author    remarks
  *        2016-08-12  v1.0       zbt       初次创建
  *
  */

#ifndef __EXTI_DUP_H
#define __EXTI_DUP_H

/** 头文件包含区 ------------------------------------------------ */
#include "stm32f4xx_hal.h"

/** 公有宏(类型定义) -------------------------------------------- */

/** 枚举、结构体 ------------------------------------------------ */
enum EXTI_N
{
    EXTI_0, EXTI_13,
};

/** 公有函数原型 ------------------------------------------------ */
void set_exti_flag(enum EXTI_N exti_n);
uint8_t read_exti_flag(enum EXTI_N exti_n);


#endif
