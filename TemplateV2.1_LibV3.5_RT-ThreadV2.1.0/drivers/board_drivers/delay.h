/**
  * @file  delay.h
  * @brief 粗略延时驱动程序
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */ 

#ifndef __DELAY_H
#define __DELAY_H

/** 头文件包含区 --------------------------------------------------- */
#include "stm32f10x.h"

/** 公有宏(类型定义) ----------------------------------------------- */

/** 结构、枚举 ----------------------------------------------------- */

/** 文件接口 ------------------------------------------------------- */
void delay_n_us(uint16_t n);
void delay_n_ms(uint16_t n);

#endif
