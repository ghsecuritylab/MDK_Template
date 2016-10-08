/**
  * @file    main.c 
  * @author  Z B T
  * @version V1.1
  * @date    2016-01-29
  * @brief   Main program body 
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
/* freertos includes */
#include "FreeRTOS.h"
#include "task.h"

/* applications includes */
#include "thread.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes ------------------------------------------------*/


int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured, 
	this is done through SystemInit() function which is called from startup
	file (startup_stm32f10x_xx.s) before to branch to application main.
	To reconfigure the default setting of SystemInit() function, refer to
	system_stm32f10x.c file
	*/ 
    /* Declare variables ------------------------------------------------------*/
    
    
    /*  Function call ---------------------------------------------------------*/
    user_task_create();
    
    vTaskStartScheduler();      /* 启动调度开始执行任务 */
    
    while (1)
    {
        /* 如果系统正常启动是不会运行到这里的，
            运行到这里极有可能是空闲任务heap空间不足造成创建失败 */
    }

}



/* 钩子函数 ------------------------------------------------------------------- */
/**
  * @brief  栈溢出钩子函数
  * @param  pxTask：产生栈溢出的任务句柄
  * @param  *pcTaskName：产生栈溢出的任务名
  * @retval None
  * @note   当一个任务从该任务的栈溢出时，此函数被调用。如果溢出非常
            严重，这两个参数信息也可能是错误的，在这种情况下可以直接
            检查pxCurrentTCB变量
            推荐仅在开发板or测试版使用栈溢出检查，因为这会增大上下文
            开销
  */
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    ( void ) pxTask;
	( void ) pcTaskName;
    
    while (1);
}

/**
  * @brief  周期中断钩子函数，可以实现定时器功能
  * @param  None
  * @retval None
  * @note   使用此函数需要在FreeRTOSConfig.h中将configUSE_TICK_HOOK宏定义改为1
            此函数在中断服务程序中运行，所以此函数必须短小，不可使用大量堆栈，
            不能调用以From_ISR or FROM_ISR结尾的函数
  */
void vApplicationTickHook(void)
{
    
}
