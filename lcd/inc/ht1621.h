#ifndef __HT1621_H
#define __HT1621_H	 
#include "sys.h"

#define BIAS 0x29
#define SYSEN 0x01
#define LCDOFF 0x02
#define LCDON 0x03

//////////////////////////////////////////////////////////////////////////////////	 
//������Ϊ��������ƣ�δ����ɣ����ø����⴫
//ʵ��嶰�����V3.0-1
//LCD����HT1621���� PB3Ϊ595RCLK;PB4Ϊ1621WR;PB5Ϊ1621CS;PB6Ϊ1621DATA��595SCLK	   
//�޸�����:2013/3/13
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �����ж�����ӿƼ����޹�˾ 2013-2023
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//HT1621�˿ڶ���
//#define CS PBout(5) 	// ht1621Ƭѡ
//#define WR PBout(7)	// ht1621дʱ��,74hc595���ݶ�	
//#define DATA PBout(6)	//ht1621���ݣ�74hc595��������ʱ�Ӷ�
//#define RCLK_595 PBout(9)	//74hc595�������������ʱ�Ӷ�
#define CS_1 GPIO_SetBits(GPIOB, GPIO_Pin_5)	// ht1621Ƭѡ
#define WR_1 GPIO_SetBits(GPIOB, GPIO_Pin_7)	
	// ht1621дʱ��,74hc595���ݶ�	
#define DATA_1 GPIO_SetBits(GPIOB, GPIO_Pin_6)	
	//ht1621���ݣ�74hc595��������ʱ�Ӷ�

#define CS_0 GPIO_ResetBits(GPIOB, GPIO_Pin_5)	// ht1621Ƭѡ
#define WR_0 GPIO_ResetBits(GPIOB, GPIO_Pin_7)	
	// ht1621дʱ��,74hc595���ݶ�	
#define DATA_0 GPIO_ResetBits(GPIOB, GPIO_Pin_6)
	//ht1621���ݣ�74hc595��������ʱ�Ӷ�
#define ON 1
#define OFF 0
				    


void HT1621_Init(void);//��ʼ��1621
void SendBit_1621(u8 data,u8 cnt);
void SendDataBit_1621(u8 data,u8 cnt);
void SendCmd(u8 command);
void Write_1621(u8 addr,u8 data);
void WriteAll_1621(u8 addr,u8 *p,u8 cnt);
void Clera_lcd(void);
void Graf_cos_volt_current(u16 PF,u16 volt_para,u32 current_para);
void Graf_cos_volt_current_L1(u16 PF,u16 volt_para,u32 current_para,u8);		 //��ʾ����������ѹ����
void Graf_cos_volt_current_L2(u16 PF,u16 volt_para,u32 current_para,u8);		 //��ʾ����������ѹ����
void Graf_cos_volt_current_L3(u16 PF,u16 volt_para,u32 current_para,u8);		 //��ʾ����������ѹ����

void Graf_powuse_poweunuse_freq(u16 powunuse,u16 powuse,u16 freq);
void Graf_powuse_poweunuse_freq_L1(u16 powunuse,u16 powuse,u16 freq);
void Graf_powuse_poweunuse_freq_L2(u16 powunuse,u16 powuse,u16 freq);
void Graf_powuse_poweunuse_freq_L3(u16 powunuse,u16 powuse,u16 freq);

void Graf_temp_hv_hi(u16 TEMP,u16 HV,u16 HI);
void Graf_temp_hv_hi_L1(u16 TEMP,u16 HV,u16 HI);	   //��ʾ�¶ȵ�ѹг������г��
void Graf_temp_hv_hi_L2(u16 TEMP,u16 HV,u16 HI);	   //��ʾ�¶ȵ�ѹг������г��
void Graf_temp_hv_hi_L3(u16 TEMP,u16 HV,u16 HI);	   //��ʾ�¶ȵ�ѹг������г��

//void Graf_set_para(void);
void Graf_VER(u8 VER);
void Graf_current_value(u32 Current_A,u32 Current_B,u32 Current_C);		 				    
void HT595_Send_Byte(u8 state);

void set_74hc273(int number,int onoff);
void init_74hc273(void);


#endif

















