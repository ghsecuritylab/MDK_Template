/**
  * @file  led_app.h
  * @brief RT-Thread点亮led程序
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */

#ifndef __LED_APP_H
#define __LED_APP_H

/** 头文件包含区 ------------------------------------------------ */
#include "stm32f10x.h"

/** 公有宏(类型定义) -------------------------------------------- */

/** 枚举、结构体 ------------------------------------------------ */

/** 公有函数原型 ------------------------------------------------ */
void led0_thread_entry(void *parameter);
void led1_thread_entry(void *parameter);

#endif
