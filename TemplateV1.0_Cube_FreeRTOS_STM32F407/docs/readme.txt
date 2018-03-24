/**
  * @file  readme.txt
  * @brief 项目工程使用必读，包含项目开发环境说明和项目功能说明等信息
  * @par   date        version    author    remarks
  *        2016-10-06  v1.0       zbt       初次创建
  *
  */ 

  1. 溶解氧项目开发环境说明
    硬件平台：   STM32F407ZGT6
    软件平台：   MDK V5.20 + STM32Cube4.14
    库文件版本： HAL Lib + STemwin5.22
    操作系统：   FreeRTOS8.20 
    
    1.1 STM32F407ZGT6引脚分配说明
		下载方式：SWD -> SWDIO SWCLK
		串口打印：USART1 -> USART_TX（PA9） + USART_RX（PA10）
		液晶触摸：
				SPI1 -> SCK（PA5） + MISO（PA6） + MOSI（PA7）
				CS（PA4） + RESET（PC5）+ INT（PC4）
	
	1.2 项目工程文件架构说明
		Application/MDK_ARM				--------	STM32启动文件		
		Application/User 				--------  	存放应用层程序
		Drivers/CMSIS					--------	M4内核外设接口层系统源文件
		Drivers/STM32F4xx_HAL_Drivers	--------	STM32F4的HAL库源文件
		Drviers/User     				-------- 	存放非STM32片上外设驱动程序
		Drivers/Board   				--------  	存放STM32片上外设相关驱动程序
		Middlewares/FreeRTOS			--------	FreeRTOS相关文件
		Docs							--------  	存放项目工程说明文件
		
  2. 项目功能说明
