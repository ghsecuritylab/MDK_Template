/**
  * @file    delay.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   延时函数
  */  

/* 头文件包含区 --------------------------------------------------*/
#include "delay.h"

/* 文件私有变量 ------------------------------------------------- */
static __IO uint32_t s_tick;

/* 私有函数原型 ------------------------------------------------- */
static void delay_task(void);

/* 公有函数 ----------------------------------------------------- */
/**
  *  @brief  systick初始化
  *  @param  None
  *  @retval None
  */
void systick_init(void)
{
    /** 设置定时周期
        SystemCoreClock / 1000 表示定时频率 1000hz，可得定时周期1ms
        SystemCoreClock / 100 表示定时频率  100hz，可得定时周期10ms
    */
    SysTick_Config(SystemCoreClock / 1000);
    /** 配置systick中断 */
    
}

/**
  *  @brief  增加tick值
  *  @param  None
  *  @retval None
  */
void inc_tick(void)
{
    s_tick++;
}

/**
  *  @brief  粗略延时n us
  *  @param  None
  *  @retval s_tick的值
  */
uint32_t get_tick(void)
{
    return s_tick;
}


/**
  *  @brief  利用systick产生精确延时
  *  @param  ms：要延时的时间 单位：ms
  *  @retval None
  */
void systick_delay(__IO uint32_t ms)
{
    uint32_t tick_start = 0;
    
    tick_start = get_tick();
    
    while (get_tick() - tick_start < ms)
    {
        delay_task();
    }
}

/**
  *  @brief  粗略延时n us
  *  @param  None
  *  @retval None
  */
void delay_n_us(uint16_t n_us)
{
    uint8_t i = 0;

    while (n_us--)
    {
        i = 10;
        while (i--);
    }
}

/**
  * @brief  粗略延时n ms
  * @param  None
  * @retval None
  */
void delay_n_ms(uint16_t n_ms)
{
    uint16_t i = 0;

    while (n_ms--)
    {
        i = 12000;
        while (i--);
    }
}

/* 私有函数 ----------------------------------------------------- */
/**
  * @brief  在延时中插入任务，避免延时空等
  * @param  None
  * @retval None
  * @note   可插入STemwin显示程序或喂狗等
  */
static void delay_task(void)
{
    
}
