/**
  * @file  common.h
  * @brief 包含一些公用的函数、文件
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */

#ifndef __COMMON_H
#define __COMMON_H

/** 头文件包含区 ------------------------------------------------ */
#include "stm32f10x.h"

#include <rtthread.h>

#include "delay.h"
#include "led.h"

#include "led_app.h"

/** 公有宏(类型定义) -------------------------------------------- */

/** 枚举、结构体 ------------------------------------------------ */

/** 公有函数原型 ------------------------------------------------ */
void bsp_init(void);


#endif
