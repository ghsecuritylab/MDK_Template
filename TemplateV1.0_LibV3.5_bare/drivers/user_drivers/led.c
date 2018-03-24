/**
  * @file    led.c 
  * @author  Z B T
  * @version V0.1    Lib STM32_V3.5
  * @date    2016-01-29
  * @brief   led驱动程序
  *
  */  

#include "led.h"

const struct GPIO_PIN_LED led_pin[] = 
{
    GPIOA, GPIO_Pin_0, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_1, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_2, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_3, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_4, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_5, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_6, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
    GPIOA, GPIO_Pin_7, GPIO_Speed_2MHz, GPIO_Mode_Out_PP,
};

#define NUM_LEDS    (sizeof(led_pin) / sizeof(led_pin[0]))
    
/**
 *  @brief ledc初始化函数
 *  @param None
 *  @return None
 */
void GPIO_led_config(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef    GPIO_InitStructure;
    
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
 *  @brief  点亮led   可配置若干led
 *  @param  [in]led_num  e.g LED_0 
 *  @return None
 */
void led_on(uint16_t led_num)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_num & (1 << i))
        {
            /**< 视led具体送0还是送1点亮选择 */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_SET);
        }

    }
}

/**
 *  @brief  熄灭led   可配置若干led
 *  @param  [in]led_num  e.g LED_0 
 *  @return None
 */
void led_off(uint16_t led_num)
{
    uint8_t i;
    
    for (i = 0; i < NUM_LEDS; i++)
    {
        if (led_num & (1 << i))
        {
            /**< 视led具体送0还是送1点亮选择 */
//            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
            GPIO_WriteBit(led_pin[i].port, led_pin[i].pin, Bit_RESET);
        }

    }
}

