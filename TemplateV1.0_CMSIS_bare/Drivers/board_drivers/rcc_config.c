/**
  * @file    rcc_config.c 
  * @author  Z B T
  * @version V0.1   Lib STM32 V3.5
  * @date    2016-03-01
  * @brief   RCC配置函数 时钟使能
  */  

/* Includes ------------------------------------------------------------------*/
#include "rcc_config.h"


/**
  *  @brief  RCC配置函数 此处配置了按键和led使用的端口时钟
  *  @param  None
  *  @retval None
  */
void RCC_Configuration(void)
{
      /** GPIOA Periph时钟使能 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
     /** GPIOB Periph时钟使能 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
}
