/**
  * @file  user_driver_def.h
  * @brief 存放用户驱动公用定义、枚举、宏和结构体定义
  * @par   date        version    author    remarks
  *        2017-02-24  v1.0       zbt       初次创建
  *
  */

#ifndef __USER_DRIVER_DEF_H
#define __USER_DRIVER_DEF_H

/** 头文件包含区 ------------------------------------------------ */
#include "stm32f1xx_hal.h"

#include <stdio.h>
#include <string.h>
#include <math.h>


/** 公有宏(类型定义) -------------------------------------------- */

/** 使用结构体的指定初始化功能需使用C99标准 
    方法： options for target C/C++选 C99mode
    否则会产生错误
*/
typedef struct gpio
{
    GPIO_TypeDef      *Port;
    GPIO_InitTypeDef  Init;
}gpio_init_t;


/** 枚举、结构体 ------------------------------------------------ */

/** 公有函数原型 ------------------------------------------------ */


#endif
