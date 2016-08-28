/**
  * @file    digitron.c 
  * @author  Z B T
  * @version V0.1
  * @date    2016-03-16
  * @brief   共阳极数码管驱动程序 适用于普中开发板
  */  

/* Includes ------------------------------------------------------------------*/
#include "digitron.h"
#include "delay.h"

/* Private define ------------------------------------------------------------*/
/**< 8个数码管接口定义 */
#define GPIO_DIGITRON_DATA      GPIOB
#define GPIO_DIGITRON           GPIOA      

/* External variables --------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
//const uint8_t digitron_map[] = 
//{   /** 共阴极数码管段选 */
//    ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07,
//    ~0x7F, ~0x6F, ~0x77, ~0x7C, ~0x39, ~0x5E, ~0x79, ~0x71,
//};
const uint8_t digitron_map[] = 
{   /** 共阳极数码管段选 */
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
};
/** 数码管位选表 */
const uint8_t digitron_select[] = 
{
    0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f
};

/* Private function prototypes -----------------------------------------------*/


/**
  *  @brief  数码管引脚配置函数
  *  @param	 None
  *  @retval None
  */
void digitron_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_All;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    
    /** GPIOB Periph时钟使能 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init(GPIOA, &GPIO_InitStructure);                          /**< 初始化 LS138 译码器的端口 */
    GPIO_Init(GPIOB, &GPIO_InitStructure);                          /**< 初始化配置连接数码管的端口 */
}

/**
  *  @brief  数码管显示数字
  *  @param	 None
  *  @retval None
  */
void digitron_display(void)
{
    uint8_t i;
    
    for (i = 0; i < 8; i++)
    {
        GPIO_Write(GPIO_DIGITRON, digitron_select[i]);
        GPIO_Write(GPIO_DIGITRON_DATA, digitron_map[i] << 8);
        delay_n_us(500);
        GPIO_Write(GPIO_DIGITRON_DATA, 0x0000);
    }
}

