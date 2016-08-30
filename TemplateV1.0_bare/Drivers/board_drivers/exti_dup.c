/**
  * @file    exti_dup.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   外部中断配置函数
  *
  */  

/* Includes ------------------------------------------------------------------*/
#include "exti_dup.h"
#include "delay.h"
#include "led.h"

/* Private define ------------------------------------------------------------*/
#define NUM_EXTI        (sizeof(exti) / sizeof(exti[0]))
#define NUM_EXTI_X      (sizeof(exti_x) / sizeof(exti_x[0]))
    
/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
const struct GPIO_EXTI exti[] = 
{
    GPIOB, GPIO_Pin_8, GPIO_Speed_10MHz, GPIO_Mode_IPU,
    GPIOB, GPIO_Pin_9, GPIO_Speed_10MHz, GPIO_Mode_IPU,
};
const struct EXTI_X exti_x[] = 
{
    GPIO_PortSourceGPIOB, GPIO_PinSource8, EXTI_Line8, EXTI_Mode_Interrupt, EXTI_Trigger_Falling, ENABLE,
    GPIO_PortSourceGPIOB, GPIO_PinSource9, EXTI_Line9, EXTI_Mode_Interrupt, EXTI_Trigger_Falling, ENABLE,
};
   
static uint8_t exti_flag[] = {0, 0,};

/* Public function prototypes -----------------------------------------------*/
/**
 * @brief  配置外部中断的GPIO NVIC EXTI相关参数
 * @param	None
 * @return None
 */
void GPIO_EXTI_config(void)
{
    uint8_t i = 0;
    GPIO_InitTypeDef    GPIO_InitStructure;
 	EXTI_InitTypeDef    EXTI_InitStructure;
    
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);       /**< 关闭JTAG */
    
    /** 配置EXTI的GPIO */
    for (i = 0; i < NUM_EXTI; i++)
    {
        GPIO_InitStructure.GPIO_Pin   = exti[i].pin;
        GPIO_InitStructure.GPIO_Speed = exti[i].speed;
        GPIO_InitStructure.GPIO_Mode  = exti[i].mode;
        GPIO_Init(exti[i].port, &GPIO_InitStructure);
    }
    /**< 中断线和中断初始化配置 */
    for (i = 0; i < NUM_EXTI_X; i++)
    {
        GPIO_EXTILineConfig(exti_x[i].port_src, exti_x[i].pin_src);           
        EXTI_InitStructure.EXTI_Line    = exti_x[i].line;
        EXTI_InitStructure.EXTI_Mode    = exti_x[i].mode;
        EXTI_InitStructure.EXTI_Trigger = exti_x[i].trigger;
        EXTI_InitStructure.EXTI_LineCmd = exti_x[i].cmd;
        EXTI_Init(&EXTI_InitStructure);                             
        EXTI_GenerateSWInterrupt(exti_x[i].line);       /**< 中断允许 */
    }
}

/**
 * @brief  配置外部中断的GPIO NVIC EXTI相关参数
 * @param	None
 * @return None
 */
void set_exti_flag(enum EXTI_N exti_n)
{
    exti_flag[exti_n] = 1;
}

/**
 * @brief  配置外部中断的GPIO NVIC EXTI相关参数
 * @param	None
 * @return None
 */
uint8_t read_exti_flag(enum EXTI_N exti_n)
{
    uint8_t tmp_flag = 0;
    
    tmp_flag = exti_flag[exti_n];
    exti_flag[exti_n] = 0;          /**< 清除中断标志位 */
    
    return tmp_flag;
}

/**
 * @brief   外部中断9-5中断处理程序
 * @param	None
 * @return  None
 * @note    无需调用
*/
void EXTI9_5_IRQHandler(void)
{
    uint8_t i = 0;
    enum EXTI_N exti_n_flag;
    
    for (i = 0; i < NUM_EXTI_X; i++)
    {
        if (EXTI_GetITStatus(exti_x[i].line) != RESET)
        {
            exti_n_flag = (enum EXTI_N) i;
            set_exti_flag(exti_n_flag);
            break;
        }
    }
    
    for (i = 0; i < NUM_EXTI_X; i++)
    {   /** 清除相应中断挂起位 */
        EXTI_ClearITPendingBit(exti_x[exti_n_flag].line);   
    }
    
/**< 写法二 如需采用去掉此部分注释 注释上部分即可 */    
//    if (EXTI_GetITStatus(EXTI_Line8) != RESET)
//    {
//        set_exti_flag(EXTI_8);

//    }
//    if (EXTI_GetITStatus(EXTI_Line9) != RESET)
//    {
//        set_exti_flag(EXTI_9);

//    }
//    EXTI_ClearITPendingBit(EXTI_Line8);     
//    EXTI_ClearITPendingBit(EXTI_Line9);
}

/* Private function prototypes -----------------------------------------------*/
