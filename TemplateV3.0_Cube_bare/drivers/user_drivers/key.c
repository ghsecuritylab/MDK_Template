/**
  * @file  key.c
  * @brief 按键驱动程序
  * @par   date        version    author    remarks
  *        2016-03-19  v1.0       zbt       初次创建
  *
  */

/** 头文件包含区 ------------------------------------------------ */
#include "bsp.h"

/** 私有宏(类型定义) -------------------------------------------- */ 
#define NUM_KEYS    (sizeof(key_gpio_config) / sizeof(key_gpio_config[0]))
    
/** 私有变量 --------------------------------------------------- */ 
/** 配置key用到的端口、引脚   
    推荐使用 user_driver_def中的struct gpio 
    GPIO_InitTypeDef部分值缺省
*/
const gpio_init_t key_gpio_config[] = 
{
    {GPIOA, {GPIO_PIN_0, }},
    {GPIOC, {GPIO_PIN_13, }},
};
  
/** 外部变量 --------------------------------------------------- */

/** 私有函数原型 ----------------------------------------------- */
static key_name_t key_press_down(void);

/** 公有函数 --------------------------------------------------- */

/**
  * @brief  读取按键值    
  * @param  None
  * @retval enum KEY
  */
key_name_t key_read(void)
{
    key_name_t key_name = NO_KEY;
    
    key_name = key_press_down();
    
    if (key_name != NO_KEY)
    {
        HAL_Delay(20);
        while (key_press_down() != NO_KEY)
        {
            HAL_Delay(50);
        }
    }
    
    return key_name;
}

/** 私有函数 --------------------------------------------------- */

/**
  * @brief  按键按下检测    
  * @param  None
  * @retval enum KEY
  */
static key_name_t key_press_down(void)
{
    uint8_t i;
    key_name_t key_name = NO_KEY;
    
    for (i = 0; i < NUM_KEYS; i++)
    {
        if (!HAL_GPIO_ReadPin(key_gpio_config[i].Port, key_gpio_config[i].Init.Pin))
        {
            key_name = (key_name_t)i;
            break;
        }
    }
    
    return key_name;
}
