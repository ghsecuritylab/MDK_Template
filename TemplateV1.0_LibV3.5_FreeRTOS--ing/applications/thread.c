/**
  * @file    thread.c 
  * @author  Z B T
  * @version V0.1	
  * @date    2016-08-12
  * @brief   创建用户线程
  *
  */  

/* Includes ------------------------------------------------------------------*/
#include "thread.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "delay.h"

/* Private define ------------------------------------------------------------*/
#define STACK_SIZE      512     /* 单位：word 总共4字节 */
#define TASK_PRIORITY   1

/* Private variables ---------------------------------------------------------*/

/* External variables --------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void vTaskLed(void *Parameters);

/* Public function -----------------------------------------------------------*/
/**
  * @brief  创建用户线程
  * @param	None
  * @retval None
  */
void user_task_create(void)
{
    xTaskCreate(vTaskLed, "LedTask", STACK_SIZE, NULL, TASK_PRIORITY, NULL);
}

static void vTaskLed(void *Parameters)
{
    while (1)
    {
        led_on(LED_0);
        delay_n_ms(200);
        led_off(LED_0);
        delay_n_ms(200);
    }
}
/* Private function ----------------------------------------------------------*/
