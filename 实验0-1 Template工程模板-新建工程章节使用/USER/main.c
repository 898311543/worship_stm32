#include "stm32f10x.h"


/************************************************
 ALIENTEK ս��STM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|
  RCC_APB2Periph_GPIOE, ENABLE);	    //ʹ��PB,PE�˿�ʱ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    //LED0-->PB.5 �˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //��ʼ��GPIOB.5
  GPIO_SetBits(GPIOB,GPIO_Pin_5);					//PB.5 �����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	            //LED1-->PE.5�������
  GPIO_Init(GPIOE, &GPIO_InitStructure);	  	       //��ʼ��GPIO
  GPIO_SetBits(GPIOE,GPIO_Pin_5); 			 //PE.5 ����� 	  
  while(1)
	{
	    GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	    GPIO_SetBits(GPIOE,GPIO_Pin_5);
		Delay(3000000);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		Delay(3000000);
	}
 }
