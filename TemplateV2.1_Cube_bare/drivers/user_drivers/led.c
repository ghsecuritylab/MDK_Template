/**
  * @file  led.c
  * @brief led驱动程序
  * @par   date        version    author    remarks
  *        2016-03-21  v1.0       zbt       初次创建
  *
  */ 

/** 头文件包含区 ------------------------------------------------ */
#include "bsp.h"

/** 私有宏(类型定义) -------------------------------------------- */ 
#define NUM_LEDS (sizeof(Led) / sizeof(Led[0]))
    
/** 私有变量 --------------------------------------------------- */
/** 配置led用到的端口、引脚 */
const GPIO_Led Led[] =
{
    {GPIOD, {GPIO_PIN_2, GPIO_MODE_OUTPUT_PP, .Speed = GPIO_SPEED_FREQ_LOW}},
    {GPIOD, {GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, .Speed = GPIO_SPEED_FREQ_LOW}},
    {GPIOD, {GPIO_PIN_4, GPIO_MODE_OUTPUT_PP, .Speed = GPIO_SPEED_FREQ_LOW}},
    {GPIOD, {GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, .Speed = GPIO_SPEED_FREQ_LOW}},
};

/** 外部变量 --------------------------------------------------- */

/** 私有函数原型 ----------------------------------------------- */

/** 公有函数 --------------------------------------------------- */

/**
  * @brief  点亮led驱动程序 可同时点亮多个 
  * @param  val 多个LED组合
  * @retval None
  * @note   例如： led_on(LED_0 | LED_1)
  */
void led_on(uint16_t val) 
{
    uint8_t n;
    
    for(n = 0; n < NUM_LEDS; n++)
    {
        if (val & (1 << n)) 
        {
            HAL_GPIO_WritePin(Led[n].Port, Led[n].Init.Pin, GPIO_PIN_SET);        
        }        
    }    
}

/**
  * @brief  熄灭led驱动程序 可同时熄灭多个 
  * @param  val 多个LED组合
  * @retval None
  * @note   例如： led_on(LED_0 | LED_1)
  */
void led_off(uint16_t val) 
{
    uint8_t n;
    
    for(n = 0; n < NUM_LEDS; n++)
    {
        if (val & (1 << n)) 
        {
            HAL_GPIO_WritePin(Led[n].Port, Led[n].Init.Pin, GPIO_PIN_RESET);        
        }        
    }     
}


/** 私有函数 --------------------------------------------------- */
