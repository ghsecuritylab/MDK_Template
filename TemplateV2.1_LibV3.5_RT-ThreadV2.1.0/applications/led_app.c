/**
  * @file  template.c
  * @brief 模板
  * @par   date        version    author    remarks
  *        2016-08-12  v1.0       zbt       初次创建
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
  * @brief  led0线程入口函数
  * @param	None
  * @retval None
  */
void led0_thread_entry(void *parameter)
{
    
    while (1)
    {
        led_on(LED_0);
        rt_thread_delay(50);
        led_off(LED_0);
        rt_thread_delay(50);
    }
}

/**
  * @brief  led1线程入口函数
  * @param	None
  * @retval None
  */
void led1_thread_entry(void *parameter)
{
    
    while (1)
    {
        led_on(LED_1);
        rt_thread_delay(100);
        led_off(LED_1);
        rt_thread_delay(100);
    }
}

/** 私有函数 --------------------------------------------------- */

/**
  * @brief 
  * @param	None
  * @retval None
  */

