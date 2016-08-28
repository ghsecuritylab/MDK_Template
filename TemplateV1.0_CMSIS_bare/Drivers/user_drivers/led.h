/**
  * @file    led.h 
  * @author  Z B T
  * @version V0.1
  * @date    2016-01-29
  * @brief   
  *
  */  

#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Public define ------------------------------------------------------------*/
/** 定义GPIOB驱动led用到的引脚 */
#define GPIO_PIN_LED        (GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11\
| GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15)

#define GPIO_LED            GPIOB               /**< 定义LED所使用的GPIO端口 */

#define GPIO_LED_0          GPIO_Pin_15
#define GPIO_LED_1          GPIO_Pin_14
#define GPIO_LED_2          GPIO_Pin_13
#define GPIO_LED_3          GPIO_Pin_12
#define GPIO_LED_4          GPIO_Pin_11
#define GPIO_LED_5          GPIO_Pin_10
#define GPIO_LED_6          GPIO_Pin_9
#define GPIO_LED_7          GPIO_Pin_8
#define GPIO_LED_All        GPIO_PIN_LED

/* Public function prototypes ------------------------------------------------*/
void LED_Init(void);
void LED_On(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x);
void LED_Off(GPIO_TypeDef* GPIOx, uint16_t GPIO_LED_x);


#endif
