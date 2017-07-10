#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������Ϊ��������ƣ�δ����ɣ����ø����⴫
//ʵ��嶰�����V3.0-1
//KEY ���� PA11Ϊ��ʾ�����ð�����PA12Ϊ�ֶ�Ͷ�п���	   
//�޸�����:2013/3/13
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �����ж�����ӿƼ����޹�˾ 2013-2023
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 
typedef struct  
{ 
  s8 size;      //������λǧ��
  u8 work_status;    //����״̬ 1 ΪͶ�빤����0 Ϊû�й���
  u8 id;
}status_comm_node;



#define KEY_right GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)
#define KEY_up GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_14) 
#define KEY_left GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_11)
#define KEY_down GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_12)
#define KEY_set GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_8)
#define KEY_hand GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_10)
#define KEY_conceal GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_9)

#define KEY_1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_9)
#define KEY_2 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_8)
#define KEY_3 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_7)//���뿪�أ������ǲ����ǹ���ģʽ��ֲ�ģʽ




void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��
void key_idset(void);
void ParaSet(void);	
void Graf_display(void);				    
#endif

