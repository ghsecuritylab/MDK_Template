/**
  * @file  key.h
  * @brief 按键驱动程序
  * @par   date        version    author    remarks
  *        2016-03-19  v1.0       zbt       初次创建
  *
  */
 
#ifndef	__KEY_H
#define	__KEY_H 

/** 头文件包含区 ------------------------------------------------ */
#include "user_driver_def.h"

/** 公有宏(类型定义) -------------------------------------------- */

/** 枚举、结构体 ------------------------------------------------ */ 
typedef enum key_name
{
    LEFT_SHIFT, RIGHT_SHIFT, NO_KEY = 0xff,
}key_name_t; 


/** 公有函数原型 ------------------------------------------------ */
key_name_t key_read(void);


#endif 
