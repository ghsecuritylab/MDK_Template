/**
  * @file    delay.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   —” ±∫Ø ˝
  */  

/* Includes ------------------------------------------------------------------*/
#include "delay.h"


/**
  *  @brief  ¥÷¬‘—” ±n us
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
  * @brief  ¥÷¬‘—” ±n ms
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


