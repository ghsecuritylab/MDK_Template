/**
  * @file    led.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   
  */  

/* Includes ------------------------------------------------------------------*/
#include "led.h"

/* Private function prototypes ------------------------------------------------*/


/**
  *  @brief  led初始化函数
  *  @param  None
  *  @retval None
  */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_LED_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    /** GPIOB Periph时钟使能 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Init(GPIO_LED, &GPIO_InitStructure);                 /**< 初始化配置连接led的端口 */
    
    GPIO_ResetBits(GPIO_LED, GPIO_Pin_All);                      /**< 关闭开发板上所有的(8个)led */
}

/**
  *  @brief  点亮led
  *  @param  None
  *  @retval None
  */
void LED_On(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x)
{
    GPIO_SetBits(GPIOx, GPIO_LED_x); 
}

/**
  *  @brief  熄灭led
  *  @param  None
  *  @retval None
  */
void LED_Off(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x)
{
    GPIO_ResetBits(GPIOx, GPIO_LED_x);
}

