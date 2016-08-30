/**
  *
  * @file    key.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   独立按键驱动程序
  *
  */  

/* Includes ------------------------------------------------------------------*/
#include "key.h"
#include "led.h"
#include "delay.h"

#define NUM_KEYS    (sizeof(key) / sizeof(key[0]))
    
/** 配置key用到的端口、引脚 */
struct GPIO_KEY key[] = 
{
    GPIOB, GPIO_Pin_8,  GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_9,  GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_10, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_11, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_12, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_13, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_14, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
    GPIOB, GPIO_Pin_15, GPIO_Speed_10MHz, GPIO_Mode_IN_FLOATING,
};

/**
 *  @brief  独立按键初始化函数
 *  @param  None
 *  @return None
 */
void GPIO_key_config(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef    GPIO_InitStructure;
    
    for (i = 0; i < NUM_KEYS; i++)
    {
        GPIO_InitStructure.GPIO_Pin   = key[i].pin;
        GPIO_InitStructure.GPIO_Speed = key[i].speed;
        GPIO_InitStructure.GPIO_Mode  = key[i].mode;            
        GPIO_Init(key[i].port, &GPIO_InitStructure);           
    }  
}

/**
 *  @brief  读取按键值
 *  @param  None
 *  @retval enum KEY
 */
enum KEY_N key_read(void)
{
    uint8_t i = 0;
    enum KEY_N key_name = NO_KEY;
    
    for (i = 0; i < NUM_KEYS; i++)
    {
        delay_n_ms(10);
        if (GPIO_ReadInputDataBit(key[i].port, key[i].pin) == RESET)
        {
            key_name = (enum KEY_N)i;
            break;
        }
    }
    while ((i < 10 ) && (GPIO_ReadInputDataBit(key[i].port, key[i].pin) != NO_KEY))
    {       /** 检测按键是否被释放 超时退出 */
        i++;
        delay_n_ms(2);
    }
    
    return key_name;
}




