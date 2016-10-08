/**
  * @file  common.c
  * @brief 包含一些公用的函数、文件
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */

/** 头文件包含区 ------------------------------------------------ */

#include "common.h"



/** 私有宏(类型定义) -------------------------------------------- */ 

/** 私有变量 --------------------------------------------------- */ 

/** 外部变量 --------------------------------------------------- */

/** 私有函数原型 ----------------------------------------------- */


/** 公有函数 --------------------------------------------------- */

/**
  * @brief  板级支持包初始化
  * @param	None
  * @retval None
  */
void bsp_init(void)
{
    led_init();
    
    
}

/** 私有函数 --------------------------------------------------- */

/**
  * @brief 
  * @param	None
  * @retval None
  */
