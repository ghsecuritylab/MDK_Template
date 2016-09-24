/**
  * @file  app_thread.c
  * @brief RT-Thread线程创建及初始化程序
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */

/** 头文件包含区 --------------------------------------------------- */
#include <rtthread.h>
#include "led_app.h"

/** 私有宏(类型定义) ----------------------------------------------- */ 

/** 私有变量 ------------------------------------------------------- */ 
/** 线程控制块 */
/** led0线程 */
static struct rt_thread thread_led0;
ALIGN(4)
static rt_uint8_t s_thread_led0_stack[2048];
#define THREAD_LED0_PRIORITY         5 

/** led1线程 */
static struct rt_thread thread_led1;
ALIGN(4)
static rt_uint8_t s_thread_led1_stack[2048];
#define THREAD_LED1_PRIORITY         5 

/** 外部变量 ------------------------------------------------------- */

/** 私有函数原型 --------------------------------------------------- */

/** 公有函数 ------------------------------------------------------- */

/**
  * @brief  RT-Thread 线程创建及初始化函数
  * @param	None
  * @retval None
  */
void user_thread_init(void)
{
    rt_err_t result;
    
    /** rt_thread_init参数：线程-线程名-线程入口函数-栈起始地址-栈大小
                            线程优先级-同一优先级的时间片
    */
    
    result = rt_thread_init(&thread_led0, "led0", led0_thread_entry, RT_NULL, &s_thread_led0_stack[0], 
                            sizeof(s_thread_led0_stack), THREAD_LED0_PRIORITY, 10);
    if (result == RT_EOK)
    {
        rt_thread_startup(&thread_led0);
        rt_kprintf("Init therad led0 succeed\n");
    }
    else
    {
        rt_kprintf("Init thread led0 failed\n");
    }
    
    result = rt_thread_init(&thread_led1, "led1", led1_thread_entry, RT_NULL, &s_thread_led1_stack[0], 
                            sizeof(s_thread_led1_stack), THREAD_LED1_PRIORITY, 10);
    if (result == RT_EOK)
    {
        rt_thread_startup(&thread_led1);
        rt_kprintf("Init therad led1 succeed\n");
    }
    else
    {
        rt_kprintf("Init thread led1 failed\n");
    }
       
}
    
/** 私有函数 ------------------------------------------------------- */


