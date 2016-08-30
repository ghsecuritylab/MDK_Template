/**
  *
  * @file    key.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   独立按键驱动程序
  *
  */  

#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private define ------------------------------------------------------------*/


enum KEY_N
{
    KEY_1, KEY_2, KEY_3, KEY_4,
    KEY_5, KEY_6, KEY_7, KEY_8,
    NO_KEY = 0xff,
}; 

struct GPIO_KEY
{
    GPIO_TypeDef        *port;
    uint16_t            pin;
    GPIOSpeed_TypeDef   speed;
    GPIOMode_TypeDef    mode;
};

/* Public function prototypes ------------------------------------------------*/
void GPIO_key_config(void);
enum KEY_N key_read(void);

#endif
