/**
  * @file    delay.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   ÑÓÊ±º¯Êý
  */  

#ifndef __DELAY_H
#define __DELAY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private variables ---------------------------------------------------------*/
void delay_n_us(uint16_t n_us);
void delay_n_ms(uint16_t n_ms);

void inc_tick(void);
uint32_t get_tick(void);
void systick_init(void);
void systick_delay(__IO uint32_t ms);


#endif
