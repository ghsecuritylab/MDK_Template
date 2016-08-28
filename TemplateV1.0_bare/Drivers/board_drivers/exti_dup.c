/**
  * @file    exti_dup.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_exti.h"
#include "exti_dup.h"
#include "delay.h"
#include "led.h"

/* Private define ------------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/



/**
  *  @brief  初始化外部中断
  *  @param  None
  *  @retval None
  */
void EXTIx_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;
 	EXTI_InitTypeDef    EXTI_InitStructure;
 	NVIC_InitTypeDef    NVIC_InitStructure;
    
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);                   /**< 关闭JTAG */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB
                                                | RCC_APB2Periph_AFIO, ENABLE); /**< 复用引脚要开启AFIO时钟 */
    /** 配置GPIOB 的6和8号引脚为中断源 */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    /**< 中断线和中断初始化配置 */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);             /**< EXTI线6连到PB6 */
    EXTI_InitStructure.EXTI_Line    = EXTI_Line6;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);                             

    EXTI_GenerateSWInterrupt(EXTI_Line6);                                   /**< EXTI_Line6 中断允许 */
    
    /**< 先占优先级1位 从占优先级3位 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                         
    NVIC_InitStructure.NVIC_IRQChannel                   = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;               /**< 设置NVIC_IRQChannel的先占优先级 */   
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;               /**< 设置NVIC_IRQChannel的从占优先级 */
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
}

/**
  *  @brief  外部中断9-5中断处理程序
  *  @param	 None
  *  @retval None
  */
void EXTI9_5_IRQHandler(void)
{
    delay_n_ms(20);
    
    if (EXTI_GetITStatus(EXTI_Line6))
    {
        LED_On(GPIO_LED, GPIO_LED_0);
        delay_n_ms(1000);
        LED_Off(GPIO_LED, GPIO_LED_All);
        delay_n_ms(1000);
        LED_On(GPIO_LED, GPIO_LED_0);
        delay_n_ms(1000);
        LED_Off(GPIO_LED, GPIO_LED_All);
    }
    
    EXTI_ClearITPendingBit(EXTI_Line6);             /**< 清楚线路6中断挂起位 */
}
