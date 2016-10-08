/**
  * @file  led.c
  * @brief led驱动程序
  * @par   date        version    author    remarks
  *        2016-09-22  v1.0       zbt       初次创建
  *
  */
  
/** 头文件包含区 --------------------------------------------------- */
#include "common.h"

/** 私有宏(类型定义) ----------------------------------------------- */ 
#define NUM_LEDS    (sizeof(led_pin) / sizeof(led_pin[0]))

/** 私有变量 ------------------------------------------------------- */
const struct GPIO_PIN_LED led_pin[] = 
{
    GPIOD, GPIO_Pin_2,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_3,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_4,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,
    GPIOD, GPIO_Pin_7,  GPIO_Speed_50MHz, GPIO_Mode_Out_PP,

};

/** 外部变量 ------------------------------------------------------- */

/** 私有函数原型 --------------------------------------------------- */

/** 公有函数 ------------------------------------------------------- */
    
/**
  * @brief ledc初始化函数
  * @param None
  * @return None
  */
void led_init(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        GPIO_InitStructure.GPIO_Pin   = led_pin[i].pin;
        GPIO_InitStructure.GPIO_Speed = led_pin[i].speed;
        GPIO_InitStructure.GPIO_Mode  = led_pin[i].mode;
        GPIO_Init(led_pin[i].port, &GPIO_InitStructure);
    }
    
    /**< 设定LED的初始状态 */
    for (i = 0; i < NUM_LEDS; i++)
    {    /**< 关闭开发板上所有的(8个)led */
         GPIO_ResetBits(led_pin[i].port, led_pin[i].pin);         
    }
   
}

/**
  * @brief  点亮led   可配置若干led
  * @param  [in]led_id  e.g LED_0 
  * @return None
  */
void led_on(uint16_t led_id)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            /**< 视led具体送0还是送1点亮选择 */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_SET);
        }

    }
}

/**
  * @brief  熄灭led   可配置若干led
  * @param  [in]led_id  e.g LED_0 
  * @return None
  */
void led_off(uint16_t led_id)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            /**< 视led具体送0还是送1点亮选择 */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
        }

    }
}

/**
  *  @brief  翻转led状态   可配置若干led
  *  @param  [in]led_id  e.g LED_0 
  *  @return None
  */
void led_toggle(uint16_t led_id)
{
    uint8_t i;
    uint8_t pin_status = 0x00;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_id & (1 << i))
        {
            pin_status = GPIO_ReadInputDataBit(led_pin[i].port, led_pin[i].pin);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, ((BitAction)!pin_status));
        }

    }
}

/** 私有函数 ------------------------------------------------------- */
