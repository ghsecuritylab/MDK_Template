/**
  * @file    delay.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   ��ʱ����
  */  

/* Includes ------------------------------------------------------------------*/
#include "delay.h"


/**
  *  @brief  ������ʱn us
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
  * @brief  ������ʱn ms
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

