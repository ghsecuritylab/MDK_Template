/**
  * @file    key.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   
  */  

#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Public define ------------------------------------------------------------*/
/** 定义独立按键用到的GPIO */
#define GPIO_PIN_KEY        (GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11\
| GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15)

#define GPIO_KEY            GPIOB               /**< 定义独立按键所使用的GPIO端口 */

#define GPIO_KEY_0          GPIO_Pin_15
#define GPIO_KEY_1          GPIO_Pin_14
#define GPIO_KEY_2          GPIO_Pin_13
#define GPIO_KEY_3          GPIO_Pin_12
#define GPIO_KEY_4          GPIO_Pin_11
#define GPIO_KEY_5          GPIO_Pin_10
#define GPIO_KEY_6          GPIO_Pin_9
#define GPIO_KEY_7          GPIO_Pin_8
#define GPIO_KEY_All        GPIO_PIN_KEY

/* Public function prototypes ------------------------------------------------*/
void KEY_Init(void);

#endif
