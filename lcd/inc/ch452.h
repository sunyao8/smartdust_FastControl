#ifndef __CH452_H
#define __CH452_H	 
#include "sys.h"



/* CH451和CH452的常用命令码 */
#define CH452_NOP		0x0000					// 空操作
#define CH452_RESET     0x0201					// 复位
#define CH452_LEVEL		0x0100					// 加载光柱值,需另加7位数据
#define CH452_CLR_BIT	0x0180					// 段位清0,需另加6位数据
#define CH452_SET_BIT	0x01C0					// 段位置1,需另加6位数据
#define CH452_SLEEP		0x0202					// 进入睡眠状态
#define CH452_LEFTMOV   0x0300		            // 设置移动方式-左移
#define CH452_LEFTCYC   0x0301		            // 设置移动方式-左循环
#define CH452_RIGHTMOV  0x0302		            // 设置移动方式-右移
#define CH452_RIGHTCYC  0x0303		            // 设置移动方式-右循环	
#define CH452_SELF_BCD	0x0380					// 自定义BCD码,需另加7位数据
#define CH452_SYSOFF    0x0400					// 关闭显示、关闭键盘
#define CH452_SYSON1    0x0401					// 开启显示
#define CH452_SYSON2    0x0403					// 开启显示、键盘
#define CH452_SYSON2W   0x0423					// 开启显示、键盘, 真正2线接口
#define CH452_NO_BCD    0x0500					// 设置默认显示方式,可另加3位扫描极限
#define CH452_BCD       0x0580					// 设置BCD译码方式,可另加3位扫描极限
#define CH452_TWINKLE   0x0600		            // 设置闪烁控制,需另加8位数据
#define CH452_GET_KEY	0x0700					// 获取按键,返回按键代码
#define CH452_DIG0      0x0800					// 数码管位0显示,需另加8位数据
#define CH452_DIG1      0x0900		            // 数码管位1显示,需另加8位数据
#define CH452_DIG2      0x0a00		            // 数码管位2显示,需另加8位数据
#define CH452_DIG3      0x0b00		            // 数码管位3显示,需另加8位数据
#define CH452_DIG4      0x0c00		            // 数码管位4显示,需另加8位数据
#define CH452_DIG5      0x0d00					// 数码管位5显示,需另加8位数据
#define CH452_DIG6      0x0e00					// 数码管位6显示,需另加8位数据
#define CH452_DIG7      0x0f00		            // 数码管位7显示,需另加8位数据
#define OFF_RED			0xf7
#define OFF_GREEN       0xef
#define OFF_YELLOW      0xe7
#define RED_OFF         0xfe
#define GREEN_OFF       0xfd
#define YELLOW_OFF      0xfc
#define RED_RED         0xf6
#define RED_GREEN       0xe7
#define RED_YELLOW      0xe6
#define GREEN_RED       0xf5
#define GREEN_GREEN     0xed
#define GREEN_YELLOW    0xe5
#define YELLOW_RED      0xf4
#define YELLOW_GREEN    0xec
#define YELLOW_YELLOW   0xe4
#define OFF_OFF         0xff  

// BCD译码方式下的特殊字符
#define		CH452_BCD_SPACE		0x10
#define		CH452_BCD_PLUS		0x11
#define		CH452_BCD_MINUS		0x12
#define		CH452_BCD_EQU		0x13
#define		CH452_BCD_LEFT		0x14
#define		CH452_BCD_RIGHT		0x15
#define		CH452_BCD_UNDER		0x16
#define		CH452_BCD_CH_H		0x17
#define		CH452_BCD_CH_L		0x18
#define		CH452_BCD_CH_P		0x19
#define		CH452_BCD_DOT		0x1A
#define		CH452_BCD_SELF		0x1E
#define		CH452_BCD_TEST		0x88
#define		CH452_BCD_DOT_X		0x80

#define		CH452_KEY_MIN		0x40
#define		CH452_KEY_MAX		0x7F

#define		CH452_I2C_ADDR0		0x40			// CH452的ADDR=0时的地址
#define		CH452_I2C_ADDR1		0x60			// CH452的ADDR=1时的地址,默认值
#define		CH452_I2C_MASK		0x3E			// CH452的2线接口高字节命令掩码


/* 2线接口的位操作,与单片机有关 */
#define		CH452_SCL_SET		GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define		CH452_SCL_CLR		GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define		CH452_SDA_SET		GPIO_SetBits(GPIOB,GPIO_Pin_9)
#define		CH452_SDA_CLR		GPIO_ResetBits(GPIOB,GPIO_Pin_9)

//CH452端口定义
#define LOAD1_SET GPIO_SetBits(GPIOD,GPIO_Pin_0)
#define LOAD2_SET GPIO_SetBits(GPIOD,GPIO_Pin_1) 
#define LOAD3_SET GPIO_SetBits(GPIOD,GPIO_Pin_2)
#define LOAD4_SET GPIO_SetBits(GPIOD,GPIO_Pin_3)
#define LOAD5_SET GPIO_SetBits(GPIOD,GPIO_Pin_4)
#define LOAD6_SET GPIO_SetBits(GPIOD,GPIO_Pin_5)

#define LOAD1_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_0)
#define LOAD2_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_1) 
#define LOAD3_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_2)
#define LOAD4_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_3)
#define LOAD5_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_4)
#define LOAD6_CLR GPIO_ResetBits(GPIOD,GPIO_Pin_5)



void CH452_Init(void);
void CH452_I2c_WrByte(u16,u8);	
void init_light_off(void);
void Light_pad_on(u8 comm_dis,u8 num,u8 status_1,u8 status_2,u8 status_3);
void Light_pad_twinkle(u8 comm_dis ,u8 num,u8 status_1,u8 status_2,u8 status_3,u16 time);
void Light_pad_off(u8 comm_dis ,u8 num,u8 status_1,u8 status_2,u8 status_3);
void Light_pad_on_smartdust( u8 num,u8 on_off);



#endif

















