/**
  * @file    led.h 
  * @author  Z B T
  * @version V0.1   Lib STM32_V3.5
  * @date    2016-01-29
  * @brief   ledÇý¶¯³ÌÐò
  *
  */  

#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

/**< ledÐòÁÐ */
#define LED_0   0x01
#define LED_1   0x02
#define LED_2   0x04
#define LED_3   0x08
#define LED_4   0x10
#define LED_5   0x20
#define LED_6   0x40
#define LED_7   0x80
#define LED_ALL 0xff

struct GPIO_PIN_LED
{
    GPIO_TypeDef        *port;
    uint16_t            pin;
    GPIOSpeed_TypeDef   speed;
    GPIOMode_TypeDef    mode;
};


void GPIO_led_config(void);
void led_on(uint16_t led_num);
void led_off(uint16_t led_num);


#endif
